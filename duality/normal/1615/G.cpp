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

// from https://judge.yosupo.jp/submission/51907
struct blossom {
    int n, m;
    vector<int> mate;
    vector<vector<int>> b;
    vector<int> p, d, bl;
    vector<vector<int>> g;
    blossom(int n) : n(n) {
        m = n + n / 2;
        mate.assign(n, -1);
        b.resize(m);
        p.resize(m);
        d.resize(m);
        bl.resize(m);
        g.assign(m, vector<int>(m, -1));
    }
    void add_edge(int u, int v) {
        g[u][v] = u;
        g[v][u] = v;
    }
    void match(int u, int v) {
        g[u][v] = g[v][u] = -1;
        mate[u] = v;
        mate[v] = u;
    }
    vector<int> trace(int x) {
        vector<int> vx;
        while(true) {
            while(bl[x] != x) x = bl[x];
            if(!vx.empty() && vx.back() == x) break;
            vx.push_back(x);
            x = p[x];
        }
        return vx;
    }
    void contract(int c, int x, int y, vector<int> &vx, vector<int> &vy) {
        b[c].clear();
        int r = vx.back();
        while(!vx.empty() && !vy.empty() && vx.back() == vy.back()) {
            r = vx.back();
            vx.pop_back();
            vy.pop_back();
        }
        b[c].push_back(r);
        b[c].insert(b[c].end(), vx.rbegin(), vx.rend());
        b[c].insert(b[c].end(), vy.begin(), vy.end());
        for(int i = 0; i <= c; i++) {
            g[c][i] = g[i][c] = -1;
        }
        for(int z : b[c]) {
            bl[z] = c;
            for(int i = 0; i < c; i++) {
                if(g[z][i] != -1) {
                    g[c][i] = z;
                    g[i][c] = g[i][z];
                }
            }
        }
    }
    vector<int> lift(vector<int> &vx) {
        vector<int> A;
        while(vx.size() >= 2) {
            int z = vx.back(); vx.pop_back();
            if(z < n) {
                A.push_back(z);
                continue;
            }
            int w = vx.back();
            int i = (A.size() % 2 == 0 ? find(b[z].begin(), b[z].end(), g[z][w]) - b[z].begin() : 0);
            int j = (A.size() % 2 == 1 ? find(b[z].begin(), b[z].end(), g[z][A.back()]) - b[z].begin() : 0);
            int k = b[z].size();
            int dif = (A.size() % 2 == 0 ? i % 2 == 1 : j % 2 == 0) ? 1 : k - 1;
            while(i != j) {
                vx.push_back(b[z][i]);
                i = (i + dif) % k;
            }
            vx.push_back(b[z][i]);
        }
        return A;
    }
    int solve() {
        for(int ans = 0; ; ans++) {
            fill(d.begin(), d.end(), 0);
            queue<int> Q;
            for(int i = 0; i < m; i++) bl[i] = i;
            for(int i = 0; i < n; i++) {
                if(mate[i] == -1) {
                    Q.push(i);
                    p[i] = i;
                    d[i] = 1;
                }
            }
            int c = n;
            bool aug = false;
            while(!Q.empty() && !aug) {
                int x = Q.front(); Q.pop();
                if(bl[x] != x) continue;
                for(int y = 0; y < c; y++) {
                    if(bl[y] == y && g[x][y] != -1) {
                        if(d[y] == 0) {
                            p[y] = x;
                            d[y] = 2;
                            p[mate[y]] = y;
                            d[mate[y]] = 1;
                            Q.push(mate[y]);
                        }else if(d[y] == 1) {
                            vector<int> vx = trace(x);
                            vector<int> vy = trace(y);
                            if(vx.back() == vy.back()) {
                                contract(c, x, y, vx, vy);
                                Q.push(c);
                                p[c] = p[b[c][0]];
                                d[c] = 1;
                                c++;
                            }else {
                                aug = true;
                                vx.insert(vx.begin(), y);
                                vy.insert(vy.begin(), x);
                                vector<int> A = lift(vx);
                                vector<int> B = lift(vy);
                                A.insert(A.end(), B.rbegin(), B.rend());
                                for(int i = 0; i < (int) A.size(); i += 2) {
                                    match(A[i], A[i + 1]);
                                    if(i + 2 < (int) A.size()) add_edge(A[i + 1], A[i + 2]);
                                }
                            }
                            break;
                        }
                    }
                }
            }
            if(!aug) return ans;
        }
    }
};

int a[300000];
vi v;
vpii adjList[601];
vector<pair<pii,int> > other;
int visited[601],e = 0,nn = 0,cc = 0;
int com[601];
int ss[601];
int doDFS(int u,int p) {
    if (visited[u]) {
        ss[u] = 1;
        return 0;
    }
    visited[u] = 1,com[u] = cc,nn++;
    for (auto [v,i]: adjList[u]) {
        e++;
        if (v != p) doDFS(v,u);
    }
    return 0;
}
int good[601];
set<pii> matched;
int dir[300000];
int doDFS2(int u,int p) {
    if (visited[u]) return 0;
    visited[u] = 1;
    for (auto [v,i]: adjList[u]) {
        if ((i != -2) && (dir[i] == -1)) dir[i] = v;
        doDFS2(v,u);
    }
    return 0;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]);

    for (i = 0; i < n; i++) {
        if (a[i] > 0) v.pb(i);
    }
    if (v.empty()) {
        for (i = 0; i < n; i++) printf("%d%c",i/2+1,(i == n-1) ? '\n':' ');
        return 0;
    }
    if (v[0] & 1) a[v[0]-1] = a[v[0]];
    if ((n-v.back()-1) & 1) a[v.back()+1] = a[v.back()];
    v.clear();
    for (i = 0; i < n; i++) {
        if (a[i] > 0) v.pb(i);
    }
    for (i = 0; i < v.size()-1; i++) {
        if ((v[i+1]-v[i]) & 1) {
            if (v[i] == v[i+1]-1) {
                if (a[v[i]] == a[v[i+1]]) {
                    adjList[a[v[i]]].pb(mp(a[v[i]],-2));
                    adjList[a[v[i]]].pb(mp(a[v[i]],-2));
                }
            }
            else other.pb(mp(mp(a[v[i]],a[v[i+1]]),i));
        }
        else {
            adjList[a[v[i]]].pb(mp(a[v[i+1]],i));
            adjList[a[v[i+1]]].pb(mp(a[v[i]],i));
        }
    }

    for (i = 1; i <= 600; i++) {
        if (!visited[i]) {
            e = 0,nn = 0,doDFS(i,-1);
            if (e/2 == nn-1) good[cc] = 1;
            cc++;
        }
    }
    blossom B(cc);
    for (auto [e,i]: other) {
        if ((com[e.first] != com[e.second]) && good[com[e.first]] && good[com[e.second]]) B.add_edge(com[e.first],com[e.second]);
    }
    B.solve();
    for (i = 0; i < cc; i++) {
        if (i < B.mate[i]) matched.insert(mp(i,B.mate[i]));
    }
    for (auto [e,p]: other) {
        if ((com[e.first] != com[e.second]) && good[com[e.first]] && good[com[e.second]]) {
            if (matched.count(mp(com[e.first],com[e.second]))) {
                a[v[p]+1] = e.first,a[v[p+1]-1] = e.second;
                adjList[e.first].pb(mp(e.first,-2));
                adjList[e.second].pb(mp(e.second,-2));
                ss[e.first] = ss[e.second] = 1;
                matched.erase(mp(com[e.first],com[e.second]));
            }
            else if (matched.count(mp(com[e.second],com[e.first]))) {
                a[v[p]+1] = e.first,a[v[p+1]-1] = e.second;
                adjList[e.first].pb(mp(e.first,-2));
                adjList[e.second].pb(mp(e.second,-2));
                ss[e.first] = ss[e.second] = 1;
                matched.erase(mp(com[e.second],com[e.first]));
            }
        }
    }

    memset(visited,0,sizeof(visited));
    memset(dir,-1,sizeof(dir));
    for (i = 1; i <= 600; i++) {
        if (!visited[i] && ss[i]) doDFS2(i,-1);
    }
    for (i = 1; i <= 600; i++) {
        if (!visited[i]) doDFS2(i,-1);
    }
    for (i = 0; i < v.size()-1; i++) {
        if (dir[i] != -1) {
            if (a[v[i]] == dir[i]) a[v[i]+1] = a[v[i]];
            else a[v[i+1]-1] = a[v[i+1]];
        }
    }

    set<int> S;
    for (i = 1; i <= n; i++) S.insert(i);
    for (i = 0; i < n; i++) {
        if (a[i] > 0) S.erase(a[i]);
    }
    for (i = 0; i < n-1; i++) {
        if ((a[i] == 0) && (a[i+1] == 0)) a[i] = a[i+1] = *S.begin(),S.erase(S.begin());
    }
    for (i = 0; i < n; i++) printf("%d%c",a[i],(i == n-1) ? '\n':' ');

    return 0;
}