#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

vector<int> mo;

string solve() {
    char s[1000];
    memset(s, 0, 1000);
    cin >> s;
    int n = strlen(s);
    mo = vector<int>(256, 0);
    char l = 0;
    int amt = 0;
    for (int i=0; i<=n; ++i) {
        if (l != s[i]) {
            mo[l] |= amt;
            l = s[i];
            amt = 0;
        }
        ++amt;
    }
    string t = "";
    for (char c = 'a'; c<='z' ; ++c) {
        if (mo[c]&1) {
            t += c;
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    for (int tt=0; tt<TT; ++tt) {
        cout << solve() << "\n";
    }
    return 0;
}