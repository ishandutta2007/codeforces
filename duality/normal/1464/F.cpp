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
int parent[200000][19],depth[200000],disc[200000],fin[200000],order[400000],num = 0;
int sparse[400000][19],logg[400001],logn;
int doDFS(int u,int p,int d) {
    int i;
    parent[u][0] = p,depth[u] = d,disc[u] = num++,order[num-1] = u;
    for (i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if (v != p) doDFS(v,u,d+1),order[num++] = u;
    }
    fin[u] = num-1;
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
int isAnc(int u,int v) {
    return (disc[v] >= disc[u]) && (disc[v] <= fin[u]);
}
int onPath(int u,int v,int w) {
    int l = lca(u,v);
    return isAnc(l,w) && (isAnc(w,u) || isAnc(w,v));
}
int moveTo(int u,int v,int d) {
    int i;
    if (d >= depth[u]-depth[lca(u,v)]) d = dist(u,v)-d,u = v;
    if (d < 0) return u;
    for (i = 0; i < logn; i++) {
        if (d & (1 << i)) u = parent[u][i];
    }
    return u;
}

set<pair<pii,int> > S;
struct path { int u,v,d; };
path com(path a,path b) {
    if (a.d == -1) return b;
    else if (b.d == -1) return a;
    else {
        if (a.d < b.d) swap(a,b);
        int i,j;
        vpii vv;
        vv.pb(mp(disc[a.u],a.u));
        vv.pb(mp(disc[a.v],a.v));
        vv.pb(mp(disc[b.u],b.u));
        vv.pb(mp(disc[b.v],b.v));
        sort(vv.begin(),vv.end());
        for (i = 0; i < 3; i++) {
            int x = lca(vv[i].second,vv[i+1].second);
            vv.pb(mp(disc[x],x));
        }
        sort(vv.begin(),vv.end());
        vv.resize(unique(vv.begin(),vv.end())-vv.begin());
        vi vv2;
        for (i = 0; i < vv.size(); i++) {
            if (onPath(a.u,a.v,vv[i].second) && onPath(b.u,b.v,vv[i].second)) vv2.pb(vv[i].second);
        }
        if (vv2.empty()) {
            int u = -1,v = -1;
            for (i = 0; i < vv.size(); i++) {
                if (onPath(a.u,a.v,vv[i].second)) {
                    for (j = 0; j < vv.size(); j++) {
                        if (onPath(b.u,b.v,vv[j].second)) {
                            if ((u == -1) || (dist(vv[i].second,vv[j].second) < dist(u,v))) u = vv[i].second,v = vv[j].second;
                        }
                    }
                }
            }
            if (a.d-b.d <= dist(u,v)) {
                int d = dist(u,v)-(a.d-b.d);
                if (d & 1) {
                    path c;
                    c.u = moveTo(u,v,(d-1)/2),c.v = moveTo(u,v,(d+1)/2);
                    c.d = a.d + (d+1)/2;
                    return c;
                }
                else {
                    path c;
                    c.u = c.v = moveTo(u,v,d/2);
                    c.d = a.d + d/2;
                    return c;
                }
            }
            else {
                path c;
                int d = (a.d-b.d)-dist(u,v);
                c.u = moveTo(u,a.u,d),c.v = moveTo(u,a.v,d);
                c.d = a.d;
                return c;
            }
        }
        else {
            int u = -1,v = -1;
            for (i = 0; i < vv2.size(); i++) {
                for (j = i; j < vv2.size(); j++) {
                    if ((u == -1) || (dist(vv2[i],vv2[j]) > dist(u,v))) u = vv2[i],v = vv2[j];
                }
            }
            if (dist(a.u,u) > dist(a.u,v)) swap(u,v);
            path c;
            c.u = moveTo(u,a.u,a.d-b.d),c.v = moveTo(v,a.v,a.d-b.d);
            c.d = a.d;
            return c;
        }
    }
}
vector<path> tree[1 << 19];
int qq[200000];
int update(int s,int e,int as,int ae,int i,path p) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        tree[i].pb(p);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,p),update(mid+1,e,as,ae,2*i+2,p);
    return 0;
}
int solve(int s,int e,int i,path p) {
    int j;
    for (j = 0; j < tree[i].size(); j++) p = com(p,tree[i][j]);
    if (s == e) {
        if (qq[s] != -1) printf((qq[s] >= p.d) ? "Yes\n":"No\n");
        return 0;
    }

    int mid = (s+e) / 2;
    solve(s,mid,2*i+1,p),solve(mid+1,e,2*i+2,p);
    return 0;
}
int main() {
    int i,j;
    int n,q,t,u,v,d;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n-1; i++) {
        scanf("%d %d",&u,&v);
        u--,v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    doDFS(0,-1,0);
    for (i = 0; i < num; i++) sparse[i][0] = order[i];
    for (i = 2; i <= num; i++) logg[i] = logg[i/2]+1;
    for (i = 1; (1 << i) <= num; i++) {
        for (j = 0; j <= num-(1 << i); j++) {
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
    fill(qq,qq+q,-1);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&u,&v);
            u--,v--;
            if (u > v) swap(u,v);
            S.insert(mp(mp(u,v),i));
        }
        else if (t == 2) {
            scanf("%d %d",&u,&v);
            u--,v--;
            if (u > v) swap(u,v);
            auto it = S.lower_bound(mp(mp(u,v),0));
            update(0,q-1,it->second,i-1,0,(path){u,v,0});
            S.erase(it);
        }
        else scanf("%d",&d),qq[i] = d;
    }
    while (!S.empty()) {
        u = S.begin()->first.first,v = S.begin()->first.second;
        update(0,q-1,S.begin()->second,q-1,0,(path){u,v,0});
        S.erase(S.begin());
    }
    solve(0,q-1,0,(path){-1,-1,-1});

    return 0;
}