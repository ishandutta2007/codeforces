#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;
ll a[100100];
ll cnt[100100];
ll s, f, t, m, ct;
pii ans;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s >> f >> t;
    cin >> n;
    for(int i=1; i<=n; ++i) {
        ll x;
        cin >> x;
        if(x == a[m]) ++cnt[m];
        else {
            a[++m] = x;
            ++cnt[m];
        }
    }
    ct = s;
    ans = pii(1e18, s);
    for(int i=1; i<=m; ++i) {
        if(ct+t > f) break;
        if(a[i]-1+t > f) break;
        ans = min(ans, pii(max(ct-a[i]+1, 0ll), a[i]-1));
        ct = max(ct+t*cnt[i], a[i]+t*cnt[i]);
    }
    if(ct+t <= f) ans = pii(0, f-t);

    cout << ans.second << endl;

    return 0;
}