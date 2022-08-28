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
int parent[200000][19],depth[200000],disc[200000],order[400000],nnum = 0;
int sparse[400000][19],logg[400001],logn;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = nnum++,order[nnum-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1),order[nnum++] = u;
    }
    return 0;
}
int lca(int u,int v) {
    u = disc[u],v = disc[v];
    if (u > v) swap(u,v);
    int l = logg[v-u+1];
    u = sparse[u][l],v = sparse[v-(1 << l)+1][l];
    return (depth[u] < depth[v]) ? u:v;
}
int dist(int u,int v) {
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
int midpoint(int u,int v,int d) {
    int i;
    if (depth[u] < depth[v]) swap(u,v);
    for (i = 0; i < logn; i++) {
        if ((d/2) & (1 << i)) u = parent[u][i];
    }
    return u;
}
int visited[200000],size[200000],parent2[200000];
vi adjList2[200000];
int layer[200000],depth2[18][200000],sub[18][200000];
int doDFS2(int u,int p) {
    int i;
    size[u] = 1;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v] && (v != p)) size[u] += doDFS2(v,u);
    }
    return size[u];
}
int centroid(int u) {
    int i,p = -1,r = u;
    doDFS2(u,-1);
    while (1) {
        int h = -1;
        for (i = 0; i < adjList[u].size(); i++) {
            int v = adjList[u][i];
            if (!visited[v] && (v != p) && ((h == -1) || (size[v] > size[h]))) h = v;
        }
        if (((h == -1) || (size[h] <= size[r]/2)) && (size[r]-size[u] <= size[r]/2)) break;
        else p = u,u = h;
    }
    return u;
}
int doDFS3(int u,int p,int d,int l,int s) {
    int i;
    depth2[l][u] = d,sub[l][u] = s;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v] && (v != p)) doDFS3(v,u,d+1,l,s);
    }
    return 0;
}
int decompose(int u,int l) {
    int i,x = 0;
    u = centroid(u);
    visited[u] = 1,layer[u] = l;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (!visited[v]) {
            doDFS3(v,u,1,l,x++);
            v = decompose(v,l+1);
            parent2[v] = u,adjList2[u].pb(v);
        }
    }
    return u;
}

LLI ans = 0;
LLI sum[200000],num[200000];
vlli sum2[200000],num2[200000];
vi vv;
vpii vv2;
vpii a,b;
int cover(pii a,pii b) {
    return max(max(2*a.second,2*b.second),a.second+b.second+dist(a.first,b.first));
}
int findAns(int l,int r) {
    if (l == r) return 0;
    int i,m = (l+r) / 2;
    pii diam = mp(m,m);
    int d = 0,mid = m;
    for (i = m; i >= l; i--) {
        int d1 = dist(diam.first,i),d2 = dist(diam.second,i);
        if (max(d1,d2) > d) {
            if (d1 > d2) diam.second = i,d = d1;
            else diam.first = i,d = d2;
            mid = midpoint(diam.first,diam.second,d);
        }
        a.pb(mp(mid,d/2));
    }
    diam = mp(m+1,m+1),mid = m+1,d = 0;
    for (i = m+1; i <= r; i++) {
        int d1 = dist(diam.first,i),d2 = dist(diam.second,i);
        if (max(d1,d2) > d) {
            if (d1 > d2) diam.second = i,d = d1;
            else diam.first = i,d = d2;
            mid = midpoint(diam.first,diam.second,d);
        }
        b.pb(mp(mid,d/2));
    }
    int s = 0,e = -1;
    LLI x = 0;
    for (i = 0; i < b.size(); i++) x += 2*b[i].second;
    for (i = 0; i < a.size(); i++) {
        while ((e+1 < b.size()) && (cover(a[i],b[e+1]) != 2*b[e+1].second)) {
            int u = b[e+1].first;
            num[u]++,vv.pb(u);
            while (parent2[u] != -1) {
                int p = parent2[u],c = sub[layer[p]][u],d = depth2[layer[p]][b[e+1].first];
                sum[p] += d,num[p]++,sum2[p][c] += d,num2[p][c]++;
                vv.pb(p),vv2.pb(mp(p,c));
                u = p;
            }
            x -= b[e+1].second;
            e++;
        }
        while ((s <= e) && (cover(a[i],b[s]) == 2*a[i].second)) {
            int u = b[s].first;
            num[u]--,vv.pb(u);
            while (parent2[u] != -1) {
                int p = parent2[u],c = sub[layer[p]][u],d = depth2[layer[p]][b[s].first];
                sum[p] -= d,num[p]--,sum2[p][c] -= d,num2[p][c]--;
                vv.pb(p),vv2.pb(mp(p,c));
                u = p;
            }
            x -= b[s].second;
            s++;
        }
        LLI y = 0;
        int u = a[i].first;
        y += sum[u];
        while (parent2[u] != -1) {
            int p = parent2[u],c = sub[layer[p]][u],d = depth2[layer[p]][a[i].first];
            y += sum[p]+d*num[p],y -= sum2[p][c]+d*num2[p][c];
            u = p;
        }
        ans += (LLI) (s+e+1)*a[i].second+x+y;
    }
    for (i = 0; i < vv.size(); i++) sum[vv[i]] = num[vv[i]] = 0;
    for (i = 0; i < vv2.size(); i++) sum2[vv2[i].first][vv2[i].second] = num2[vv2[i].first][vv2[i].second] = 0;
    vv.clear(),vv2.clear(),a.clear(),b.clear();
    findAns(l,m),findAns(m+1,r);
    return 0;
}
int main() {
    int i,j;
    int n,u,v;
    scanf("%d",&n);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(i+n);
        adjList[i+n].pb(u);
        adjList[v].pb(i+n);
        adjList[i+n].pb(v);
    }
    n = 2*n-1;
    doDFS(0,-1,0);
    for (i = 0; i < nnum; i++) sparse[i][0] = order[i];
    for (i = 2; i <= nnum; i++) logg[i] = logg[i/2]+1;
    for (i = 1; (1 << i) <= nnum; i++) {
        for (j = 0; j <= nnum-(1 << i); j++) {
            int a = sparse[j][i-1],b = sparse[j+(1 << (i-1))][i-1];
            sparse[j][i] = (depth[a] < depth[b]) ? a:b;
        }
    }
    for (i = 1; (1 << i) < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
            else parent[j][i] = -1;
        }
    }
    logn = i;
    parent2[decompose(0,0)] = -1;
    for (i = 0; i < n; i++) sum2[i].resize(adjList[i].size()),num2[i].resize(adjList[i].size());
    findAns(0,(n-1)/2);
    printf("%lld\n",ans/2);

    return 0;
}