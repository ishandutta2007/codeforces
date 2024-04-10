#include <bits/stdc++.h>

using namespace std;

// *****

auto solve() {
    int N;
    cin >> N;
    int product = 1;
    vector<int> coprime;
    for (int i = 1; i < N; i++) {
        if (gcd(i, N) == 1) {
            product = 1ULL * product * i % N;
            coprime.push_back(i);
        }
    }
    cout << (product > 1 ? coprime.size() - 1 : coprime.size()) << endl;
    for (int n : coprime) {
        if (product == 1 || n != product) {
            cout << n << ' ';
        }
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}