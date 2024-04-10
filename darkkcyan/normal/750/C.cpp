#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define inf ((llong) INT_MAX)
typedef pair<llong, llong> range;
range intersect(range const& u, range const& v) {
    if (u.first > v.second or v.first > u.second) return {inf, -inf};
    return {max(u.first, v.first), min(u.second, v.second)};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    range ans(-inf * 2, inf * 2);
    
    int n; cin >> n;
    while (n--) {
        int c, d; cin >> c >> d;
        if (d == 1) ans = intersect(ans, {1900, inf * 2});
        else ans = intersect(ans, {-inf * 2, 1899});
        if (ans.first > ans.second) {
            cout << "Impossible";
            return 0;
        }
        ans.first += c;
        ans.second += c;
    }
    if (ans.second >= inf) cout << "Infinity";
    else cout << ans.second;
    return 0;
}