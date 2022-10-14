#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N <= 26) {
            string s(N, 'z');
            iota(begin(s), end(s), 'a');
            cout << s << '\n';
            continue;
        }
        if (N & 1) {
            // 2a+2b+2c+3=N
            // a+b+c=(N-3)/2
            int K = (N - 3) / 2;
            int a = K / 3;
            int b = K / 3;
            int c = K - a - b;
            assert(K >= 6 && a >= 2 && b >= 2 && c >= 2);
            string s;
            s += string(a, 'a');
            s += string(b, 'b');
            s += string(c, 'c');
            s += string(a + 1, 'a');
            s += string(c + 1, 'c');
            s += string(b + 1, 'b');
            cout << s << '\n';
        } else {
            // 2a+2b+2c+2d+4=N
            // a+b+c+d=(N-4)/2>=11
            int K = (N - 4) / 2;
            int a = K / 4;
            int b = K / 4;
            int c = K / 4;
            int d = K - a - b - c;
            assert(K >= 6 && a >= 2 && b >= 2 && c >= 2 && d >= 2);
            string s;
            s += string(a, 'a');
            s += string(b, 'b');
            s += string(c, 'c');
            s += string(d, 'd');
            s += string(a + 1, 'a');
            s += string(c + 1, 'c');
            s += string(b + 1, 'b');
            s += string(d + 1, 'd');
            cout << s << '\n';
        }
    }
    return 0;
}