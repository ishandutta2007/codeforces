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

struct node { int m,m2,m12,m23,m123; };
char s[200000];
int d[200000];
node tree[1 << 19];
int lazy[1 << 19];
node com(node a,node b) {
    node c;
    c.m = max(a.m,b.m),c.m2 = max(a.m2,b.m2);
    c.m12 = max(max(a.m12,b.m12),a.m+b.m2);
    c.m23 = max(max(a.m23,b.m23),a.m2+b.m);
    c.m123 = max(max(a.m123,b.m123),max(a.m+b.m23,a.m12+b.m));
    return c;
}
int prop(int s,int e,int i) {
    tree[i].m += lazy[i],tree[i].m2 -= 2*lazy[i];
    tree[i].m12 -= lazy[i],tree[i].m23 -= lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = (node){d[s],-2*d[s],-d[s],-d[s],0};
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
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
    tree[i] = com(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int main() {
    int i;
    int n,q,a,b;
    scanf("%d %d",&n,&q);
    for (i = 0; i < 2*(n-1); i++) {
        scanf(" %c",&s[i]);
        if (i == 0) d[i] = 1;
        else d[i] = d[i-1] + 2*(s[i] == '(') - 1;
    }
    build(0,2*n-3,0);
    printf("%d\n",tree[0].m123);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&a,&b);
        a--,b--;
        if (a > b) swap(a,b);

        if (s[a] == '(') update(0,2*n-3,a,b-1,0,-2);
        else update(0,2*n-3,a,b-1,0,2);
        swap(s[a],s[b]);
        prop(0,2*n-3,0);
        printf("%d\n",tree[0].m123);
    }

    return 0;
}