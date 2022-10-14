#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    string s;
    cin >> N >> s;
    string a(N, 'x'), b(N, 'x');
    int zeros = count(begin(s), end(s), '0');
    if (zeros & 1) {
        return "NO"s;
    }

    int al = 0, bl = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            if (al == 0 || bl == 0) {
                a[i] = b[i] = '(';
                al++, bl++;
            } else if (i + 1 == N || al > 1 || bl > 1) {
                a[i] = b[i] = ')';
                al--, bl--;
            } else {
                a[i] = b[i] = '(';
                al++, bl++;
            }
        } else {
            if (al == 0 && bl == 0) {
                return "NO"s;
            } else if (al < bl) {
                a[i] = '(', b[i] = ')';
                al++, bl--;
            } else {
                a[i] = ')', b[i] = '(';
                al--, bl++;
            }
        }
    }
    if (al > 0 || bl > 0) {
        return "NO"s;
    }

    return "YES\n" + a + "\n" + b;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}