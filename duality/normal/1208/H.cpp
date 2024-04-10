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
int s[100000],s2[100000];
int t[100000],x[100000];
int parent[100000][17],depth[100000],disc[100000],order[100000],num = 0;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = num++,order[num-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) adjList2[u].pb(v),doDFS(v,u,d+1);
    }
    return 0;
}
int logn;
int lca(int u,int v) {
    if (depth[u] < depth[v]) swap(u,v);
    int i;
    for (i = logn-1; i >= 0; i--) {
        if ((parent[u][i] != -1) && (depth[parent[u][i]] >= depth[v])) u = parent[u][i];
    }
    if (u == v) return u;
    for (i = logn-1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) u = parent[u][i],v = parent[v][i];
    }
    return parent[u][0];
}
int key[100000],blue[100000][2],child[100000];
vi cc[100000][2];
int main() {
    int i;
    int n,k,q,u,v;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 0; i < n; i++) scanf("%d",&s[i]),s2[i] = s[i];
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&t[i]);
        if (t[i] == 1) scanf("%d",&x[i]),x[i]--;
        else if (t[i] == 2) {
            scanf("%d %d",&x[i],&u),x[i]--;
            if (s2[x[i]] == u) i--,q--;
            else s2[x[i]] = u;
        }
        else scanf("%d",&x[i]);
    }

    int j,b,B = sqrt(q);
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    for (b = 0; b < q; b += B) {
        int e = min(b+B,q);
        vi vv;
        for (i = b; i < e; i++) {
            if (t[i] <= 2) vv.pb(disc[x[i]]);
        }
        sort(vv.begin(),vv.end());
        int l = vv.size();
        for (i = 1; i < l; i++) vv.pb(disc[lca(order[vv[i-1]],order[vv[i]])]);
        sort(vv.begin(),vv.end());
        vv.resize(unique(vv.begin(),vv.end())-vv.begin());
        fill(key,key+n,0);
        for (i = 0; i < vv.size(); i++) key[order[vv[i]]] = 1;
        for (i = n-1; i >= 0; i--) {
            u = order[i];
            cc[u][0].clear(),cc[u][1].clear();
            if (key[u]) {
                child[u] = u,blue[u][0] = -n-1,blue[u][1] = n+1;
                for (j = 0; j < adjList2[u].size(); j++) {
                    v = adjList2[u][j];
                    if (child[v] == -1) cc[u][0].pb(blue[v][0]);
                    else cc[u][1].pb(v);
                }
                sort(cc[u][0].begin(),cc[u][0].end());
            }
            else if (adjList2[u].empty()) child[u] = -1,blue[u][0] = blue[u][1] = s[u] ? n+1:-n-1;
            else {
                child[u] = -1;
                for (j = 0; j < adjList2[u].size(); j++) {
                    v = adjList2[u][j];
                    if (child[v] != -1) child[u] = child[v];
                    cc[u][0].pb(blue[v][0]),cc[u][1].pb(blue[v][1]);
                }
                sort(cc[u][0].begin(),cc[u][0].end(),greater<int>());
                sort(cc[u][1].begin(),cc[u][1].end(),greater<int>());
                blue[u][0] = -cc[u][0].size(),blue[u][1] = -cc[u][1].size();
                for (j = 0; j < cc[u][0].size(); j++) blue[u][0] = max(blue[u][0],min(cc[u][0][j],2*(j+1)-(int) cc[u][0].size()));
                for (j = 0; j < cc[u][1].size(); j++) blue[u][1] = max(blue[u][1],min(cc[u][1][j],2*(j+1)-(int) cc[u][1].size()));
            }
        }
        for (i = b; i < e; i++) {
            if (t[i] == 1) {
                for (j = vv.size()-1; j >= 0; j--) {
                    int u = order[vv[j]];
                    if (!adjList2[u].empty()) {
                        int num = 0;
                        for (l = 0; l < cc[u][1].size(); l++) {
                            int v = cc[u][1][l];
                            if (k <= blue[v][s[child[v]]]) num++;
                        }
                        num += cc[u][0].end()-lower_bound(cc[u][0].begin(),cc[u][0].end(),k);
                        s[u] = (k <= 2*num-(int) adjList2[u].size());
                    }
                    if (u == x[i]) {
                        printf("%d\n",s[u]);
                        break;
                    }
                }
            }
            else if (t[i] == 2) s[x[i]] ^= 1,blue[x[i]][0] = blue[x[i]][1] = s[x[i]] ? n+1:-n-1;
            else k = x[i];
        }
    }

    return 0;
}