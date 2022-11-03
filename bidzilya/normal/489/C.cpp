#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int m, s;
    cin >> m >> s;

    if (s > m * 9) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }


    if (m == 1) {
        cout << s << " " << s << endl;
        return 0;
    }

    if (s == 0) {
        cout << -1 << " " << -1 << endl;
        return 0;
    }

    int cs = s;

    vector<int> mn(m);
    for (int i = 0; i < m; ++i) {
        int l = 0;
        if (i == 0) {
            l = 1;
        }
        for (int j = l; j < 10; ++j) {
            if (s - j >= 0 && s - j <= 9 * (m - i - 1)) {
                mn[i] = j;
                s -= j;
                break;
            }
        }
    }

    s = cs;
    vector<int> mx(m);
    for (int i = 0; i < m; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (s - j >= 0 && s - j <= 9 * (m - i - 1)) {
                mx[i] = j;
                s -= j;
                break;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << mn[i];
    }
    cout << " ";
    for (int i = 0; i < m; ++i) {
        cout << mx[i];
    }
    cout << endl;

    return 0;
}