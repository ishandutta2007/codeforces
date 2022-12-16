#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int8_t ok[1001000];

int main() {
    ok[1] = ok[2] = ok[4] = ok[5] = 1;
    for (int i=6; i<1001000; ++i) {
        int x = (i-1)/2;
        int y = i-1-x;
        ok[i] = (ok[x] && ok[y] && (y%2 == 0 || x%2 == 0));
    }
    int n;
    cin >> n;
    cout << (ok[n] ? '1' : '0') << "\n";
    return 0;
}