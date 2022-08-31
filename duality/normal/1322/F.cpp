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

int n;
vi adjList[500000];
pii ds[500000],num[500000],temp[500000];
int bad = 0;
pii find(int n) {
    if (ds[n].first != n) {
        pii p = find(ds[n].first);
        ds[n] = mp(p.first,p.second^ds[n].second);
    }
    return ds[n];
}
int merge(int a,int b,int e) {
    pii pa = find(a),pb = find(b);
    e ^= pa.second^pb.second;
    if (pa.first == pb.first) {
        if (e) bad = 1;
        return 0;
    }
    ds[pa.first] = mp(pb.first,e);
    return 0;
}
int parent[500000][19],toUpdate[500000][19],depth[500000];
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1);
    }
    return 0;
}
int ans,dp[500000];
int doDFS2(int u) {
    int i;
    vpii c;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != parent[u][0]) {
            doDFS2(v);
            if (dp[v] == 1e9) {
                dp[u] = 1e9;
                return 0;
            }
            else c.pb(mp(dp[v],v));
        }
    }
    if (!c.empty()) swap(*max_element(c.begin(),c.end()),c[0]);
    for (i = 0; i < c.size(); i++) num[find(c[i].second).first] = mp(0,0);
    for (i = 1; i < c.size(); i++) {
        if (c[i].first+c[0].first > ans) {
            pii p = find(c[i].second);
            if (p.first == find(c[0].second).first) {
                if (p.second != find(c[0].second).second) {
                    dp[u] = 1e9;
                    return 0;
                }
            }
            else {
                if (temp[p.first] == mp(u,p.second^1)) {
                    dp[u] = 1e9;
                    return 0;
                }
                temp[p.first] = mp(u,p.second);
            }
        }
    }
    dp[u] = (u != 0);
    pii pu = find(u);
    if ((temp[pu.first].first == u) && (pu.first != find(c[0].second).first))
        pu = mp(find(c[0].second).first,pu.second^temp[pu.first].second^find(c[0].second).second);
    for (i = 0; i < c.size(); i++) {
        pii p = find(c[i].second);
        if (temp[p.first].first == u) p = mp(find(c[0].second).first,p.second^temp[p.first].second^find(c[0].second).second);
        if (p.first == pu.first) {
            if (!(p.second^pu.second)) dp[u] = max(dp[u],c[i].first+(u != 0));
        }
        if (p.second) num[p.first].second = max(num[p.first].second,c[i].first);
        else num[p.first].first = max(num[p.first].first,c[i].first);
        dp[u] = max(dp[u],min(num[p.first].first,num[p.first].second)+(u != 0));
    }
    if (dp[u] > ans) {
        dp[u] = 1e9;
        return 0;
    }
    return 0;
}
vi adjList2[500000];
int doDFS3(int u,int f) {
    int i;
    vpii c;
    if (u != 0) {
        if (f) adjList2[parent[u][0]].pb(u);
        else adjList2[u].pb(parent[u][0]);
    }
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != parent[u][0]) c.pb(mp(dp[v],v));
    }
    if (!c.empty()) swap(*max_element(c.begin(),c.end()),c[0]);
    for (i = 0; i < c.size(); i++) num[find(c[i].second).first] = mp(0,0);
    for (i = 1; i < c.size(); i++) {
        if (c[i].first+c[0].first > ans) {
            pii p = find(c[i].second);
            if (p.first != find(c[0].second).first) temp[p.first] = mp(u,p.second);
        }
    }
    pii pu = find(u);
    if ((temp[pu.first].first == u) && (pu.first != find(c[0].second).first))
        pu = mp(find(c[0].second).first,pu.second^temp[pu.first].second^find(c[0].second).second);
    for (i = 0; i < c.size(); i++) {
        pii p = find(c[i].second);
        if (temp[p.first].first == u) p = mp(find(c[0].second).first,p.second^temp[p.first].second^find(c[0].second).second);
        if (p.second) num[p.first].second = max(num[p.first].second,c[i].first);
        else num[p.first].first = max(num[p.first].first,c[i].first);
    }
    for (i = 0; i < c.size(); i++) {
        pii p = find(c[i].second);
        if (temp[p.first].first == u) p = mp(find(c[0].second).first,p.second^temp[p.first].second^find(c[0].second).second);
        if (p.first == pu.first) c[i].first = f^p.second^pu.second;
        else if (num[p.first].first < num[p.first].second) c[i].first = f^p.second;
        else c[i].first = f^p.second^1;
    }
    for (i = 0; i < c.size(); i++) doDFS3(c[i].second,c[i].first);
    return 0;
}
queue<int> Q;
int in[500000],c[500000];
int main() {
    int i,j;
    int m,u,v;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    for (i = 0; i < n; i++) ds[i] = mp(i,0);
    doDFS(0,-1,0);
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    int logn = i;
    for (i = 0; i < m; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;

        if (depth[u] < depth[v]) swap(u,v);
        for (j = logn-1; j >= 0; j--) {
            if ((parent[u][j] != -1) && (depth[parent[u][j]] >= depth[v]) && (parent[u][j] != v)) {
                toUpdate[u][j] = 1;
                u = parent[u][j];
            }
        }
        if (parent[u][0] != v) {
            for (j = logn-1; j >= 0; j--) {
                if (parent[u][j] != parent[v][j]) {
                    toUpdate[u][j] = toUpdate[v][j] = 1;
                    u = parent[u][j],v = parent[v][j];
                }
            }
            merge(u,v,1);
        }
    }
    for (i = logn-1; i > 0; i--) {
        for (j = 0; j < n; j++) {
            if (toUpdate[j][i]) toUpdate[j][i-1] = toUpdate[parent[j][i-1]][i-1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (toUpdate[i][0]) merge(i,parent[i][0],0);
    }
    if (bad) {
        printf("-1\n");
        return 0;
    }

    int l = 0,r = n-1;
    while (l < r) {
        int m = (l+r) / 2;
        if ((l == 0) && (r == n-1)) m = n-sqrt(n)-1;

        ans = m;
        fill(temp,temp+n,mp(-1,-1));
        doDFS2(0);
        if (dp[0] < 1e9) r = m;
        else l = m+1;
    }
    ans = l;
    printf("%d\n",l+1);
    fill(temp,temp+n,mp(-1,-1));
    doDFS2(0);
    fill(temp,temp+n,mp(-1,-1));
    doDFS3(0,0);
    for (i = 0; i < n; i++) {
        for (j = 0; j < adjList2[i].size(); j++) in[adjList2[i][j]]++;
    }
    for (i = 0; i < n; i++) {
        if (in[i] == 0) Q.push(i),c[i] = 1;
    }
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (i = 0; i < adjList2[u].size(); i++) {
            int v = adjList2[u][i];
            in[v]--;
            if (in[v] == 0) c[v] = c[u]+1,Q.push(v);
        }
    }
    for (i = 0; i < n; i++) printf("%d ",c[i]);
    printf("\n");

    return 0;
}