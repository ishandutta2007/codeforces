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

vi adjList[200000];
vi vv;
int doDFS(int u,int p) {
    vi x;
    for (int v: adjList[u]) {
        if (v != p) x.pb(doDFS(v,u));
    }
    sort(x.begin(),x.end());
    if (x.empty()) return 1;
    else {
        int c = x.back()+1;
        x.pop_back();
        for (int y: x) vv.pb(y);
        return c;
    }
}
int main() {
    int i;
    int n,k,u,v;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int sum = 0;
    LLI ans = -1e18;
    vv.pb(doDFS(0,-1));
    sort(vv.begin(),vv.end(),greater<int>());
    for (i = 1; i <= k; i++) {
        if (i-1 < vv.size()) sum += vv[i-1];
        int sum2 = sum-i;
        if (i+sum2 <= n/2) ans = max(ans,-((LLI) (n-2*i)*(n-2*i)/4));
        else ans = max(ans,(LLI) sum2*(2*i-n+sum2));
    }
    printf("%lld\n",ans);

    return 0;
}