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

/*pair<vector<vector<int>>, vector<vector<int>> solve(vector<int> c) {
    if(is_sorted(all_of(c))) {
        return {{}, {}};
    }
    int N = c.size();
    int i, j;
    for(i = 0; i < N; ++i) {
        for(j = 0; j < i; ++j) {
            if(c[j] == c[i] + 1) {
                break;
            }
        }
        if(c[j] == c[i] + 1) {
            break;
        }
    }
    assert(i < N);
    moves.push_back(vector<int>{j, 1, i - j, N - i - 1});
    vector<int> d;
    d.insert(d.end(), c.begin() + i + 1, c.end());
    d.insert(d.end(), c.begin() + j + 1, c.begin() + i + 1);
    d.insert(d.end(), c.begin(), c.begin() + j);
    assert(int(d.size()) == N - 1);
    for(auto& a : d) {
        if(a > c[i]) {
            --a;
        }
    }
    auto [new_moves, new_cs] = solve(d);
    
}*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> c(N);
    cin >> c;
    vector<vector<int>> moves;
    while(not(is_sorted(all_of(c)))) {
        debug(c);
        int i, j;
        for(i = 0; i < N; ++i) {
            for(j = 0; j < i; ++j) {
                if(c[j] == c[i] + 1) {
                    break;
                }
            }
            if(c[j] == c[i] + 1) {
                break;
            }
        }
        assert(i < N);
        int k = j;
        while(c[k + 1] == c[k] + 1) {
            ++k;
        }
        moves.push_back(vector<int>{j, k - j + 1, i - k, N - i - 1});
        vector<int> d;
        d.insert(d.end(), c.begin() + i + 1, c.end());
        d.insert(d.end(), c.begin() + k + 1, c.begin() + i + 1);
        d.insert(d.end(), c.begin() + j, c.begin() + k + 1);
        d.insert(d.end(), c.begin(), c.begin() + j);
        assert(int(d.size()) == N);
        c = d;
        assert(int(moves.size()) <= N);
    }
    cout << moves.size() << "\n";
    for(auto m : moves) {
        vector<int> actual_m;
        for(auto k : m) {
            if(k > 0) {
                actual_m.push_back(k);
            }
        }
        cout << actual_m.size() << " ";
        for(auto k : actual_m) {
            cout << k << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}