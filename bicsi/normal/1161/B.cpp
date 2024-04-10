#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937_64 mt_rand(seed);
    std::uniform_int_distribution<unsigned long long> dis;

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    vector<long long> has(2 * n, 0);
    map<int, long long> has_map;
    auto Get = [&](int x) {
        if (has_map.count(x)) return has_map[x];
        has_map[x] = dis(mt_rand);
        return has_map[x];
    };

    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        if (a > b) swap(a, b);
        int len = min(b - a, n - b + a);
        
        // cerr << a << " " << b << " " << len << endl;
        if (len * 2 == n) {
            has[a] += Get(len);
            has[b] += Get(len);
        } else {
            if (b == a + len) {
                has[a] += Get(len);
                has[b] += Get(-len);    
            } else {
                has[a] += Get(-len);
                has[b] += Get(len);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        has[i + n] = has[i];

    
    vector<int> pi(2 * n + 1, -1);
  
    for (int i = 0; i < 2 * n; ++i) {
        int j = pi[i];
        if (j == n) {
            cout << "YES\n";
            return 0;
        }
        while (j != -1 && has[j] != has[i]) j = pi[j];
        pi[i + 1] = j + 1;
    }

    cout << "NO\n";
    return 0;  
}