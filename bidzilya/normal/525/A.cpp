#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(26, 0);
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ++c[s[2 * i] - 'a'];
        --c[s[2 * i + 1] - 'A'];
        if (c[s[2 * i + 1] - 'A'] < 0) {
            c[s[2 * i + 1] - 'A'] = 0;
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}