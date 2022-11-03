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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    set<int> for2, for3;
    vector<int> for2y(N), for3y(N);
    vector<pair<int, int>> ans;
    for(int n = N - 1; n >= 0; --n) {
        if(A[n] == 0) {
            continue;
        }
        if(A[n] == 1) {
            ans.emplace_back(n + 1, N - n);
            for2.insert(n);
            for2y[n] = N - n;
            for3.insert(n);
            for3y[n] = N - n;
        }
        if(A[n] == 2) {
            if(for2.empty()) {
                cout << "-1\n";
                return 0;
            }
            auto x = *for2.begin();
            for2.erase(x);
            for3.erase(x); //does this work?;
            ans.emplace_back(n + 1, for2y[x]);
            for3.insert(n);
            for3y[n] = for2y[x];
        }
        if(A[n] == 3) {
            if(for3.empty()) {
                cout << "-1\n";
                return 0;
            }
            auto x = *for3.begin();
            for3.erase(x);
            for2.erase(x);
            ans.emplace_back(n + 1, N - n);
            ans.emplace_back(x + 1, N - n);
            for3.insert(n);
            for3y[n] = N - n;
        }
    }
    cout << ans.size() << "\n";
    for(auto [x, y] : ans) {
        cout << N + 1 - y << " " << x << "\n";
    }
    
    
    return 0;
}