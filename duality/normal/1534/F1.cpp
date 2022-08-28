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

char *grid[400000];
int *pos[400000];
vpii vv;
int a[400000];
int need[400000];
vi adjList[400000],adjList2[400000];
int disc[400000],low[400000],inStack[400000],num = 0;
int com[400000],L[400000],R[400000],c = 0;
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
        L[c] = R[c] = vv[u].second;
        while (1) {
            int v = S.back();
            S.pop_back(),inStack[v] = 0;
            com[v] = c;
            L[c] = min(L[c],vv[v].second),R[c] = max(R[c],vv[v].second);
            if (u == v) break;
        }
        c++;
    }
    return 0;
}
int visited[400000];
int doDFS2(int u) {
    if (visited[u]) return 0;
    int i;
    visited[u] = 1;
    for (i = 0; i < adjList2[u].size(); i++) {
        int v = adjList2[u][i];
        doDFS2(v);
        L[u] = min(L[u],L[v]);
        R[u] = max(R[u],R[v]);
    }
    return 0;
}
vpii in;
bool comp(pii a,pii b) {
    return a.second < b.second;
}
int main() {
    int i,j;
    int n,m;
    int x = 0;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) {
        grid[i] = new char[m];
        pos[i] = new int[m];
        for (j = 0; j < m; j++) {
            scanf(" %c",&grid[i][j]);
            if (grid[i][j] == '#') pos[i][j] = x++,vv.pb(mp(i,j));
            else pos[i][j] = -1;
        }
    }
    for (i = 0; i < m; i++) scanf("%d",&a[i]);

    vi v;
    for (i = 0; i < m; i++) {
        if (a[i] != 0) {
            int c = 0;
            for (j = n-1; j >= 0; j--) {
                if (grid[j][i] == '#') c++;
                if (c == a[i]) break;
            }
            if (j < 0) {
                printf("-1\n");
                return 0;
            }
            else v.pb(pos[j][i]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                int k;
                for (k = i; k < n; k++) {
                    if ((j > 0) && (grid[k][j-1] == '#')) adjList[pos[k][j-1]].pb(pos[i][j]);
                    if ((j < m-1) && (grid[k][j+1] == '#')) adjList[pos[k][j+1]].pb(pos[i][j]);
                    if ((k > i) && (grid[k][j] == '#')) {
                        adjList[pos[k][j]].pb(pos[i][j]);
                        if (k == i+1) adjList[pos[i][j]].pb(pos[k][j]);
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < x; i++) disc[i] = low[i] = -1;
    for (i = 0; i < x; i++) {
        if (disc[i] == -1) doDFS(i);
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < adjList[i].size(); j++) {
            int vv = adjList[i][j];
            if (com[i] != com[vv]) adjList2[com[i]].pb(com[vv]);
        }
    }
    for (i = 0; i < v.size(); i++) {
        doDFS2(com[v[i]]);
        in.pb(mp(L[com[v[i]]],R[com[v[i]]]));
    }
    int ans = 0,l = -1;
    sort(in.begin(),in.end(),comp);
    for (i = 0; i < in.size(); i++) {
        if (in[i].first > l) ans++,l = in[i].second;
    }
    printf("%d\n",ans);

    return 0;
}