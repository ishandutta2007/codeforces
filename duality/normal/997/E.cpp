#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

int p[120000];
pair<pii,int> queries[120000];
vi S1,S2;
int mm[1 << 18],occ[1 << 18];
LLI sum[1 << 18];
int lazy[1 << 18],lazy2[1 << 18];
int build(int s,int e,int i) {
    if (s == e) {
        mm[i] = 1,occ[i] = 1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    mm[i] = 1,occ[i] = e-s+1;
    return 0;
}
int prop(int s,int e,int i) {
    mm[i] += lazy[i],sum[i] += (LLI) occ[i]*lazy2[i];
    if (s != e) {
        lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
        if (mm[2*i+1]+lazy[2*i+1] == mm[i]) lazy2[2*i+1] += lazy2[i];
        if (mm[2*i+2]+lazy[2*i+2] == mm[i]) lazy2[2*i+2] += lazy2[i];
    }
    lazy[i] = lazy2[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    mm[i] = min(mm[2*i+1],mm[2*i+2]),occ[i] = 0;
    if (mm[i] == mm[2*i+1]) occ[i] += occ[2*i+1];
    if (mm[i] == mm[2*i+2]) occ[i] += occ[2*i+2];
    sum[i] = sum[2*i+1] + sum[2*i+2];
    return 0;
}
LLI query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return sum[i];

    int mid = (s+e) / 2;
    return query(s,mid,qs,qe,2*i+1)+query(mid+1,e,qs,qe,2*i+2);
}
LLI ans[120000];
int main() {
    int i;
    int n,q,l,r;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),p[i]--;
    scanf("%d",&q);
    for (i = 0; i < q; i++) scanf("%d %d",&l,&r),queries[i] = mp(mp(r-1,l-1),i);
    sort(queries,queries+q);

    int j = 0;
    build(0,n-1,0);
    for (i = 0; i < n; i++) {
        while (!S1.empty() && (p[S1.back()] < p[i])) {
            update(0,n-1,(S1.size() == 1) ? 0:S1[S1.size()-2]+1,S1.back(),0,p[i]-p[S1.back()]);
            S1.pop_back();
        }
        while (!S2.empty() && (p[S2.back()] > p[i])) {
            update(0,n-1,(S2.size() == 1) ? 0:S2[S2.size()-2]+1,S2.back(),0,p[S2.back()]-p[i]);
            S2.pop_back();
        }
        S1.pb(i),S2.pb(i);
        update(0,n-1,0,i,0,-1);
        if (mm[0]+lazy[0] == 0) lazy2[0]++,prop(0,n-1,0);
        while ((j < q) && (queries[j].first.first == i)) {
            ans[queries[j].second] = query(0,n-1,queries[j].first.second,i,0);
            j++;
        }
    }
    for (i = 0; i < q; i++) printf("%I64d\n",ans[i]);

    return 0;
}