#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL cnt[300][300];
LL X[300];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string S;
    cin >> S;
    
    for(char c : S) {
        for(char d = 'a'; d <= 'z'; ++d) {
            cnt[d][c] += X[d];
        }
        ++X[c];
    }
    LL ans = *max_element(X + 'a', X + 'z' + 1);
    for(char c = 'a'; c <= 'z'; ++c) {
        for(char d = 'a'; d <= 'z'; ++d) {
            ans = max(ans, cnt[c][d]);
        }
    }
    cout << ans << "\n";
    
    return 0;
}