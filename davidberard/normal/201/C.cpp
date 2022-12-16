#include <cassert>
#include <iomanip>
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

const int NMAX = 100100;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll a[NMAX];
ll dpl[NMAX];
ll dpr[NMAX];
ll dp[NMAX];
ll dpd[NMAX];
int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i=1; i<n; ++i) {
        cin >> a[i];
    }
    ll e=0;
    for(int i=1; i<n; ++i) {
        dp[i+1] = dp[i]+1+((a[i]-1)/2)*2;
        if(a[i]/2 == 0) {
            e = 0;
            dpl[i+1] = 0;
        } else {
            e += (a[i]/2)*2;
            dpl[i+1] = e;
        }
        dpd[i+1] = max(dpd[i], dpl[i+1]-dp[i+1]);
    }
    e = 0;
    ll ans = dp[n];
    ans = max(ans, dpd[n]+dp[n]);
    for(int i=n-1; i>0; --i) {
        if(a[i]/2 == 0) {
            e = 0;
            dpr[i] = 0;
        } else {
            e += (a[i]/2)*2;
            dpr[i] = e;
        }
        ans = max(ans, dpr[i]+dp[i]+dpd[i]);
    }
    cout << ans << endl;
    return 0;
}