#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = len(s);
    vector<int> cnt(n + 1);
    for (int i = n; i--; )
        cnt[i] = cnt[i + 1] + (s[i] == 'v' and i + 1 < n and s[i + 1] == 'v');

    int cntpref = 0;
    llong ans = 0;
    rep(i, n) {
        if (s[i] == 'v') cntpref += i > 0 and s[i - 1] == 'v';
        else ans += 1ll * cntpref * cnt[i + 1];
    }
    cout << ans;

    return 0;
}