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
int parent[100000],height[100000],depth[100000],height2[100000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u] = p,height[u] = 0,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) height[u] = max(height[u],doDFS(v,u,d+1)+1);
    }
    return height[u];
}
int doDFS2(int u,int p,int h) {
    int i;
    height2[u] = h;
    int m1 = 0,m2 = 0,mi = -1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (height[v]+1 >= m1) m2 = m1,m1 = height[v]+1,mi = v;
            else if (height[v]+1 >= m2) m2 = height[v]+1;
        }
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) {
            if (v == mi) doDFS2(v,u,max(h,m2)+1);
            else doDFS2(v,u,max(h,m1)+1);
        }
    }
    return 0;
}
vi path;
int good[100000],onPath[100000];
int parent2[100000],depth2[100000],pathPos[100000];
int doDFS3(int u,int p,int d) {
    int i;
    parent2[u] = p,depth2[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if ((v != p) && (onPath[v] == -1)) pathPos[v] = pathPos[u],good[u] |= doDFS3(v,u,d+1);
    }
    return good[u];
}
int poss[100000][2];
queue<pii> Q;
int main() {
    int i;
    int t,n,a,b;
    int u,v;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d %d",&n,&a,&b);
        a--,b--;
        for (i = 0; i < n-1; i++) {
            scanf("%d %d",&u,&v);
            u--,v--;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }

        int j;
        doDFS(a,-1,0);
        int dd = depth[b];
        doDFS2(a,-1,0);
        for (i = 0; i < n; i++) {
            vi vv;
            for (j = 0; j < adjList[i].size(); j++) {
                int v = adjList[i][j];
                if (v != parent[i]) vv.pb(height[v]+1);
                else vv.pb(height2[i]);
            }
            sort(vv.begin(),vv.end(),greater<int>());
            if ((vv.size() >= 3) && (vv[2] >= dd)) good[i] = 1;
            else good[i] = 0;
        }
        int u = b,f = 0;
        fill(onPath,onPath+n,-1);
        while (u != -1) {
            path.pb(u),onPath[u] = path.size()-1,pathPos[u] = onPath[u];
            u = parent[u];
        }
        for (i = 0; i < n; i++) {
            if (onPath[i] != -1) doDFS3(i,-1,0);
        }
        for (i = 0; i < n; i++) poss[i][0] = poss[i][1] = 0;
        poss[a][0] = 1;
        Q.push(mp(a,0));
        while (!Q.empty()) {
            int u = Q.front().first;
            int x = Q.front().second;
            Q.pop();

            if (good[u]) {
                f = 1;
                break;
            }
            if (x == 0) {
                printVar(depth2[u]);
                printVar(dd);
                printVar(pathPos[u]);
                if ((depth2[u] <= dd) && (pathPos[u]-(dd-depth2[u]) >= 0)) {
                    int v = path[pathPos[u]-(dd-depth2[u])];
                    if (!poss[v][1]) poss[v][1] = 1,Q.push(mp(v,1));
                }
            }
            else {
                if ((depth2[u] <= dd) && (pathPos[u]+(dd-depth2[u]) < path.size())) {
                    int v = path[pathPos[u]+(dd-depth2[u])];
                    if (!poss[v][0]) poss[v][0] = 1,Q.push(mp(v,0));
                }
            }
            for (i = 0; i < adjList[u].size(); i++) {
                int v = adjList[u][i];
                if (v == parent2[u]) continue;
                if ((onPath[u] != -1) && (onPath[v] != -1) && (x != ((onPath[u] > onPath[v]) ? 1:0))) continue;
                if (!poss[v][x]) poss[v][x] = 1,Q.push(mp(v,x));
            }
        }
        while (!Q.empty()) Q.pop();
        printf(f ? "YES\n":"NO\n");

        for (i = 0; i < n; i++) adjList[i].clear();
        path.clear();
    }

    return 0;
}