#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

constexpr int MOD = 1000000007;


struct cow_t {
    int l, r;
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    for(int& s : S) {
        cin >> s;
    }
    vector<vector<cow_t>> C(N + 1);
    for(int n = 0; n < M; ++n) {
        int f, h;
        cin >> f >> h;
        int l, r;
        int hh;
        for(l = 0, hh = h; l < N; ++l) {
            if(S[l] == f) {
                --hh;
                if(hh == 0) {
                    break;
                }
            }
        }
        for(r = N - 1, hh = h; r >= 0; --r) {
            if(S[r] == f) {
                --hh;
                if(hh == 0) {
                    break;
                }
            }
        }
        C[f].push_back(cow_t{l, r});
    }
    
    auto solve = [&](int maxl, int f0) {
        LL a = 1;
        int cnt = 0;
        for(int f = 0; f <= N; ++f) {
            int left = 0, right = 0, both = 0;
            for(auto& c : C[f]) {
                if(c.l == maxl and f == f0) {
                    continue;
                }
                if(c.l < maxl and f != f0) {
                    if(c.r > maxl) {
                        ++both;
                    } else {
                        ++left;
                    }
                } else if(c.r > maxl) {
                    ++right;
                }
            }
            if(left + both == 0) {
                if(right > 0) {
                    ++cnt;
                    a = (a * right) % MOD;
                }
            } else if(right + both == 0) {
                if(left > 0) {
                    ++cnt;
                    a = (a * left) % MOD;
                }
            } else if(left + right + both == 1) {
                ++cnt;
                a = (a * 2) % MOD;
            } else {
                cnt += 2;
                a = (a * (left * (right + both) + both * (right + both - 1))) % MOD;
            }
        }
        return make_tuple(cnt, a);
    };
    
    vector<int> ans_cnt;
    vector<LL> ans_a;
    auto [cnt, a] = solve(-1, 0);
    ans_cnt.push_back(cnt);
    ans_a.push_back(a);
    for(int f = 0; f <= N; ++f) {
        for(auto& c : C[f]) {
            if(c.l < N) {
                tie(cnt, a) = solve(c.l, f);
                ans_cnt.push_back(cnt + 1);
                ans_a.push_back(a);
            }
        }
    }
    cnt = *max_element(ans_cnt.begin(), ans_cnt.end());
    a = 0;
    for(int i = 0; i < int(ans_cnt.size()); ++i) {
        if(cnt == ans_cnt[i]) {
            a = (a + ans_a[i]) % MOD;
        }
    }
    cout << cnt << " " << a << "\n";
    
    
    return 0;
}