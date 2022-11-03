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
    string S;
    cin >> N >> S;
    vector<bool> returnable(N, false);
    int cntl = 0, cntr = 0, cntb = 0;
    for(int n = 0; n < N; ++n) {
        if(S[n] == '<') {
            ++cntl;
        } else if(S[n] == '>') {
            ++cntr;
        } else {
            assert(S[n] == '-');
            ++cntb;
            returnable[n] = returnable[(n + 1) % N] = true;
        }
    }
    if(cntr == 0 or cntl == 0) {
        cout << N << "\n";
    } else {
        int ans = 0;
        for(auto r : returnable) {
            ans += r;
        }
        cout << ans << "\n";
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