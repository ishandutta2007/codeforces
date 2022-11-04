#include <bits/stdc++.h>  
 
using namespace std;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int ans = 0;
int go[1000000][26], term[1000000], cnt[1000000], ps = 0;

void add(string s) {
    ans += sz(s);
    int nu = 0, ps1 = -1, ps2 = -1;
    forn (i, sz(s)) {
        if (go[nu][s[i] - 'a'] == -1) {
            go[nu][s[i] - 'a'] = ps;
            forn (j, 26) go[ps][j] = -1;
            ps++;
        }
        nu = go[nu][s[i] - 'a'];
        if (cnt[nu] == 1 && ps1 == -1) {
            ps1 = nu;
        }
        if (term[nu] == 1) ps2 = nu;
    }
    if (ps2 != -1 && ps1 != -1 && ps2 - ps1 >= 1) {
        ans -= (ps2 - ps1);
        ans += 1;
    }
    if (ps2 == -1 || ps1 == -1 || ps2 - ps1 <= 0 || ps2 != nu) {
        nu = 0;
        forn (i, sz(s)) {
            cnt[nu]++;
            nu = go[nu][s[i] - 'a'];
        }
        cnt[nu]++;
        term[nu]++;
    }
}

int main() {
    forn (i, 26) go[0][i] = -1;
    ps++;
    char c;
    string s;
    while (scanf("%c", &c) == 1) {
        if (c >= 'a' && c <= 'z') {
            s += c;
            continue;
        }
        ans++;
        add(s);
        s = "";
    }
    add(s);
    cout << ans << "\n";
}