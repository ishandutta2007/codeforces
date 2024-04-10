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
#define MOD 1000000007

LLI c[500000];
int power[1000001];
vector<pair<LLI,pii> > edges;
int parent[500000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
vi vv;
int main() {
    int i;
    int n,m,k,u,v;
    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < n; i++) scanf("%I64d",&c[i]);
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        edges.pb(mp(c[u]^c[v],mp(u,v)));
    }
    sort(edges.begin(),edges.end());

    int j,com = n;
    power[0] = 1;
    for (i = 1; i <= 1e6; i++) power[i] = (2*power[i-1]) % MOD;
    LLI ans = power[n+k];
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < edges.size(); i++) {
        if ((i > 0) && (edges[i].first != edges[i-1].first)) {
            ans -= power[n],ans += power[com];
            for (j = 0; j < vv.size(); j++) parent[vv[j]] = vv[j];
            com = n,vv.clear();
        }
        int u = find(edges[i].second.first),v = find(edges[i].second.second);
        if (u != v) parent[u] = v,com--,vv.pb(u),vv.pb(v);
    }
    ans -= power[n],ans += power[com];
    ans %= MOD;
    if (ans < 0) ans += MOD;
    printf("%I64d\n",ans);

    return 0;
}