#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

char s[20];
char t[10][20];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4];
    for (int i=0; i<5; ++i) {
        if (t[i][0] == s[0] || t[i][1] == s[1]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}