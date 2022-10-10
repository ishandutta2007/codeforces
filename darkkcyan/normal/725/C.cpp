#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;
string s, ans[2];

ve<vi> pos(27);

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> s;
    for (int i = 0; i < sz(s); ++i) {

        pos[s[i] - 'A'].push_back(i);
    }
    int g;
    for (g = 0; g < 26; ++g) if (sz(pos[g]) == 2) {
        if (pos[g][0] == pos[g][1] - 1) return cout << "Impossible", 0;
        break;
    }
    int c = pos[g][1] - pos[g][0] - 1;
    ans[0].resize(13); ans[1] = ans[0];
    int p = c / 2;
    int f = pos[g][0];
    int i;
    for (i = p; i >= 0; --i, ++f) ans[0][i] = s[f];
    for (i = 0; f < pos[g][1]; ++i, ++f) ans[1][i] = s[f];
    for (++ f; i < 13 and f < sz(s); ++i, ++f) ans[1][i] = s[f];
    for (i = 12; f < sz(s) and i >= 0; --i, ++f) ans[0][i] = s[f];
    for (i = p + 1, f = pos[g][0] - 1; i < 13 and f >= 0; ++i, --f) ans[0][i] = s[f];
    for (i = 12; i >= 0 and f >= 0; --i, --f) ans[1][i] = s[f];
    cout << ans[0] << endl << ans[1];
    return 0;
}