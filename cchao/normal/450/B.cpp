#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1000000007;

int main() {
    ll a, b;
    cin >> a >> b;
    int n; cin >> n;

    n %= 6;
    ll ans = 0;
    if(n == 0) ans = a-b;
    else if(n == 1) ans = a;
    else if(n == 2) ans = b;
    else if(n == 3) ans = b - a;
    else if(n == 4) ans = -a;
    else if(n == 5) ans = -b;

    ans %= mod; if(ans < 0) ans += mod;

    cout << ans << endl;

    return 0;
}