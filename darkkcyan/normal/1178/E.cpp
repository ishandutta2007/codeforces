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

string s; 
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    string half;
    int i, f;
    for (i = 0, f = len(s) - 1; i + 1 < f - 1; i += 2, f -= 2) {
        // clog << i << ' ' << f << endl;
        int cnt[] = {0, 0, 0};
        cnt[s[i] - 'a']++;
        cnt[s[i + 1] - 'a']++;
        cnt[s[f] - 'a']++;
        cnt[s[f - 1] - 'a']++;
        rep(g, 3) if (cnt[g] > 1) {
            half += char('a' + g);
            break;
        }
    }
    cout << half;
    if (len(half) * 2 < len(s) / 2) cout << s[len(s) / 2];
    reverse(half.begin(), half.end());
    cout << half;

    return 0;
}