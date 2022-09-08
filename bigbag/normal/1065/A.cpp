#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
long long s, a, b, c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> s >> a >> b >> c;
        long long tot = s / c;
        cout << (tot / a) * (a + b) + tot % a << "\n";
    }
    return 0;
}