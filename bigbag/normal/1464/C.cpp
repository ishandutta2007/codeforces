/**
 *  created: 20/12/2020, 18:28:42
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_c = 30;

int n;
long long x, cnt[max_c];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> x >> s;
    x += (1 << (s[n - 2] - 'a'));
    x -= (1 << (s[n - 1] - 'a'));

    if (x < 0) {
        x = -x;
    }

    n -= 2;
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
    }
    for (long long i = 0; i < max_c; ++i) {
        x += cnt[i] << i;
    }
    for (int i = max_c - 1; i >= 0; --i) {
        long long pw = (1LL << (i + 1));
        if (x - cnt[i] * pw < 0) {
            x %= pw;
        } else {
            x -= cnt[i] * pw;
        }
    }
    if (x == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}