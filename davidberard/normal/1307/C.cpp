#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
char s[N];
ll amt[256];
ll rem[256];
ll cnt[256][256];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (s+1);
    int n = strlen(s+1);
    for (int i=1; i<=n; ++i) {
        rem[s[i]]++;
    }
    ll ans = 0;
    const int a = 'a', z = 'z';
    for (int i=a; i<=z; ++i) {
        ans = max(ans, rem[i]);
    }
    for (int i=1; i<=n; ++i) {
        int here = s[i];
        --rem[s[i]];
        for (int j=a; j<=z; ++j) {
            cnt[here][j] += rem[j];
        }
    }
    for (int i=a; i<=z; ++i) {
        for (int j=a; j<=z; ++j) {
            ans = max(ans, cnt[i][j]);
        }
    }
    cout << ans << "\n";

    return 0;
}