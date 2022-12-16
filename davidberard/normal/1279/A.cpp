#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        ll r,g,b,s;
        cin >> r >> g >> b;
        s = r+g+b;
        ll m = max(r,max(g,b));
        cout << (m > (s+1)/2 ? "No" : "Yes") << endl;
    }
    return 0;
}