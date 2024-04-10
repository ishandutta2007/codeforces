# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n;
long long a[1505];
vector<pair<long long, pair<int, int> > > q;
pair<int, int> b[1505 * 1505];
vector<pair<int, int> > ans;
int dp[1505 * 1505];
int dp2[1505 * 1505];

void solve(int n) {
    int l, r, ll;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1;
        ll = b[i].second;
        l = 1;
        r = i - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (b[mid].first < ll) l = mid;
            else r = mid - 1;
        }
        if (r < i && b[r].first < ll) dp[i] = max(dp[i], dp2[r] + 1);
        dp2[i] = max(dp2[i - 1], dp[i]);
    }
    if (dp2[n] > (int)ans.size()) {
        ans.clear();
        int last = 5005;
        int res = dp2[n];
        for (int i = n; i > 0; --i) if (b[i].first < last && dp[i] == res) {
            --res;
            ans.push_back(make_pair(b[i].second, b[i].first));
            last = b[i].second;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            q.push_back(make_pair(a[j] - a[i - 1], make_pair(j, i)));
    sort(q.begin(), q.end());
    int l = 0;
    while (l < (int)q.size()) {
        int r = l;
        while (r < (int)q.size() && q[r].first == q[l].first) ++r;
        int m;
        m = 0;
        for (int j = l; j < r; ++j)
            b[++m] = q[j].second;
        solve(m);
        l = r;
    }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}