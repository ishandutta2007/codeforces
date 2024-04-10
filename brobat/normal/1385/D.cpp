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
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <char> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        auto solve = y_combinator([&](auto self, int start, int end, char c) -> int {
            if(start == end) return v[start] != c;
            int mid = (start + end)/2;
            int c1 = 0;
            for(int i = start; i <= mid; i++) {
                if(v[i] != c) c1++;
            }
            int c2 = 0;
            for(int i = mid + 1; i <= end; i++) {
                if(v[i] != c) c2++;
            }
            return min(c2 + self(start, mid, c + 1), c1 + self(mid + 1, end, c + 1));
        });
        cout << solve(0, n - 1, 'a') << '\n';
    }
    
    return 0;
}