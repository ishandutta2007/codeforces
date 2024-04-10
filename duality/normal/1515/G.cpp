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

vpii adjList[200000];
int disc[200000],low[200000],inStack[200000],num = 0;
LLI dist[200000];
int com[200000],c = 0;
vi S;
int doDFS(int u) {
    int i;
    disc[u] = low[u] = num++;
    S.pb(u),inStack[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        if (disc[v] == -1) dist[v] = dist[u]+adjList[u][i].second,doDFS(v),low[u] = min(low[u],low[v]);
        else if (inStack[v]) low[u] = min(low[u],disc[v]);
    }
    if (disc[u] == low[u]) {
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            com[v] = c;
            if (u == v) break;
        }
        c++;
    }
    return 0;
}
LLI gcd(LLI a,LLI b) {
    LLI t;
    while (a > 0) t = b % a,b = a,a = t;
    return b;
}
LLI g[200000];
int main() {
    int i;
    int n,m,q;
    int a,b,l;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&a,&b,&l);
        a--,b--;
        adjList[a].pb(mp(b,l));
    }

    int j;
    for (i = 0; i < n; i++) disc[i] = low[i] = -1;
    for (i = 0; i < n; i++) {
        if (disc[i] == -1) doDFS(i);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int v = adjList[i][j].first;
            if (com[i] == com[v]) g[com[i]] = gcd(g[com[i]],abs(dist[v]-(dist[i]+adjList[i][j].second)));
        }
    }

    int v,s,t;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&v,&s,&t);
        v--;
        if ((s % gcd(t,g[com[v]])) == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}