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

int a[500001];
int tree[1 << 21],lazy[1 << 21],occ[1 << 21];
int build(int s,int e,int i) {
    if (s == e) {
        occ[i] = 1,tree[i] = 1e6;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    occ[i] = occ[2*i+1] + occ[2*i+2],tree[i] = 1e6;
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
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
    tree[i] = min(tree[2*i+1],tree[2*i+2]),occ[i] = 0;
    if (tree[i] == tree[2*i+1]) occ[i] += occ[2*i+1];
    if (tree[i] == tree[2*i+2]) occ[i] += occ[2*i+2];
    return 0;
}
int update(int l,int r,int num) {
    if (l > r) update(0,1e6+1,r,l-1,0,num);
    return 0;
}
int main() {
    int i;
    int n,q,p,x;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(0,1e6+1,0);
    update(1e6+1,a[0],1);
    for (i = 0; i < n; i++) update(0,1e6+1,a[i],a[i],0,-1e6),update(a[i],a[i+1],1);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&p,&x),p--;
        update((p == 0) ? 1e6:a[p-1],a[p],-1),update(a[p],a[p+1],-1),update(0,1e6+1,a[p],a[p],0,1e6);
        a[p] = x;
        update((p == 0) ? 1e6:a[p-1],a[p],1),update(a[p],a[p+1],1),update(0,1e6+1,a[p],a[p],0,-1e6);
        printf("%d\n",occ[0]);
    }

    return 0;
}