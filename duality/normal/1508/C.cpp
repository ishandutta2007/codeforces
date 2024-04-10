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
vector<pair<int,pii> > edges;
int diff[200001];
int parent[200000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int merge(int a,int b) {
    a = find(a),b = find(b);
    if (a != b) parent[a] = b;
    return 0;
}
vpii tree[200000];
int parent2[200000][18],depth[200000],depth2[200000];
int doDFS(int u,int p,int d,int d2) {
    int i;
    parent2[u][0] = p,depth[u] = d,depth2[u] = d2;
    for (i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i].first;
        if (v != p) doDFS(v,u,d+1,d2+tree[u][i].second);
    }
    return 0;
}
int main() {
    int i,j;
    int n,m;
    int u,v,w;
    int x = 0;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
        edges.pb(mp(w,mp(u,v)));
        x ^= w;
    }

    sort(edges.begin(),edges.end());
    for (i = 0; i < n; i++) parent[i] = i;
    for (i = 0; i < n; i++) {
        sort(adjList[i].begin(),adjList[i].end());
        for (j = 0; j <= adjList[i].size(); j++) {
            int l = (j == 0) ? 0:adjList[i][j-1]+1;
            int r = (j == adjList[i].size()) ? n-1:adjList[i][j]-1;
            if (l <= r) {
                merge(i,l);
                diff[l]++,diff[r]--;
            }
        }
    }
    for (i = 1; i < n; i++) diff[i] += diff[i-1];
    for (i = 0; i < n-1; i++) {
        if (diff[i] > 0) merge(i,i+1);
    }
    LLI e = (LLI) n*(n-1)/2-m;
    int c = 0;
    for (i = 0; i < n; i++) {
        if (find(i) == i) c++;
    }
    if (e == n-c) {
        for (i = 0; i < n; i++) {
            for (j = 0; j <= adjList[i].size(); j++) {
                int l = (j == 0) ? 0:adjList[i][j-1]+1;
                int r = (j == adjList[i].size()) ? n-1:adjList[i][j]-1;
                int k;
                for (k = l; k <= r; k++) {
                    if (k < i) tree[k].pb(mp(i,1)),tree[i].pb(mp(k,1));
                }
            }
        }

        LLI ans = x;
        for (i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first,v = edges[i].second.second;
            if (find(u) != find(v)) {
                ans += edges[i].first,merge(u,v),edges[i].first = -1;
                tree[u].pb(mp(v,0));
                tree[v].pb(mp(u,0));
            }
        }
        doDFS(0,-1,0,0);
        for (i = 1; (1 << i) < n; i++) {
            for (j = 0; j < n; j++) {
                if (parent2[j][i-1] != -1) parent2[j][i] = parent2[parent2[j][i-1]][i-1];
                else parent2[j][i] = -1;
            }
        }
        int logn = i;
        LLI mm = 0;
        for (i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first,v = edges[i].second.second;
            if (edges[i].first != -1) {
                if (depth[u] < depth[v]) swap(u,v);
                int ou = u,ov = v;
                for (j = logn-1; j >= 0; j--) {
                    if ((parent2[u][j] != -1) && (depth[parent2[u][j]] >= depth[v])) u = parent2[u][j];
                }
                if (u != v) {
                    for (j = logn-1; j >= 0; j--) {
                        if (parent2[u][j] != parent2[v][j]) u = parent2[u][j],v = parent2[v][j];
                    }
                    u = parent2[u][0];
                }
                if (depth2[ou]+depth2[ov]-2*depth2[u] > 0) mm = max(mm,(LLI) x-edges[i].first);
            }
        }
        ans -= mm;
        printf("%I64d\n",ans);
    }
    else {
        LLI ans = 0;
        for (i = 0; i < edges.size(); i++) {
            int u = edges[i].second.first,v = edges[i].second.second;
            if (find(u) != find(v)) ans += edges[i].first,merge(u,v);
        }
        printf("%I64d\n",ans);
    }

    return 0;
}