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

int a[200000],b[200000];
struct node { LLI sum,pres,preb,s,b; };
node tree[1 << 19];
node com(node a,node b) {
    node c;
    c.sum = a.sum+b.sum;
    c.pres = min(a.pres,a.sum+b.pres);
    c.preb = max(a.preb,a.sum+b.preb);
    c.s = min(a.s,b.s);
    c.b = max(a.b,b.b);
    return c;
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = (node){b[s],min(b[s],0),max(b[s],0),b[s],b[s]};
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
node query(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return (node){0,0,0,0,0};
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return com(query(s,mid,qs,qe,2*i+1),query(mid+1,e,qs,qe,2*i+2));
}
int main() {
    int i;
    int n,q,l,r;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    for (i = 0; i < n; i++) scanf("%d",&b[i]),b[i] -= a[i];
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&l,&r),l--,r--;
        node x = query(0,n-1,l,r,0);
        if ((x.sum != 0) || (x.pres < 0)) printf("-1\n");
        else printf("%lld\n",max(max(x.b,-x.s),x.preb));
    }

    return 0;
}