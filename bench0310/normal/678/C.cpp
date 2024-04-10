#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b,p,q;
    cin >> n >> a >> b >> p >> q;
    ll one=n/a-n/lcm(a,b);
    ll two=n/b-n/lcm(a,b);
    cout << one*p+two*q+(n/lcm(a,b))*max(p,q) << "\n";
    return 0;
}