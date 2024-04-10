#include <bits/stdc++.h>
 
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define int long long
 
using namespace std;
 
int mxm(int x) {
    if(x == 0) return 0;
    return max(x % 10, mxm(x / 10));
}
 
map<pair<int,int>,pair<int,int>>mp;
 
pair<int,int> dp(int n,int m) {
    if(n <= 9 && m <= 9) {
        if(n == 0 && m == 0) return MP(0,0);
        else return MP(1, n - max(n,m));
    }
    if(mp.count(MP(n, m)))return mp[MP(n, m)];
    pair<int,int> &ch = mp[MP(n, m)];
    ch = MP(0, 0);
    while(n > 0) {
        int o = 1;
        while(o * 10 <= n) o *= 10;
        int mx = max(m, n / o);
        pair<int,int>p=dp(n % o, mx);
        n -= n % o;
        n += p.S;
        ch.F += p.F;
    }
    ch.S = n;
    return ch;
}
 
int32_t main() {
    int n;
    cin >> n;
    bool added =0 ;
    if(n == 1e18) n--, added = 1;
    cout << dp(n, 0).F + added;
}