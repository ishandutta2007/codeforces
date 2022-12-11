    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long double ld;
    typedef long long ll;
    typedef pair<int, int> ii;
    typedef vector<ll> vi;
    typedef vector<vi> vvi;
     
    ll MOD = 1e9+7;
     
     
    ll pot(ll b, ll e) {
        if(e == 0) return 1;
        ll sq = pot(b, e/2);
        if(e&1) return (((sq*sq)%MOD)*b)%MOD;
        return (sq*sq)%MOD;
    }
     
    ll inv(ll x) {
        return pot(x, MOD-2);
    }
     
    int n;
    vvi al;
    vi par;
    vi odd_child;
    vi even_child;
    vi even_y;
    vi even_n;
    vi odd_y;
    vi odd_n;
     
    void dfs1(int v, int p) {
        par[v] = p;
        even_child[v] = 1;
        odd_child[v] = 0;
        for(int i=0; i < (int)al[v].size(); ++i) {
            int u = al[v][i];
            if(u == p) continue;
            else {
                dfs1(u, v);
                even_child[v] *= even_child[u]+odd_child[u];
                if(odd_child[v] == 0) odd_child[v] = 1;
                odd_child[v] *= even_child[u]+odd_child[u];
                even_child[v] %= MOD;
                odd_child[v] %= MOD;
            }
        }
    }
     
    void dfs2(int v, int p) {
        if(p == -1) {
            even_y[v] = odd_child[v];
            even_n[v] = even_child[v];
            odd_n[v] = odd_child[v];
            odd_y[v] = even_child[v];
        }
        else if(odd_child[v] == 0) {
            even_y[v] = ((((odd_y[p]+odd_n[p]))%MOD))%MOD;
            even_n[v] = ((((even_y[p]+even_n[p]))%MOD))%MOD;
            odd_n[v] = ((((odd_y[p]+odd_n[p]))%MOD))%MOD;
            odd_y[v] = ((((even_y[p]+even_n[p]))%MOD))%MOD;
        }
        else {
            even_y[v] = (((odd_child[v]*(odd_y[p]+odd_n[p]))%MOD)*inv(even_child[v]+odd_child[v]))%MOD;
            even_n[v] = (((even_child[v]*(even_y[p]+even_n[p]))%MOD)*inv(even_child[v]+odd_child[v]))%MOD;
            odd_y[v] = (((even_child[v]*(even_y[p]+even_n[p]))%MOD)*inv(even_child[v]+odd_child[v]))%MOD;
            odd_n[v] = (((odd_child[v]*(odd_y[p]+odd_n[p]))%MOD)*inv(even_child[v]+odd_child[v]))%MOD;
            
        }
        
        for(int i=0; i < (int)al[v].size(); ++i) {
            int u = al[v][i];
            if(u == p) continue;
            else {
                dfs2(u, v);
            }
        }
    }
     
     
    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        al = vvi(n, vi());
        vi deg(n, 0);
        for(int i=0; i < n-1; ++i) {
            int a, b;
            cin >> a >> b;
            --a;
            --b;
            al[a].push_back(b);
            al[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        if(n == 1)  {
            cout << 1 << endl;
            return 0;
        }
        else if(n == 2) {
            cout << 4 << endl;
            return 0;
        }
        par = vi(n, 0);
        odd_child = vi(n, 0);
        even_child = vi(n, 0);
        even_y = vi(n, 0);
        even_n = vi(n, 0);
        odd_y = vi(n, 0);
        odd_n = vi(n, 0);
        int root = 0;
        while(deg[root] == 1) root++;
        dfs1(root, -1);
        dfs2(root, -1);
        ll ans = 0;
        for(int i=0; i < n; ++i) {
            ans += even_y[i]+even_n[i];
            ans %= MOD;
        }
        cout << ans << endl;
    }