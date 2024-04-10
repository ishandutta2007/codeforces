#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, a, b, siz[N], mn[N], mx[N], comb[N][N];
vector<int> todo, stuff[N];
vector<vector<int>> comps;
bitset<N> vis, adj[N];

void dfs1(int v){
    vis[v] = 1;
    for(int u = 0; u<n; ++u)
        if(adj[v][u] && !vis[u]) dfs1(u);
    todo.push_back(v);
}

void dfs2(int v){
    vis[v] = 1; comps.back().push_back(v);
    for(int u = 0; u<n; ++u)
        if(adj[u][v] && !vis[u]) dfs2(u);
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 0; i<n; ++i){
        string s; cin >> s;
        for(int j = 0; j<n; ++j)
            adj[i][j] = s[j]-'0';
    }
    for(int i = 0; i<n; ++i){
        cin >> siz[i];
        stuff[i].resize(siz[i]);
        string s; cin >> s;
        for(int j = 0; j<siz[i]; ++j)
            stuff[i][j] = s[j]-'0', mn[i] += stuff[i][j];
        mx[i] = mn[i];
    }
    comb[0][0] = 1;
    for(int i = 1; i<=n; ++i){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j<i; ++j)
            comb[i][j] = add(comb[i-1][j-1], comb[i-1][j]);
    }
    for(int i = 0; i<n; ++i)
        if(!vis[i]) dfs1(i);
    reverse(todo.begin(), todo.end());
    vis.reset();
    for(auto v : todo)
        if(!vis[v]) comps.push_back({}), dfs2(v);
    int free = 0; vector<int> fr;
    for(auto& c : comps){
        int gcd = siz[c[0]];
        for(int x : c)
            gcd = __gcd(gcd, siz[x]);
        free = __gcd(free, gcd);
        vector<int> bruh;
        for(int x : fr)
            bruh.push_back(x%free);
        sort(bruh.begin(), bruh.end());
        bruh.erase(unique(bruh.begin(), bruh.end()), bruh.end());
        swap(fr, bruh);
        vector<int> tmp;
        for(int x : c)
            for(int i = 0; i<siz[x]; ++i)
                if(stuff[x][i]) tmp.push_back(i%gcd);
        for(auto x : fr)
            for(int i = x; i<gcd; i+=free)
                tmp.push_back(i);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for(int r : tmp) for(int x : c)
            for(int i = r; i<siz[x]; i+=gcd)
                if(!stuff[x][i]) ++mx[x];
        for(auto x : tmp) fr.push_back(x%free);
        sort(fr.begin(), fr.end());
        fr.erase(unique(fr.begin(), fr.end()), fr.end());
    }
    vector<int> id(n); int ans = 0;
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int x, int y){return mx[x]>mx[y];});
    for(int i = 0; i<n; ++i){
        int k = mx[id[i]], x = 0, y = 0;
        for(int j = 0; j<=i; ++j)
            if(mn[id[j]]<=k) ++x;
        for(int j = i+1; j<n; ++j)
            if(mn[id[j]]<=k) ++y;
        for(int j = 1; j<=b; ++j){
            if(j>x) continue;
            if(b-j>i+1-x) continue;
            if(x-j+y<n-a) continue;
            inc(ans, mul(comb[x-1][j-1], comb[i+1-x][b-j]));
        }
    }
    cout << ans << '\n';
}