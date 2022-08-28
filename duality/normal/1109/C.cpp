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

int o[100000],t[100000],s[100000],l[100000],r[100000],v[100000];
vi sorted;
int lazy[1 << 18];
LLI tree[1 << 18],pre[1 << 18];
int prop(int s,int e,int i) {
    if (lazy[i] != 2e9) {
        tree[i] = pre[i] = (LLI) (sorted[e+1]-sorted[s])*lazy[i];
        if (s != e) lazy[2*i+1] = lazy[i],lazy[2*i+2] = lazy[i];
        lazy[i] = 2e9;
    }
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] = num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = tree[2*i+1] + tree[2*i+2];
    pre[i] = min(pre[2*i+1],tree[2*i+1]+pre[2*i+2]);
    return 0;
}
LLI sum,ppre;
int query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        ppre = min(ppre,sum+pre[i]),sum += tree[i];
        return 0;
    }

    int mid = (s+e) / 2;
    query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2);
    return 0;
}
map<int,int> M;
int main() {
    int i;
    int q;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&o[i]);
        if (o[i] == 1) scanf("%d %d",&t[i],&s[i]),sorted.pb(t[i]);
        else if (o[i] == 2) scanf("%d",&t[i]);
        else scanf("%d %d %d",&l[i],&r[i],&v[i]),sorted.pb(r[i]);
    }
    sorted.pb(0),sorted.pb(1e9+1);
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());

    M[0] = 0,M[1e9+1] = 0;
    for (i = 0; i < q; i++) {
        if (o[i] == 1) {
            int p = lower_bound(sorted.begin(),sorted.end(),t[i])-sorted.begin();
            auto it = M.lower_bound(t[i]);
            int q = lower_bound(sorted.begin(),sorted.end(),it->first)-sorted.begin();
            update(0,sorted.size()-2,p,q-1,0,s[i]);
            M[t[i]] = s[i];
        }
        else if (o[i] == 2) {
            int p = lower_bound(sorted.begin(),sorted.end(),t[i])-sorted.begin();
            auto it = M.lower_bound(t[i]);
            auto it2 = it;
            it--,it2++;
            int q = lower_bound(sorted.begin(),sorted.end(),it2->first)-sorted.begin();
            update(0,sorted.size()-2,p,q-1,0,it->second);
            M.erase(t[i]);
        }
        else {
            if (v[i] == 0) {
                printf("%d\n",l[i]);
                continue;
            }
            l[i] = M.lower_bound(l[i])->first;
            if (l[i] >= r[i]) {
                printf("-1\n");
                continue;
            }
            int p = lower_bound(sorted.begin(),sorted.end(),l[i])-sorted.begin();
            int q = lower_bound(sorted.begin(),sorted.end(),r[i])-sorted.begin();
            sum = ppre = 0;
            query(0,sorted.size()-2,p,q-1,0);
            if (ppre+v[i] > 0) {
                printf("-1\n");
                continue;
            }
            int s = p,e = q-1;
            while (s < e) {
                int m = (s+e) / 2;
                sum = ppre = 0;
                query(0,sorted.size()-2,p,m,0);
                if (ppre+v[i] <= 0) e = m;
                else s = m+1;
            }
            sum = ppre = 0;
            query(0,sorted.size()-2,p,s-1,0);
            auto it = M.upper_bound(sorted[s]);
            it--;
            printf("%.6lf\n",sorted[s]+(double) (-v[i]-sum)/it->second);
        }
    }

    return 0;
}