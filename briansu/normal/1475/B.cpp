#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll T;
    cin >> T;
    ll n;
    while (T--) {
        cin >> n;
        int x = n / 2020, y = n % 2020;
        if (y <= x) cout << "YES\n";
        else cout << "NO\n";
    }
}