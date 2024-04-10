#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    ll a = sqrt(n);
    ll b = a;
    while(a*b < n) ++b;
    cout << a + b << "\n";
    return 0;
}