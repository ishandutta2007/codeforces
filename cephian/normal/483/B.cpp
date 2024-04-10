#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll a, b, x, y;

bool ok(ll v) {
    ll both = v-(v/x)-(v/y)+(v/(x*y));
    ll A = v/y - v/(x*y);
    ll B = v/x - v/(x*y);
    return both >= max(0LL, a - A) + max(0LL, b-B);
}

int main() {
    cin >> a >> b >> x >> y;
    ll lo = 1, hi = 1000000000000000000LL;
    while(lo < hi) {
        ll mid = (lo+hi)/2;
        if(ok(mid))
            hi = mid;
        else
            lo = mid+1;
    }
    cout << lo << "\n";
}