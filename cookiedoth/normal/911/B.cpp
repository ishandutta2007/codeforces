#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll mx = 1000;
ll a, b, n;

bool check(ll x) {
  //  cout << "checking " << x << endl;
    if (a / x + b / x >= n)
        return 1;
    else
        return 0;
}

ll binsearch(ll l, ll r) {
   // cout << "bin " << l << " " << r << endl;
    if (l == r)
        return l;
    ll mid = (l + r) / 2;
    if (check(mid + 1))
        return binsearch(mid + 1, r);
    else
        return binsearch(l, mid);
}

int main()
{
    cin >> n >> a >> b;
    for (int i = mx; i >= 1; --i) {
        for (int j = 1; j <= n - 1; ++j) {
            if (j * i <= a && ((n - j) * i) <= b) {
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}