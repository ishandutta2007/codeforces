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

vi adjList[100000],adjList2[100000];
int visited[100000],parent[100000],disc[100000],low[100000],fin[100000],num = 0,f = 0;
vi back[100000];
int doDFS(int u,int p) {
    int i;
    parent[u] = p,visited[u] = 1,disc[u] = num++,low[u] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (visited[v] == 0) doDFS(v,u),low[u] = (disc[low[v]] < disc[low[u]]) ? low[v]:low[u];
        else if (visited[v] == 1) back[u].pb(v),low[u] = (disc[v] < disc[low[u]]) ? v:low[u];
        else f = 1;
    }
    visited[u] = 2,fin[u] = num;
    return 0;
}
int pre[100001];
vi ans;
int doDFS2(int u) {
    int i;
    ans.pb(u);
    for (i = 0; i < adjList2[u].size(); i++) doDFS2(adjList2[u][i]);
    return 0;
}
int main() {
    int i,j;
    int t,n,m,u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
        }

        int r;
        mt19937 gen;
        uniform_int_distribution<int> dist(0,n-1);
        for (i = 0; i < 100; i++) {
            r = dist(gen);
            f = num = 0,doDFS(r,-1);
            if (!f && (num == n)) break;
            else {
                for (j = 0; j < n; j++) visited[j] = 0,back[j].clear();
            }
        }
        if (i == 100) printf("-1\n");
        else {
            fill(pre,pre+n+1,0);
            for (i = 0; i < n; i++) {
                for (j = 0; j < back[i].size(); j++) pre[disc[i]+1]++,pre[disc[back[i][j]]+1]--;
            }
            for (i = 1; i <= n; i++) pre[i] += pre[i-1];
            for (i = 0; i < n; i++) {
                if (pre[fin[i]]-pre[disc[i]] == 1) adjList2[low[i]].pb(i);
            }
            doDFS2(r);
            if (5*ans.size() < n) printf("-1\n");
            else {
                sort(ans.begin(),ans.end());
                for (i = 0; i < ans.size(); i++) printf("%d ",ans[i]+1);
                printf("\n");
            }
        }

        for (i = 0; i < n; i++) visited[i] = 0,adjList[i].clear(),adjList2[i].clear(),back[i].clear();
        ans.clear();
    }

    return 0;
}