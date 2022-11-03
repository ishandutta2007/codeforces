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


vector<int> A[3000];
int N, M;

int dp[13][1 << 12];
vector<int> submasks[1 << 12];

void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> N >> M;
    for(int m = 0; m < M; ++m) {
        A[m] = vector<int>(N);
    }
    for(int n = 0; n < N; ++n) {
        for(int m = 0; m < M; ++m) {
            cin >> A[m][n];
        }
    }
    sort(A, A + M, [&](const vector<int>& a, const vector<int>& b) { return *max_element(a.begin(), a.end()) > *max_element(b.begin(), b.end()); });
    M = min(M, N);
    for(int m = 1; m <= M; ++m) {
        for(int rot = 0; rot < N; ++rot) {
            for(int mask = 0; mask < (1 << N); ++mask) {
                for(int s : submasks[mask]) {
                    int a = dp[m - 1][mask ^ s];
                    for(int n = 0; n < N; ++n) {
                        if(s & (1 << n)) {
                            a += A[m - 1][n];
                        }
                    }
                    dp[m][mask] = max(dp[m][mask], a);
                }
            }
            rotate(A[m - 1].begin(), A[m - 1].begin() + 1, A[m - 1].end());
        }
    }
    cout << dp[M][(1 << N) - 1] << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for(int n = 0; n < (1 << 12); ++n) {
        for(int m = 0; m < (1 << 12); ++m) {
            if((m & n) == m) {
                submasks[n].push_back(m);
            }
        }
    }
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}