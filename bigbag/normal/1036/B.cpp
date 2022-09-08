#include <bits/stdc++.h>

using namespace std;

int t;
long long n[2], k;

long long solve() {
    long long res = k;
    for (int i = 0; i < 2; ++i) {
        if (n[i] > k) {
            return -1;
        }
        if (n[i] % 2 != k % 2) {
            --res;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n[0] >> n[1] >> k;
        cout << solve() << "\n";
    }
    return 0;
}