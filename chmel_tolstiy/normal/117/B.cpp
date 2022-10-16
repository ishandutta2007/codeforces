#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int n, m, M;
    cin >> n >> m >> M;

    int x = 1;
    for (int i = 0; i < 9; i++) x = x * 10 % M;

    int C = 0, B;
    for (int i = 1; i <= n && i < M; i++) {
        C += x; if (C >= M) C -= M;
        B = M - C; if (B >= M) B -= M;
        if (B > m) {
            stringstream str;
            str << i;
            string s = str.str();
            cout << 1 << ' ' << string(9-s.length(), '0') << s << endl;
            return 0;
        }
    }

    cout << 2 << endl;
    return 0;
}