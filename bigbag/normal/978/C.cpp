#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, pos;
long long a[max_n], b;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int pos = 0;
    long long sum = 0;
    while (m--) {
        cin >> b;
        while (sum + a[pos] < b) {
            sum += a[pos];
            ++pos;
        }
        cout << pos + 1 << " " << b - sum << endl;
    }
    return 0;
}