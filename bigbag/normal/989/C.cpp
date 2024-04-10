#include <bits/stdc++.h>

using namespace std;

const int max_n = 55, inf = 1000111222;

int a, b, c, d, n, m;
string s[max_n];

void fil(char x, char y, int cnt) {
    while (cnt) {
        for (int i = 0; i < 25; ++i) {
            if (cnt) {
                --cnt;
                s[n] += y;
            } else {
                s[n] += x;
            }
            s[n] += x;
            s[n + 1] += x;
            s[n + 1] += x;
        }
        n += 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    m = 50;
    cin >> a >> b >> c >> d;
    --a;
    fil('A', 'B', b);
    fil('A', 'C', c);
    fil('A', 'D', d - 1);
    for (int i = 0; i < m; ++i) {
        s[n] += 'D';
    }
    ++n;
    fil('D', 'A', a);
    cout << n << " " << m << endl;
    for (int i = 0; i < n; ++i) {
        cout << s[i] << endl;
    }
    return 0;
}