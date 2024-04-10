#include <cassert>
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

int n, m, r;

int s[1010], b[1010];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> r;
    int smin = 10000, bmax = 0;
    for(int i=1; i<=n; ++i) {
        cin >> s[i];
        smin = min(smin, s[i]);
    }
    for(int i=1; i<=m; ++i) {
        cin >> b[i];
        bmax = max(bmax, b[i]);
    }
    ll ans ;
    if(smin < bmax) {
        ans = (r/smin)*bmax;
        ans += r%smin;
    } else {
        ans = r;
    }
    cout << ans << endl;

    return 0;
}