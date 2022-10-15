#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool chk(int x) {
    for (int i = 2; i <= 9; i++) {
        if (x % i) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c = 1;
    while (!chk(c)) {
        c++;
    }
    ll n;
    cin >> n;
    cout << n / (ll) c << "\n";

    return 0;
}