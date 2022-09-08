#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

long long n;
vector<long long> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    long long ans = n;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            while (n % i == 0) {
                n /= i;
            }

        }
    }
    if (n > 1) {
        v.push_back(n);
    }
    if (v.size() == 1) {
        ans = v[0];
    } else {
        ans = 1;
    }
    cout << ans << "\n";
    return 0;
}