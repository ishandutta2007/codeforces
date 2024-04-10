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

int a[1000000],p;
vlli tree[1 << 21];
LLI b[1 << 21];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i].pb(p-a[s]);
        b[i] = a[s];
        return 0;
    }

    int j,k = 0,mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    b[i] = b[2*i+1] + b[2*i+2],tree[i].reserve(e-s+1);
    for (j = 0; j < tree[2*i+1].size(); j++) {
        LLI c = tree[2*i+1][j]+b[2*i+1]-(LLI) p*j;
        while ((k < tree[2*i+2].size()) && (tree[2*i+2][k] < c)) {
            tree[i].pb(tree[2*i+2][k]-b[2*i+1]+(LLI) p*j);
            k++;
        }
        if (tree[i].empty() || (tree[i].back() <= tree[2*i+1][j]-p)) tree[i].pb(tree[2*i+1][j]);
        else k--;
    }
    while (k < tree[2*i+2].size()) {
        tree[i].pb(tree[2*i+2][k]-b[2*i+1]+(LLI) p*j);
        k++;
    }
    return 0;
}
LLI query(int s,int e,int qs,int qe,int i,LLI r) {
    if ((s > qe) || (e < qs)) return r;
    else if ((s >= qs) && (e <= qe)) {
        r += b[i]-(LLI) p*(upper_bound(tree[i].begin(),tree[i].end(),r)-tree[i].begin());
        return r;
    }

    int mid = (s+e) / 2;
    return query(mid+1,e,qs,qe,2*i+2,query(s,mid,qs,qe,2*i+1,r));
}
int main() {
    int i;
    int n,m,l,r;
    scanf("%d %d %d",&n,&m,&p);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);
    build(0,n-1,0);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&l,&r);
        l--,r--;
        printf("%I64d\n",query(0,n-1,l,r,0,0));
    }

    return 0;
}