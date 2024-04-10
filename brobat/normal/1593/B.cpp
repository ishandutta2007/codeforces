#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, ans;
vector <char> v;

void solve(char f, char g) {
    int a = -1, b = -1;
    forn(i, 0, n) {
        // cout << v[i] << " " << f << endl;
        if(v[i]==f && a == -1) {
            a = i;
        }
        if(v[i]==g && b == -1 && a != -1) {
            b = i;
        }
    }
    if(a == -1 || b == -1) return;
    ans = min(ans, b - 1);
}

void solve(char f) {
    int a = -1, b = -1, c = -1;
    forn(i, 0, n) {
        // cout << v[i] << " " << f << endl;
        if(v[i]==f && a == -1) {
            a = i;
            continue;
        }
        if(v[i]==f && b == -1 && a != -1) {
            b = i;
            break;
        }
    }
    if(a == -1 || b == -1) return;

    forn(i, b + 1, n) {
        if(v[i] != f) {
            c = i;
            break;
        }
    }

    if(c == -1) return;

    ans = min(ans, b - 1);
}

void solve() {
    ans = 1E9;
    string s; cin >> s;
    n = s.length();
    v.resize(n);
    forn(i, 0, n) v[i] = s[n - i - 1];
    // for(auto i : v) cout << i << " ";
    // 25.
    solve('5', '2');
    solve('5', '7');
    solve('0', '5');
    solve('0');
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}