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
    vector<int> blocks = {0};
    vector<int> last_blocks;
    for(auto c : S) {
        if(c == 'L') {
            blocks.back()++;
        } else {
            blocks.push_back(0);
        }
    }
    if(S[N - 1] == 'L') {
        last_blocks.push_back(blocks.back());
        blocks.pop_back();
    }
    if(S[0] == 'L' and blocks.size()) {
        last_blocks.push_back(blocks[0]);
        blocks.erase(blocks.begin());
    }
    sort(all_of(blocks));
    int ans = 0;
    for(int n = 0; n < N; ++n) {
        if(S[n] == 'W') {
            if(n > 0 and S[n - 1] == 'W') {
                ++ans;
            }
            ++ans;
        }
    }
    if(last_blocks.size() and last_blocks[0] == N) {
        ans = max(0, 2 * K - 1);
    } else {
        for(auto b : blocks) {
            if(b == 0) {
                continue;
            }
            if(K >= b) {
                K -= b;
                ans += 2 * b + 1;
            } else {
                ans += 2 * K;
                K = 0;
            }
        }
        for(auto b : last_blocks) {
            assert(b > 0);
            if(K >= b) {
                K -= b;
                ans += 2 * b;
            } else {
                ans += 2 * K;
                K = 0;
            }
        }
    }
    cout << ans << "\n";
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