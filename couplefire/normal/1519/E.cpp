#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 200005

struct Frac{
    int p, q;
    Frac(){}
    Frac(int _p, int _q): p(_p), q(_q){
        normalize();
    }
    Frac(int x): p(x), q(1){}
    Frac operator + (const Frac &f) const{
        int np = p*f.q+f.p*q, nq = q*f.q;
        return Frac(np, nq);
    }
    bool operator < (const Frac &f) const{
        return p*f.q < f.p*q;
    }
    Frac operator / (const Frac &f) const{
        return Frac(f.q*p, f.p*q);
    }
    void normalize(){
        int gcd = __gcd(p, q);
        p /= gcd, q /= gcd;
    }
};

int n;
vector<array<int, 2>> adj[2*MAXN];
map<Frac, int> mp;
int curid = 0, timer = 0;
int tin[2*MAXN];
bool used[MAXN];
vector<array<int, 2>> ans;

int add(Frac x){
    if(mp.count(x)) return mp[x];
    return mp[x] = curid++;
}

void dfs(int v){
    tin[v] = ++timer;
    for(auto ux : adj[v]){
        int u = ux[0];
        if(!tin[u]) dfs(u);
    }
    vector<array<int, 3>> tmp;
    for(auto ux : adj[v]){
        int u = ux[0];
        if(!used[ux[1]]) tmp.push_back({-tin[u], u, ux[1]});
    }
    sort(tmp.begin(), tmp.end());
    for(int i = 0; i<(int)tmp.size()-1; i+=2){
        ans.push_back({tmp[i][2], tmp[i+1][2]});
        used[tmp[i][2]] = used[tmp[i+1][2]] = 1;
    }
}

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        Frac fx(a, b), fy(c, d);
        int v1 = add(fy/(fx+Frac(1))), v2 = add((fy+Frac(1))/fx);
        adj[v1].push_back({v2, i});
        adj[v2].push_back({v1, i});
    }
    for(int i = 0; i<curid; i++) if(!tin[i]) dfs(i);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x[0]+1 << " " << x[1]+1 << endl;
}