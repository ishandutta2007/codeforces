#include <bits/stdc++.h>

using namespace std;

long long n, m;

long long get_min() {
    return max(0LL, n - 2 * m);
}

long long get_max() {
    for (long long i = 0; i <= n; ++i) {
        if (m <= (i * (i - 1)) / 2) {
            return n - i;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    cout << get_min() << " " << get_max() << endl;
    return 0;
}