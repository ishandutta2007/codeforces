#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, a, b; cin >> n >> m >> a >> b;
    long long minl = n * m, maxl = 1;
    for (int i = 0; i < n; i++) {
        for (int j : {-1, 1}) {
            for (int k : {-1, 1}) {
                long long r = (j * b + i * m + n * m - k * a) % (n * m);
                minl = min(minl, n * m / __gcd(r, n * m));
                maxl = max(maxl, n * m / __gcd(r, n * m));
            }
        }
    }
    cout << minl << ' ' << maxl << endl;
	return 0;
}