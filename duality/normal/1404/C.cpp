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

int a[300000];
pair<pii,int> queries[300000];
int ans[300000];
int bit[300001];
pii tree[1 << 20];
int lazy[1 << 20];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = mp(1e9,s),lazy[i] = 0;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = mp(1e9,s),lazy[i] = 0;
    return 0;
}
int prop(int s,int e,int i) {
    tree[i].first += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
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
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int main() {
    int i;
    int n,q,x,y;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),a[i] = i+1-a[i];
    for (i = 0; i < q; i++) scanf("%d %d",&x,&y),queries[i] = mp(mp(x,y),i);
    sort(queries,queries+q);

    int j = q-1,k;
    build(0,n-1,0);
    for (i = n-1; i >= 0; i--) {
        if (a[i] >= 0) update(0,n-1,i,i,0,a[i]-(int) 1e9);
        while (tree[0].first+lazy[0] <= 0) {
            int p = tree[0].second;
            update(0,n-1,p,p,0,1e9);
            for (k = p+1; k <= n; k += k & (-k)) bit[k]++;
            update(0,n-1,p+1,n-1,0,-1);
        }
        while ((j >= 0) && (queries[j].first.first == i)) {
            int a = 0;
            for (k = n-queries[j].first.second; k > 0; k -= k & (-k)) a += bit[k];
            ans[queries[j].second] = a;
            j--;
        }
    }
    for (i = 0; i < q; i++) printf("%d\n",ans[i]);

    return 0;
}