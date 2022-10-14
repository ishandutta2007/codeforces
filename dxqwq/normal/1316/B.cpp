#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2139062143;

template <typename T> void read (T &x) {
    x = 0; bool f = 1; char ch;
    do {ch = getchar(); if (ch == '-') f = 0;} while (ch > '9' || ch < '0');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    x = f ? x : -x;
}

template <typename T> void write (T x) {
    if (x < 0) x = ~x + 1, putchar ('-');
    if (x > 9) write (x / 10);
    putchar (x % 10 + '0');
}

const int N = 5000 + 5;

int T, n, mn, ans;
string s, s1, s2, s3, ansstr;

int main () {
    read (T);
    while (T -- ) {
        read (n); cin >> s;
        ans = 1, ansstr = s;
        for (int i = 2; i <= n; i ++ ) {
            s1 = s.substr (0, i - 1);
            s2 = s.substr (i - 1, n);
            if (!((n - i) & 1)) reverse (s1.begin (), s1.end ());
            s3 = s2 + s1;
            if (s3 < ansstr) ansstr = s3, ans = i;
        }
        cout << ansstr << endl << ans << endl;
    }
}