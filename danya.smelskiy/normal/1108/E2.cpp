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


int n, m;
int a[100005];
pair<int, int> b[100005];
vector<pair<int, int> > q[100005], qq[100005];
int dp1[100005];
int dp2[100005];
int ans = 0, pos;

void calc_dp() {
    dp1[0] = -1e9;
    dp2[n + 1] = -1e9;
    for (int i = 1; i <= n; ++i) {
        dp1[i] = dp1[i - 1];
        if (a[i] > dp1[i]) dp1[i] = a[i];
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] *= -1;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i].first >> b[i].second;
        for (int j = b[i].first; j <= b[i].second; ++j)
            ++a[j];
        q[b[i].first].push_back(make_pair(b[i].first, b[i].second));
        qq[b[i].second + 1].push_back(make_pair(b[i].first, b[i].second));
    }
    calc_dp();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)q[i].size(); ++j) {
            int l = q[i][j].first;
            int r = q[i][j].second;
            for (int k = l; k <= r; ++k)
                --a[k];
            calc_dp();
        }
        for (int j = 0; j < (int)qq[i].size(); ++j) {
            int l = qq[i][j].first;
            int r = qq[i][j].second;
            for (int k = l; k <= r; ++k)
                ++a[k];
            calc_dp();
        }
        int cur;
        cur = dp1[n] - a[i];
        if (cur > ans) {
            ans = cur;
            pos = i;
        }
    }
    cout << ans << '\n';
    vector<int> z;
    for (int i = 1; i <= m; ++i)
        if (b[i].second < pos || b[i].first > pos) z.push_back(i);
    cout << (int)z.size() << '\n';
    for (int i = 0; i < (int)z.size(); ++i)
        cout << z[i] << " ";
    cout << '\n';
    return 0;
}