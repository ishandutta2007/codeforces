
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
    
    string S;
    cin >> S;
    int N = S.length();
    LL x, y;
    cin >> x >> y;
    vector<int> V;
    for(int n = 0; n < N; ++n) {
        if(S[n] == '?') {
            V.push_back(n);
            S[n] = '0';
        }
    }
    sort(all_of(V), [&](int i, int j) { return i * y + (N - 1 - i) * x > j * y + (N - 1 - j) * x; });
    debug(V);
    LL curr = 0;
    int z = 0;
    for(int n = 0; n < N; ++n) {
        if(S[n] == '0') {
            curr += (n - z) * y;
            ++z;
        } else {
            curr += z * x;
        }
    }
    LL ans = curr;
    for(int i : V) {
        S[i] = '1';
        --z;
        curr += (x + y) * z - i * y - (N - 1 - i) * x;
        ans = min(ans, curr);
    }
    cout << ans << "\n";
    
    return 0;
}