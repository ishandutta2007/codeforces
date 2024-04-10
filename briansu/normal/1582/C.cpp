#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = -1;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            int l = 0, r = n - 1, tt = 0;
            while (l < r) {
                if (s[l] == s[r])
                    ++l, --r;
                else if (s[l] != s[r]) {
                    if (s[l] == c)
                        ++l, ++tt;
                    else if (s[r] == c)
                        --r, ++tt;
                    else {
                        tt = -1;
                        break;
                    }
                }
            }
            if (tt != -1 && (ans == -1 || tt < ans))
                ans = tt;
        }
        cout << ans << "\n";
    }
}