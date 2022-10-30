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
int K;
int x, y, xx, yy;
deque<int> q[505];
int dp[505][505], dp2[505];
long long ans;
int a[505];
vector<pair<pair<int, int>, int> > qq[505];

void solve(int l) {
    for (int i = 0; i <= K; ++i) {
        dp[l][i] = 0;
        q[i].clear();
        q[i].push_back(l);
        dp2[i] = -1e9;
    }
    int cur, x;
    for (int i = l + 1; i <= n; ++i) {
        for (int j = 1; j <= K; ++j) {
            while (!q[j - 1].empty()) {
                x = q[j - 1].front();
                if (dp[x][j - 1] <= a[i] - a[x]) {
                    q[j - 1].pop_front();
                    dp2[j - 1] = a[x];
                } else break;
            }
            cur = a[i] - dp2[j - 1];
            if (!q[j - 1].empty()) {
                x = q[j - 1].front();
                if (dp[x][j - 1] < cur) cur = dp[x][j - 1];
            }
            dp[i][j] = cur;
            q[j].push_back(i);
        }
    }
    int y, xx;
    long long cur2;
    for (int i = 0; i < qq[l].size(); ++i) {
        x = qq[l][i].first.first;
        y = qq[l][i].first.second;
        xx = qq[l][i].second;
        xx++;
        cur2 = dp[x][xx];
        //cout << x << " " << y << " " << xx << " " << cur2 << '\n';
        cur2 *= y;
        if (cur2 > ans) ans = cur2;
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    K = n + 2;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> xx >> yy;
        qq[x].push_back(make_pair(make_pair(y, xx), yy));
    }
    for (int i = 1; i <= n; ++i)
        solve(i);
    cout << ans << '\n';
}