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

vi adjList[100000];
int disc[100000],low[100000],inStack[100000],num = 0;
vi com[100000],adjList2[100000];
int c[100000],in[100000],scc = 0;
vi S;
int doDFS(int u) {
    int i;
    disc[u] = low[u] = num++;
    S.pb(u),inStack[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (disc[v] == -1) doDFS(v),low[u] = min(low[u],low[v]);
        else if (inStack[v]) low[u] = min(low[u],disc[v]);
    }
    if (disc[u] == low[u]) {
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            com[scc].pb(v),c[v] = scc;
            if (u == v) break;
        }
        scc++;
    }
    return 0;
}
queue<int> Q;
int main() {
    int i;
    int n,m,u,v;
    cin >> n >> m;
    for (i = 0; i < m; i++) cin >> u >> v,adjList[u-1].pb(v-1);

    int j;
    for (i = 0; i < n; i++) disc[i] = low[i] = -1;
    for (i = 0; i < n; i++) {
        if (disc[i] == -1) doDFS(i);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            v = adjList[i][j];
            if (c[i] != c[v]) adjList2[c[i]].pb(c[v]);
        }
    }
    for (i = 0; i < scc; i++) {
        sort(adjList2[i].begin(),adjList2[i].end());
        adjList2[i].resize(unique(adjList2[i].begin(),adjList2[i].end())-adjList2[i].begin());
        for (j = 0; j < adjList2[i].size(); j++) in[adjList2[i][j]]++;
    }
    for (i = 0; i < scc; i++) {
        if (in[i] == 0) Q.push(i);
    }

    int p = Q.front();
    Q.pop();
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        while (!com[p].empty() && !com[u].empty()) {
            int r;
            cout << "? " << com[p].back()+1 << " " << com[u].back()+1 << endl;
            cin >> r;
            if (r) com[u].pop_back();
            else com[p].pop_back();
        }
        if (com[p].empty()) swap(p,u);
        for (i = 0; i < adjList2[u].size(); i++) {
            v = adjList2[u][i],in[v]--;
            if (in[v] == 0) Q.push(v);
        }
    }
    cout << "! " << com[p].back()+1 << endl;

    return 0;
}