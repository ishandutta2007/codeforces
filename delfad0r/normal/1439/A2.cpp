#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(auto& s : S) {
        cin >> s;
    }
    auto flip = [](char& c) {
        c = (c == '0') ? ('1') : ('0');
    };
    vector<pair<int, int>> moves;
    auto make_move = [&](int i, int j) {
        assert(0 <= i and i < N and 0 <= j and j < M);
        flip(S[i][j]);
        moves.emplace_back(i, j);
    };
    while(N > 2) {
        int n = N - 1;
        for(int m = M - 1; m > 1; --m) {
            if(S[n][m] == '0') {
                continue;
            }
            make_move(n, m);
            make_move(n, m - 1);
            make_move(n - 1, m);
        }
        if(S[n][0] == '1') {
            make_move(n, 0);
            make_move(n - 1, 0);
            if(S[n][1] == '1') {
                make_move(n, 1);
            } else {
                make_move(n - 1, 1);
            }
        } else if(S[n][1] == '1') {
            make_move(n, 1);
            make_move(n - 1, 0);
            make_move(n - 1, 1);
        }
        --N;
    }
    while(M > 2) {
        int m = M - 1;
        if(S[0][m] == '1') {
            make_move(0, m);
            make_move(0, m - 1);
            if(S[1][m] == '1') {
                make_move(1, m);
            } else {
                make_move(1, m - 1);
            }
        } else if(S[1][m] == '1') {
            make_move(1, m);
            make_move(0, m - 1);
            make_move(1, m - 1);
        }
        --M;
    }
    int cnt = 0;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cnt += (S[i][j] == '1');
        }
    }
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(S[i][j] == '1' - (cnt % 2)) {
                for(int n = 0; n < 2; ++n) {
                    for(int m = 0; m < 2; ++m) {
                        if(n != i or m != j) {
                            moves.emplace_back(n, m);
                        }
                    }
                }
            }
        }
    }
    assert(moves.size() % 3 == 0 and moves.size() <= 3 * S.size() * S[0].length());
    cout << (moves.size() / 3) << "\n";
    for(int i = 0; i < int(moves.size()); i += 3) {
        for(int j = i; j < i + 3; ++j) {
            cout << moves[j].first + 1 << " " << moves[j].second + 1 << " ";
        }
        cout << "\n";
    }
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
    
    return 0;
}