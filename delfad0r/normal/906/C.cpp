#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& vec) {
	out << "[";
	for (T x : vec) out << x << ", ";
	out << "]";
	return out;
}

#if DEBUG && !ONLINE_JUDGE
	#define dbg_var(x) cerr << #x << ": " << x << endl;
#else
	#define dbg_var(x)
#endif

int N, M;
int F[30];

void dfs(int n, int& m) {
    m &= ~(1 << n);
    for(int k = 0; k < N && (m & F[n]); ++k) {
        if(m & F[n] & (1 << k)) {
            dfs(k, m);
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> M;
    while(M--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        F[u] |= (1 << v);
        F[v] |= (1 << u);
    }
    int cnt = 0;
    for(int n = 0; n < N; ++n) {
        if(__builtin_popcount(F[n]) == N - 1) {
            ++cnt;
        }
    }
    if(cnt == N) {
        cout << 0 << '\n';
    } else if(cnt > 0) {
        cout << 1 << '\n';
        for(int n = 0; n < N; ++n) {
            if(__builtin_popcount(F[n]) == N - 1) {
                cout << n + 1 << '\n';
                return 0;
            }
        }
    } else {
        for(int ans = 2; ans <= N; ++ans) {
            for(int m = 0; m < (1 << N); ++m) {
                if(__builtin_popcount(m) != ans) {
                    continue;
                }
                int m1 = m;
                for(int n = 0; n < N; ++n) {
                    if(m & (1 << n)) {
                        m1 |= F[n];
                    }
                }
                if(__builtin_popcount(m1) < N) {
                    continue;
                }
                for(int n = 0; n < N; ++n) {
                    if(m & (1 << n)) {
                        m1 = m;
                        dfs(n, m1);
                        if(m1 == 0) {
                            cout << ans << '\n';
                            dbg_var(m);
                            for(int k = 0; k < N; ++k) {
                                if(m & (1 << k)) {
                                    cout << k + 1 << ' ';
                                }
                            }
                            cout << '\n';
                            return 0;
                        }
                        break;
                    }
                }
            }
        }
    }
}