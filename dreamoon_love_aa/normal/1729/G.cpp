#include<iostream>
#include<algorithm>
#define SZ(X) ((int)(X).size())
#define MP make_pair
const int MOD = 1e9 + 7;
using namespace std;
const int SIZE = 514;
pair<int, int> dp[SIZE];
string s, t;
void add(pair<int, int> &v, pair<int, int> v2) {
    v2.first++;
    if(v2.first < v.first) {
        v = v2;
    }
    else if(v2.first == v.first) {
        v.second += v2.second;
        if(v.second >= MOD) v.second -= MOD;
    }
}
void solve() {
    cin >> s >> t;
    int n = SZ(s);
    int m = SZ(t);
    for(int i = 0; i <= n; i++) {
        if(i < m) {
            dp[i] = {0, 1};
            continue;
        }
        dp[i] = {n, 0};
        if(s.substr(i - m, m) == t) {
            add(dp[i], dp[i - m]);
            for(int j = 1; j < m; j++) {
                if(i - j - m >= 0 && s.substr(i - j - m, m) == t) {
                    add(dp[i], dp[i - j - m]);
                }
            }
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << dp[n].first << ' ' << dp[n].second << '\n';
}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}