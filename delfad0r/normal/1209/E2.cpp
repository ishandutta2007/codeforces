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

int memo[12][13][1 << 12];
vector<int> submasks[1 << 12];

void dp(int l, int r) {
    if(l + 1 == r) {
        for(int mask = 0; mask < (1 << N); ++mask) {
            for(int rot = 0; rot < N; ++rot) {
                int a = 0;
                for(int i = 0; i < N; ++i) {
                    if(mask & (1 << i)) {
                        a += A[l][(i + rot) % N];
                    }
                }
                memo[l][r][mask] = max(memo[l][r][mask], a);
            }
        }
    } else {
        int m = (l + r) / 2;
        dp(l, m);
        dp(m, r);
        for(int mask = 0; mask < (1 << N); ++mask) {
            for(int sub : submasks[mask]) {
                memo[l][r][mask] = max(memo[l][r][mask], memo[l][m][sub] + memo[m][r][mask ^ sub]);
            }
        }
    }
}

void solve() {
    memset(memo, -1, sizeof(memo));
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
    dp(0, M);
    cout << memo[0][M][(1 << N) - 1] << "\n";
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