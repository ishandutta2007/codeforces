#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int K;
    cin >> K;
    vector<vector<LL>> N(K);
    unordered_map<LL, int> n_to_k;
    LL sum = 0;
    vector<LL> sum_k(K, 0);
    for(int k = 0; k < K; ++k) {
        int n;
        cin >> n;
        while(n--) {
            int a;
            cin >> a;
            sum += a;
            sum_k[k] += a;
            N[k].push_back(a);
            n_to_k.emplace(a, k);
        }
    }
    if(sum % K) {
        cout << "No\n";
        return 0;
    }
    vector<LL> delta(K, 0);
    for(int k = 0; k < K; ++k) {
        delta[k] = sum / K - sum_k[k];
    }
    auto find_bitmask = [&](int k, LL v) {
        int m = 0;
        LL v1 = v;
        int k1 = k;
        while(true) {
            v += delta[k1];
            if(n_to_k.count(v)) {
                k1 = n_to_k[v];
                if(m & (1 << k1)) {
                    return -1;
                }
                m |= (1 << k1);
                if(k1 == k) {
                    if(v1 == v) {
                        return m;
                    } else {
                        return -1;
                    }
                }
            } else {
                return -1;
            }
        }
    };
    auto find_cycle = [&](int k, LL v) {
        vector<tuple<int, LL, int>> p;
        int k1 = k;
        while(true) {
            v += delta[k1];
            p.emplace_back(n_to_k[v], v, k1);
            k1 = n_to_k[v];
            if(k1 == k) {
                return p;
            }
        }
    };
    vector<int> dp(1 << K, -1);
    vector<tuple<int, LL>> cycle_start(1 << K);
    for(int k = 0; k < K; ++k) {
        for(auto a : N[k]) {
            int m = find_bitmask(k, a);
            if(m >= 0) {
                dp[m] = 0;
                cycle_start[m] = {k, a};
            }
        }
    }
    for(int m = 1; m < (1 << K); ++m) {
        if(dp[m] == 0) {
            continue;
        }
        for(int s = (m - 1) & m; s; s = (s - 1) & m) {
            if(dp[s] >= 0 and dp[m ^ s] >= 0) {
                dp[m] = s;
                break;
            }
        }
    }
    if(dp[(1 << K) - 1] >= 0) {
        vector<tuple<int, LL>> ans(K);
        function<void(int)> f;
        f = [&](int m) {
            if(dp[m] == 0) {
                auto c = find_cycle(get<0>(cycle_start[m]), get<1>(cycle_start[m]));
                for(auto [i, n, j] : c) {
                    ans[i] = {j, n};
                }
            } else {
                f(dp[m]);
                f(m ^ dp[m]);
            }
        };
        f((1 << K) - 1);
        cout << "Yes\n";
        for(auto [j, n] : ans) {
            cout << n << " " << (j + 1) << "\n";
        }
    } else {
        cout << "No\n";
        return 0;
    }
    
    
    
    
    return 0;
}