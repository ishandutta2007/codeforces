#include <bits/stdc++.h>

using namespace std;

#define mp make_pair

string s[1010];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    if (n == 1) {
        cout << 6 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                cnt += s[i][k] == s[j][k];
            }
            ans = max(ans, cnt);
        }
    }
    if (ans < 2) cout << 2 << endl;
    else if (ans < 4) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}