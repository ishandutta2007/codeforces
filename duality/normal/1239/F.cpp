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

vi adjList[500000];
int parent[500000],visited[500000];
queue<int> Q;
int keep[500000];
int yes[500000];
vi cycle;
int doDFS(int u,int p) {
    int i;
    visited[u] = 1,parent[u] = p;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((adjList[v].size() % 3) != 2) continue;
        if ((v != p) && (visited[v] == 1) && cycle.empty()) {
            int w = u;
            while ((w == p) || !binary_search(adjList[u].begin(),adjList[u].end(),w)) cycle.pb(w),w = parent[w];
            cycle.pb(w);
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((adjList[v].size() % 3) != 2) continue;
        if (visited[v] == 0) doDFS(v,u);
    }
    visited[u] = 2;
    return 0;
}
int doDFS2(int u) {
    int i;
    int r = -1;
    visited[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((adjList[v].size() % 3) != 2) continue;
        if (!visited[v]) {
            parent[v] = u;
            int rr = doDFS2(v);
            if (rr != -1) r = rr;
        }
    }
    if (yes[u]) r = u;
    return r;
}
int main() {
    int i;
    int t,n,m;
    int a,b;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < m; i++) {
            scanf("%d %d",&a,&b);
            a--,b--;
            adjList[a].pb(b);
            adjList[b].pb(a);
        }

        for (i = 0; i < n; i++) sort(adjList[i].begin(),adjList[i].end());
        for (i = 0; i < n; i++) {
            if ((adjList[i].size() % 3) == 0) break;
        }
        if (i < n) {
            if (n == 1) printf("No\n");
            else {
                int p = i;
                printf("Yes\n%d\n",n-1);
                for (i = 0; i < n; i++) {
                    if (i != p) printf("%d ",i+1);
                }
                printf("\n");
            }
        }
        else {
            fill(visited,visited+n,0),cycle.clear();
            for (i = 0; i < n; i++) {
                if (((adjList[i].size() % 3) == 2) && (visited[i] == 0)) {
                    doDFS(i,-1);
                    if (!cycle.empty()) break;
                }
            }
            if (cycle.empty()) {
                int a = -1,b = -1;
                for (i = 0; i < n; i++) {
                    if ((adjList[i].size() % 3) == 1) {
                        if (a == -1) a = i;
                        else b = i;
                    }
                }
                if (b == -1) {
                    int c = 0;
                    fill(visited,visited+n,0),fill(keep,keep+n,0),fill(yes,yes+n,0);
                    keep[a] = 1;
                    for (i = 0; i < adjList[a].size(); i++) yes[adjList[a][i]] = 1;
                    for (i = 0; i < adjList[a].size(); i++) {
                        int v = adjList[a][i];
                        if (!visited[v] && (c < 2)) {
                            yes[v] = 0,b = doDFS2(v);
                            while (b != v) keep[b] = 1,b = parent[b];
                            keep[b] = 1;
                            c++;
                        }
                    }
                    c = 0;
                    for (i = 0; i < n; i++) {
                        if (!keep[i]) c++;
                    }
                    if (c == 0) printf("No\n");
                    else {
                        printf("Yes\n%d\n",c);
                        for (i = 0; i < n; i++) {
                            if (!keep[i]) printf("%d ",i+1);
                        }
                        printf("\n");
                    }
                }
                else {
                    fill(parent,parent+n,-1),fill(keep,keep+n,0);
                    while (!Q.empty()) Q.pop();
                    Q.push(a);
                    while (!Q.empty()) {
                        int u = Q.front();
                        Q.pop();

                        if ((u != a) && ((adjList[u].size() % 3) == 1)) {
                            b = u;
                            break;
                        }
                        for (i = 0; i < adjList[u].size(); i++) {
                            int v = adjList[u][i];
                            if ((v != a) && (parent[v] == -1)) {
                                parent[v] = u;
                                Q.push(v);
                            }
                        }
                    }
                    int d = 0;
                    while (b != a) keep[b] = 1,b = parent[b],d++;
                    keep[b] = 1,d++;
                    if (d == n) printf("No\n");
                    else {
                        printf("Yes\n%d\n",n-d);
                        for (i = 0; i < n; i++) {
                            if (!keep[i]) printf("%d ",i+1);
                        }
                        printf("\n");
                    }
                }
            }
            else {
                fill(keep,keep+n,0);
                for (i = 0; i < cycle.size(); i++) keep[cycle[i]] = 1;
                if (cycle.size() == n) printf("No\n");
                else {
                    printf("Yes\n%d\n",n-cycle.size());
                    for (i = 0; i < n; i++) {
                        if (!keep[i]) printf("%d ",i+1);
                    }
                    printf("\n");
                }
            }
        }

        for (i = 0; i < n; i++) adjList[i].clear();
    }

    return 0;
}