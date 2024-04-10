#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int N = 1515;

char s[N][35];
int n, k;

map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> s[i];
        mp[string(s[i])]++;
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i == j) continue;
            string goal;
            bool good = true;
            for (int a=0; a<k && good; ++a) {
                if (s[i][a] == 'S' && s[j][a] == 'E') goal += 'T';
                else if (s[i][a] == 'S' && s[j][a] == 'T') goal += 'E';
                else if (s[i][a] == 'E' && s[j][a] == 'S') goal += 'T';
                else if (s[i][a] == 'E' && s[j][a] == 'T') goal += 'S';
                else if (s[i][a] == 'T' && s[j][a] == 'S') goal += 'E';
                else if (s[i][a] == 'T' && s[j][a] == 'E') goal += 'S';

                else if (s[i][a] == 'S' && s[j][a] == 'S') goal += 'S';
                else if (s[i][a] == 'E' && s[j][a] == 'E') goal += 'E';
                else if (s[i][a] == 'T' && s[j][a] == 'T') goal += 'T';

                else good = false;
            }

            //cerr << " -- " << i << " " << j << " " << s[i][j] << "\n";

            if (good && mp.count(goal)) {
                ans += mp[goal];
                //cerr << " :: " << i << " " << j << " " << s[i] << " " << s[j] << " " << goal << endl;
            }
        }
    }
    cout << ans/6 << "\n";
    return 0;
}