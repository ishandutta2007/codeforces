#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int y, b, r;
    cin >> y >> b >> r;
    int l = min(y, min(b-1, r-2));
    cout << l*3+3 << "\n";
    return 0;
}