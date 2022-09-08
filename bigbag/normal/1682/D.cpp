/**
 *  created: 22/05/2022, 20:00:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
string s;

void write(int a, int b) {
    cout << a + 1 << " " << b + 1 << "\n";
}

void solve(int l, int r) {
    //cout << "solve " << l + 1 << " " << r + 1 << endl;
    assert(s[l] == '1');
    while (s[(l + 1) % n] != '1') {
        write(l, (l + 1) % n);
        l = (l + 1) % n;
    }
    if ((l + 1) % n == r) {
        write(l, r);
        return;
    }
    write(l, r);
    s[r] ^= '0' ^ '1';
    solve((l + 1) % n, r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int sum = accumulate(s.begin(), s.end(), 0) - '0' * n;
        if (sum % 2 || *max_element(s.begin(), s.end()) == '0') {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                solve(i, (i + n - 1) % n);
                break;
            }
        }
    }
    return 0;
}