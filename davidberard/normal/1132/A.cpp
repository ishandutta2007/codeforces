#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a == d && (!c || d) ? '1' : '0') << endl;
    return 0;
}