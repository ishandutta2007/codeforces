#include <bits/stdc++.h>
using namespace std;

const int kAlphabetSize = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int m = s.length();

    vector<int> a(kAlphabetSize, 0);
    for (int i = 0; i < m; ++i) {
        ++a[s[i] - 'a'];
    }

    int amount_of_symbols = 0;
    for (int i = 0; i < kAlphabetSize; ++i) {
        if (a[i] > 0) {
            ++amount_of_symbols;
        }
    }

    int n;
    cin >> n;

    if (amount_of_symbols > n) {
        cout << -1 << endl;
        return 0;
    }

    int ans = m;

    int bl = 1;
    int br = m;
    while (bl <= br) {
        int bm = (bl + br) >> 1;

        vector<int> b(kAlphabetSize);
        for (int i = 0; i < kAlphabetSize; ++i) {
            b[i] = a[i] / bm + (a[i] % bm != 0);
        }
        int bs = 0;
        for (int i = 0; i < kAlphabetSize; ++i) {
            bs += b[i];
        }

        if (bs > n) {
            bl = bm + 1;
        } else {
            ans = bm;
            br = bm - 1;
        }
    }

    string t;
    t.resize(n);
    int last_pos = 0;
    for (int i = 0; i < kAlphabetSize; ++i) {
        int cb = a[i] / ans + (a[i] % ans != 0);
        while (cb) {
            t[last_pos] = (char)('a' + i);
            ++last_pos;
            --cb;
        }
    }

    while (last_pos < n) {
        t[last_pos] = 'a';
        ++last_pos;
    }

    cout << ans << endl;
    sort(t.begin(), t.end());
    cout << t << endl;

    return 0;
}