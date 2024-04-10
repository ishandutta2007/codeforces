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
    vector<int> X(N);
    cin >> X;
    vector<int> L(N), R(N);
    {
        L[0] = 1;
        vector<int> V = { 0 };
        for(int n = 1; n < N; ++n) {
            while(V.size() and X[V.back()] >= X[n]) {
                V.pop_back();
            }
            if(V.empty()) {
                L[n] = n + 1;
            } else {
                L[n] = n - V.back();
            }
            V.push_back(n);
        }
        debug(L);
    }
    {
        R[N - 1] = 1;
        vector<int> V = { N - 1 };
        for(int n = N - 2; n >= 0; --n) {
            while(V.size() and X[V.back()] >= X[n]) {
                V.pop_back();
            }
            if(V.empty()) {
                R[n] = N - n;
            } else {
                R[n] = V.back() - n;
            }
            V.push_back(n);
        }
        debug(R);
    }
    vector<int> E(2 * N + 10, 0);
    vector<vector<int>> S(N + 1);
    for(int n = 0; n < N; ++n) {
        if(L[n] >= 2 and R[n] >= 2) {
            ++E[2];
            --E[L[n] + R[n] - 1];
            //~ cerr << 2 << " " << L[n] + R[n] - 2 << endl;
        }
        if(L[n] + R[n] - 1 > N + 1 - X[n]) {
            ++E[N + 2 - X[n]];
            --E[L[n] + R[n]];
            //~ cerr << N + 2 - X[n] << " " << L[n] + R[n] - 1 << endl;
        }
        S[X[n]].push_back(n);
    }
    for(auto& s : S) {
        set<int> q(all_of(s));
        sort(all_of(s), [&](int i, int j) { return L[i] + R[i] < L[j] + R[j]; });
        for(int i : s) {
            int l = *q.rbegin() - *q.begin();
            ++E[1];
            --E[min(l, L[i] + R[i] - 1) + 1];
            //~ cerr << 1 << " " << min(l, L[i] + R[i] - 1) << endl;
            q.erase(i);
        }
    }
    for(int i = 1; i <= N; ++i) {
        E[i] += E[i - 1];
        cout << (E[i] == 0);
    }
    cout << "\n";
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