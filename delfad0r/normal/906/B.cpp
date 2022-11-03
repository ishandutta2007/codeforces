#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> II;

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

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool are_close(II a, II b) {
    return abs(a.first - b.first) + abs(a.second - b.second) <= 1;
}

template<typename T>
void transpose(vector<vector<T>>& V) {
    if(V.empty()) {
        return;
    }
    vector<vector<T>> U(V[0].size(), vector<T>(V.size()));
    for(int i = 0; i < int(V.size()); ++i) {
        for(int j = 0; j < int(V[i].size()); ++j) {
            U[j][i] = V[i][j];
        }
    }
    swap(U, V);
}

//assume N <= M;
vector<vector<II>> solve(int N, int M) {
    if(N == 1 && M == 1) {
        return {{{1, 1}}};
    }
    if(N <= 2) {
        if(M <= 3) {
            return {};
        }
        vector<vector<II>> B(N);
        for(int n = 0; n < N; ++n) {
            for(int m = 2; m <= M; m += 2) {
                B[n].emplace_back(n + 1, m);
            }
            for(int m = 1; m <= M; m += 2) {
                B[n].emplace_back(n + 1, m);
            }
        }
        if(N == 2) {
            if(M % 2) {
                rotate(B[1].begin(), B[1].begin() + 1, B[1].end());
            } else {
                reverse(B[1].begin(), B[1].end());
            }
        }
        return B;
    } else {
        vector<vector<II>> B(N, vector<II>(M));
        for(int n = 0; n < N; ++n) {
            for(int m = 0; m < M; ++m) {
                B[n][m] = II(n + 1, m + 1);
            }
        }
        for(int n = 0; n < N; ++n) {
            rotate(B[n].begin(), B[n].begin() + n, B[n].end());
        }
        transpose(B);
        for(int m = 0; m < M; ++m) {
            rotate(B[m].begin(), B[m].begin() + (m % N), B[m].end());
        }
        transpose(B);
        return B;
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<II>> B;
    if(N <= M) {
        B = solve(N, M);
    } else {
        B = solve(M, N);
        transpose(B);
        for(auto& v : B) {
            for(auto& p : v) {
                swap(p.first, p.second);
            }
        }
    }
    if(B.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for(int n = 0; n < N; ++n) {
            for(int m = 0; m < M; ++m) {
                II p = B[n][m];
                for(int i = 0; i < 4; ++i) {
                    int n1 = n + dx[i], m1 = m + dy[i];
                    if(n1 >= 0 && n1 < N && m1 >= 0 && m1 < M) {
                        if(are_close(p, B[n1][m1])) {
                            abort();
                        }
                    }
                }
                cout << (p.first - 1) * M + p.second << ' ';
            }
            cout << '\n';
        }
    }
}