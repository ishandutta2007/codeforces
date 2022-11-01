#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

ll n;
string s;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    ll ans = 0, ct = 1;
    while (ct * 10LL - 1 <= n) {
        ct *= 10LL;
        ans += 9LL;
    } 
    ll kp = n - ct + 1;
    while (kp) {
        ans += kp % 10;
        kp /= 10;
    }
    cout << ans;
    return 0;
}