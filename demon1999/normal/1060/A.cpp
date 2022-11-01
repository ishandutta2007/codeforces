#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

int n;
string s;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s;
    int k = 0;
    forn (i, sz(s)) {
        if (s[i] == '8') k++;
    }
    int ans = min(k, n / 11);
    cout << ans;
    return 0;
}