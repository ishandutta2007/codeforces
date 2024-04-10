#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    ll sol = (1LL << (n + 1)) - 2;
    cout << sol << "\n";


    return 0;
}