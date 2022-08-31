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

int a[300000],b[300000];
int tree[1 << 21],lazy[1 << 21];
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return tree[i];
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return tree[i];
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = min(tree[2*i+1],tree[2*i+2]);
    return tree[i];
}
int query(int s,int e,int i) {
    prop(s,e,i);
    if (s == e) return s;
    int mid = (s+e) / 2;
    prop(mid+1,e,2*i+2);
    if (tree[2*i+2] < 0) return query(mid+1,e,2*i+2);
    else return query(s,mid,2*i+1);
}
int main() {
    int i;
    int n,m,q;
    int t,j,x;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < m; i++) scanf("%d",&b[i]);
    for (i = 0; i < n; i++) update(0,1000000,1,a[i],0,-1);
    for (i = 0; i < m; i++) update(0,1000000,1,b[i],0,1);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&t,&j,&x),j--;
        if (t == 1) {
            update(0,1000000,1,a[j],0,1);
            a[j] = x;
            update(0,1000000,1,a[j],0,-1);
        }
        else {
            update(0,1000000,1,b[j],0,-1);
            b[j] = x;
            update(0,1000000,1,b[j],0,1);
        }
        int ans = query(0,1000000,0);
        if (ans == 0) printf("-1\n");
        else printf("%d\n",ans);
    }

    return 0;
}