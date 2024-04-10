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
const int C = 1e5;

int n;
int a[1005];
int b[1005];
long long ans;
int cnt[300005];
bool used[300005];
vector<pair<pair<int, int>, pair<int, int> > > v;
double zz = 0;
vector<int> vv[30005];

int gcd(int x, int y) {
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    while (x > 0 && y > 0) {
        if (x >= y) x %= y;
        else y %= x;
    }
    return x + y;
}

void dfs(int x) {
    used[x] = true;
    for (int i = 0; i < (int)vv[x].size(); ++i) {
        int to = vv[x][i];
        if (!used[to]) dfs(to);
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    long long allv = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            pair<int, int> c1 = make_pair(a[i], b[i]), c2 = make_pair(a[j], b[j]);
            if (c1 > c2) swap(c1, c2);
            int xx1 = c2.first - c1.first;
            int yy1 = c2.second - c1.second;
//            cout << xx1 << " " << yy1 << '\n';
            int zz = gcd(xx1, yy1);
            xx1 /= zz;
            yy1 /= zz;
            
            if (xx1 == 0) {
                ++cnt[a[i]];
//                cout << ">" << xx1 << '\n';
                if (cnt[a[i]] == 1) ++allv;
            } else v.push_back(make_pair(make_pair(xx1, yy1), make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    int l = 0;
    int x, y;
    vector<int> q;
    long long ans = 0;
    while (l < (int)v.size()) {
        int r = l;
        while (r < (int)v.size() && v[r].first == v[l].first) ++r;
        --r;
//        cout << l << " " << r << '\n';
        q.clear();
        for (int j = l; j <= r; ++j) {
            x = v[j].second.first;
            y = v[j].second.second;
            vv[x].push_back(y);
            vv[y].push_back(x);
            q.push_back(x);
            q.push_back(y);
        }
        int cur = 0;
        for (int i = 0; i < (int)q.size(); ++i) {
            x = q[i];
            if (!used[x]) {
                dfs(x);
                ++cur;
            }
        }
        ans += allv * cur;
        allv += cur;
        for (int i = 0; i < (int)q.size(); ++i) {
            x = q[i];
            used[x] = false;
            vv[x].clear();
        }
        l = r + 1;
    }
    cout << ans << '\n';
    return 0;
    
}