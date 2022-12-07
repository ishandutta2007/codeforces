#include <bits/stdc++.h>
using namespace std;
#define int long long

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 201;

    vector<vector<int>> f(N + 1);
    
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            f[j].push_back(i);
        }
    }
    for(int i = 1; i <= N; i++) {
        sort(f[i].begin(), f[i].end());
    }
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s; cin >> s;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        vector <int> a;
        vector <string> c;
        vector <int> vis(n, false);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            string temp;
            // int cnt = 1;
            int j = v[i];
            temp += s[i];
            vis[i] = true;
            while(j != i) {
                // cnt++;
                vis[j] = true;
                temp += s[j];
                j = v[j];
            }
            // a.push_back(cnt);
            c.push_back(temp);
        }

        // for(auto i : c) cout << i << " ";
        // cout << '\n';

        for(auto s : c) {
            int t = s.length();
            for(auto i : f[t]) {
                // assuming length i.
                string x;
                for(int j = 0; j < t; j++) {
                    x += s[j % i];
                }
                if(x == s) {
                    // cout << x << '\n';
                    a.push_back(i);
                    break;
                }
                // cout << "F";
            }
        }

        int ans = a[0];
        for(int i = 1; i < (int)a.size(); i++) {
            ans = ans / __gcd(ans, a[i]);
            ans = ans * a[i];
        }
        cout << ans << '\n';
    }
    
    return 0;
}