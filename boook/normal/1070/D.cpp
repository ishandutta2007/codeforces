#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    ll ans = 0;
    ll pre = 0;
    for (int i=0;i<n;++i) {
        ll x;
        cin >> x;
        ll need = (pre+k-1)/k;
        x += pre;
        pre = 0;
        ll real = max(need,x/k);
        x -= real*k;
        ans += real;
        pre = max(x,0LL);
    }
    if (pre != 0) {
        ans += (pre+k-1)/k;
    }
    cout << ans << endl;
}