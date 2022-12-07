#include <bits/stdc++.h>
using namespace std;
#define int long long


// 0000000000
// 000000000

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int a, b;
    cin >> a >> b;
    int s = 1 + a;
    int mn = 1E10;
    int mx = -1;
    /*
    Check for points st (1 + a + b + l) % k == 0
    or (1 + a - b + l) % k == 0
    l --> From 1 to n*k.
    */
   int x = (a + b) % k;
   int l_min = k - x;
   if(l_min == 0) l_min += k;
    for(int i = l_min; i <= n * k; i += k) {
        mn = min(mn, n * k / __gcd(i, n * k));
        mx = max(mx,  n * k / __gcd(i, n * k));
    }
    x = (a - b + k) % k;
    l_min = k - x;
    if(l_min == 0) l_min += k;
    for(int i = l_min; i <= n * k; i += k) {
        mn = min(mn,  n * k / __gcd(i, n * k));
        mx = max(mx,  n * k / __gcd(i, n * k));
    }
    cout << mn << " " << mx << endl;
    if(a ==  b == 1) {

    }
    
    return 0;
}