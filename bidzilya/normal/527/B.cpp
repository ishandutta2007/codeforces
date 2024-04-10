#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    const int kMaxC = 26;
    vector<vector<int> > a(kMaxC, vector<int>(kMaxC, 0));
    vector<vector<int> > lid(kMaxC, vector<int>(kMaxC, -1));
    int dist = 0;
    for (int i = 0; i < n; ++i) {
        int c1 = s[i] - 'a';
        int c2 = t[i] - 'a';

        if (c1 != c2) {
            ++a[c1][c2];
            lid[c1][c2] = i;
            ++dist;
        }
    }
    for (int i = 0; i < n; ++i) {
        int c1 = s[i] - 'a';
        int c2 = t[i] - 'a';

        if (c1 != c2) {
            if (a[c2][c1] > 0) {
                cout << dist - 2 << endl;
                cout << lid[c2][c1] + 1 << " " << i + 1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int c1 = s[i] - 'a';
        int c2 = t[i] - 'a';

        if (c1 != c2) {
            for (int c = 0; c < kMaxC; ++c) {
                if (a[c2][c] > 0) {
                    cout << dist - 1 << endl;
                    cout << lid[c2][c] + 1 << " " << i + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << dist << endl;
    cout << "-1 -1" << endl;

    return 0;
}