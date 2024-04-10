#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

void solve() {
    int N, M, K;
    string E;
    cin >> N >> M >> K;
    cin >> E;
    if(N > M) {
        swap(N, M);
    }
    int ans = M * N;
    vector<int> C(26, 0);
    for(auto e : E) {
        C[int(e - 'A')]++;
    }
    for(int l = 0; l < 26; ++l) {
        if(K - C[l] < N) {
            ans = min(ans, M * (N - K + C[l]));
            continue;
        }
        vector<int> S(N, 0);
        int min_sum_gt_N = 1 << 30;
        S[0] = 1;
        for(int i = 0; i < 26; ++i) {
            if(i == l) {
                continue;
            }
            for(int n = N - 1; n >= 0; --n) {
                if(S[n]) {
                    if(n + C[i] >= N) {
                        min_sum_gt_N = min(min_sum_gt_N, n + C[i]);
                    } else {
                        S[n + C[i]] = 1;
                    }
                }
            }
        }
        int m = min_sum_gt_N;
        for(int a = 0; a <= N and a <= C[l]; ++a) {
            if(a > 0 and S[N - a]) {
                m = N - a;
            }
            int u = K - C[l] - m, b = max(0, M - u);
            if(a + b <= C[l]) {
                //cerr << char(l + 'A') << ' ' << a << ' ' << b << ' ' << m << ' ' << u << endl;
                ans = min(ans, a * b);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}