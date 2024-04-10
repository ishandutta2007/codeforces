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
    int N;
    cin >> N;
    vector<LL> A(N);
    cin >> A;
    LL sum = 0;
    for(auto a : A) {
        sum += a;
    }
    if(sum % N) {
        cout << "-1\n";
        return;
    }
    vector<tuple<int, int, int>> moves;
    auto make_move = [&](int i, int j, LL x) {
        //cerr << A << i << " " << j << " " << x << endl;
        assert(x >= 0);
        moves.emplace_back(i, j, x);
        A[i - 1] -= i * x;
        A[j - 1] += i * x;
        assert(A[i - 1] >= 0);
        assert(A[j - 1] >= 0);
    };
    for(int n = 2; n <= N; ++n) {
        if(A[n - 1] % n) {
            make_move(1, n, n - (A[n - 1] % n));
        }
        make_move(n, 1, A[n - 1] / n);
        assert(A[n - 1] == 0);
    }
    for(int n = 2; n <= N; ++n) {
        make_move(1, n, sum / N);
    }
    for(int n = 1; n <= N; ++ n) {
        assert(A[n - 1] == A[0]);
    }
    assert((int)moves.size() <= 3 * N);
    cout << moves.size() << "\n";
    for(auto& [i, j, x] : moves) {
        cout << i << " " << j << " " << x << "\n";
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