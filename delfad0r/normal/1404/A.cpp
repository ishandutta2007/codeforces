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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    
    int x = 0, y = 0;
    for(int n = 0; n < K; ++n) {
        bool a = 0, b = 0;
        for(int i = n; i < N; i += K) {
            a |= (S[i] == '0');
            b |= (S[i] == '1');
        }
        if(a and b) {
            cout << "NO\n";
            return;
        }
        for(int i = n; i < N; i += K) {
            if(a) {
                S[i] = '0';
            } 
            if(b) {
                S[i] = '1';
            }
        }
        x += (S[n] == '0');
        y += (S[n] == '1');
    }
    if(2 * x > K or 2 * y > K) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
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