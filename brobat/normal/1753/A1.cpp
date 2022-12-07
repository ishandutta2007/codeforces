#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        int x = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            x += v[i];
        }
        if(abs(x) % 2 == 1) {
            cout << -1 << '\n';
            continue;
        }
        if(x == 0) {
            cout << n << '\n';
            for(int i = 0; i < n; i++) cout << i + 1 << ' ' << i + 1 << '\n';
            continue;
        }
        if(x < 0) {
            for(int i = 0; i < n; i++) v[i] *= -1;
            x *= -1;
        }
        int i = 0;
        int done = 0;
        vector<pair<int, int>> p;
        while(i < n) {
            if(done == x) {
                p.push_back({i, i});
                i++;
                continue;
            }
            if(v[i + 1] == 1) {
                p.push_back({i, i + 1});
                i += 2;
                done += 2;
                continue;
            }
            p.push_back({i, i});
            i++;
        }
        assert(done == x);
        cout << (int)p.size() << '\n';
        for(auto i : p) cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    
    return 0;
}