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

const int MOD = 998244353;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    n = (1<<n) - 1;
    string s;
    cin >> s;
    
    map<int, string> m; // node corresponds to which value? m[i] = sorted pre-order of vertex i.
    vector <int> ans(n, 0);

    auto DFS = y_combinator([&](auto self, int i) -> void {
        // children of i --> 2*i + 1, 2*i + 2.
        if(2*i + 2 >= n) {
            ans[i] = 1;
            m[i] = s[i];
            // cout << i << " " << m[i] << '\n';
            return;
        }
        self(2*i + 1);
        self(2*i + 2);
        string x = m[2*i + 1];
        string y = m[2*i + 2];
        if(x == y) {
            ans[i] = ans[2*i + 1] * ans[2*i + 2] % MOD;
            m[i] = s[i] + x + y;
        } else {
            ans[i] = ans[2*i + 1] * ans[2*i + 2] * 2 % MOD;
            if(x < y) m[i] = s[i] + x + y;
            else m[i] = s[i] + y + x;
        }
    });

    DFS(0);

    cout << ans[0];

    // for(int i = 0; i < n; i++) {
    //     cout << i << " " << m[i] << " " << ans[i] << '\n';
    // }
    
    return 0;
}