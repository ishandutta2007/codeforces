#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int MOD;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int n){
    int x, y;
    int g = gcd(n,MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int n;
vector<array<int, 2>> adj[MAXN];
int siz[MAXN], vis[MAXN];
int pw[MAXN], invpw[MAXN];

void dfs(int v, int p){
    siz[v] = 1;
    for(auto u : adj[v]){
        if(vis[u[0]] || u[0] == p) continue;
        dfs(u[0], v);
        siz[v] += siz[u[0]];
    }
}

int centroid(int v){
    dfs(v, -1);
    int num = siz[v], p = -1;
    do{
        int nxt = -1;
        for(auto u : adj[v]){
            if(vis[u[0]] || u[0] == p) continue;
            if(2*siz[u[0]] > num) nxt = u[0];
        }
        p = v, v = nxt;
    } while(~v);
    return p;
}

map<int, int> mp[MAXN];
map<int, int> tot;
long long totans = 0;

void precalc(int v, int p, int r, int val, int d, int cur){
    inc(cur, mul(pw[d], val));
    mp[r][cur]++; tot[cur]++;
    for(auto u : adj[v]){
        if(vis[u[0]] || u[0] == p) continue;
        precalc(u[0], v, r, u[1], d+1, cur);
    }
}

long long calc(int v, int p, int r, int val, int d, int cur){
    long long ans = 0;
    grow(cur, 10); inc(cur, val);
    int need = MOD-cur; grow(need, invpw[d+1]);
    ans += tot[need]-mp[r][need];
    if(cur == 0) ans++;
    for(auto u : adj[v]){
        if(vis[u[0]] || u[0] == p) continue;
        ans += calc(u[0], v, r, u[1], d+1, cur);
    }
    return ans;
}

void solve(int v){
    int c = centroid(v);
    // cout << c+1 << endl;
    tot = map<int, int>();
    for(auto u : adj[c]){
        if(vis[u[0]]) continue;
        mp[u[0]] = map<int, int>();
    }
    for(auto u : adj[c]){
        if(vis[u[0]]) continue;
        precalc(u[0], c, u[0], u[1], 0, 0);
    }
    long long res = 0;
    for(auto u : adj[c]){
        if(vis[u[0]]) continue;
        res += calc(u[0], c, u[0], u[1], 0, 0);
    }
    res += tot[0];
    totans += res;
    vis[c] = 1;
    for(auto u : adj[c]){
        if(vis[u[0]]) continue;
        solve(u[0]);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> MOD;
    pw[0] = 1;
    for(int i = 1; i<MAXN; i++) pw[i] = mul(pw[i-1], 10);
    for(int i = 0; i<MAXN; i++) invpw[i] = inv(pw[i]);
    for(int i = 0; i<n-1; i++){
        int a, b, w; cin >> a >> b >> w; w%=MOD;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    // tot[0]++;
    solve(0);
    cout << totans << endl;
}