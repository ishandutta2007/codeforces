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
#define MOD 998244353

vi adjList[200000];
LLI a[200000],b[200000],c[200000];
int doDFS(int u) {
    if (adjList[u].size() == 0) {
        a[u] = 0,b[u] = 1,c[u] = 1;
        return 0;
    }

    int i;
    a[u] = b[u] = c[u] = 1;
    vlli temp1,temp2(adjList[u].size());
    LLI p = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        doDFS(v);
        b[u] *= (a[v]+b[v]) % MOD,b[u] %= MOD;
        a[u] *= (a[v]+b[v]+c[v]) % MOD,a[u] %= MOD;
        p *= (a[v]+b[v]) % MOD,p %= MOD;
        temp1.pb(p);
    }
    c[u] = (a[u] - b[u] + MOD) % MOD;
    a[u] = c[u];
    p = 1;
    for (i = adjList[u].size()-1; i >= 0; i--) {
        int v = adjList[u][i];
        p *= (a[v]+b[v]) % MOD,p %= MOD;
        temp2[i] = p;
        LLI ll = (i == 0) ? 1:temp1[i-1];
        LLI rr = (i == adjList[u].size()-1) ? 1:temp2[i+1];
        LLI xx = (ll * rr) % MOD;
        a[u] -= (c[v]*xx) % MOD;
        a[u] += MOD,a[u] %= MOD;
    }
    return 0;
}
int main() {
    int i;
    int n,p;
    scanf("%d",&n);
    for (i = 1; i < n; i++) {
        scanf("%d",&p);
        adjList[p-1].pb(i);
    }
    doDFS(0);
    //for (i = 0; i < n; i++) {
    //    cout << a[i] << " " << b[i] << " " << c[i] << endl;
    //}
    printf("%d\n",(a[0]+b[0]) % MOD);

    return 0;
}