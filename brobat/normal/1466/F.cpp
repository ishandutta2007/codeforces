#include <bits/stdc++.h>
using namespace std;
#define int long long

int parent[500100];

const int MOD = (int)1E9 + 7;

int find(int x) {
    if(x==parent[x]) return x;
    return parent[x] = find(parent[x]);
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void unite(int a, int b) {
    int c = find(a);
    int d = find(b);
    if(d!=c) parent[d] = c;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= m; i++) {
        parent[i] = i;
    }
    vector <int> ans;
    for(int i = 0; i < n; i++) {
        int k, u, v;
        cin >> k;
        if(k == 1) {
            cin >> u;
            if(find(u) != find(0)) {
                unite(0, u);
                ans.push_back(i + 1);
            }
        } else {
            cin >> u >> v;
            if(find(u) != find(v)) {
                unite(v, u);
                ans.push_back(i + 1);
            }
        }
    }
    map<int, int> p;
    for(int i = 0; i <= m; i++) {
        p[find(i)]++;    
    }
    int x = 1;
    for(auto i : p) {
        x = (x * binpow(2, i.second - 1)) % MOD;
    }
    cout << x << " " << (int)ans.size() << '\n';
    for(auto i : ans) cout << i << " ";
    
    return 0;
}