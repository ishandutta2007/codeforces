/*  * In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200002;
int a[N];
short s[N];

short size(int x) { 
    return (short)to_string(x).size();
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    map <int, int> mp[11];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = size(a[i]);
        mp[s[i]][a[i] % k]++;
    }   
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        mp[s[i]][a[i] % k]--;
        int x = a[i] % k, y = 1;
        for (int kk = 1; kk < 11; kk++) {
            y *= 10;
            y %= k;
            ll x2 = ((ll)x * (ll)y) % k;
            x2 %= k;
            x2 = k - x2;
            x2 %= k;
            ans += mp[kk][x2];
        }
        mp[s[i]][a[i] % k]++;
    }
    cout << ans;
}