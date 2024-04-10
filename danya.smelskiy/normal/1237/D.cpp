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
int a[200005];
int mx, pos;
int ans[200005];
int sz1, sz2;
pair<int, int> q1[200005];
pair<int, int> q2[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
        if (a[i] > mx) {
            mx = a[i];
            pos = i;
        }
    }
    for (int i = pos; i <= n + n; ++i) {
        if (a[i] <= (mx + 1) / 2 - 1) break;
        ++ans[pos];
    }
    if (ans[pos] == n + n - pos + 1) ans[pos] = -1;
    ans[pos + n] = ans[pos];
    q1[++sz1] = {a[pos], n + pos};
    q2[++sz2] = {a[pos], n + pos};
    for (int i = n + pos - 1; i > 0; --i) {
        int x = a[i];
        while (sz1 > 0 && q1[sz1].first < x) --sz1;
        int l = 1;
        int r = sz2;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (q2[mid].first <= (x + 1) / 2 - 1) l = mid;
            else r = mid - 1;
        }
        if (q2[l].first <= (x + 1) / 2 - 1) {
            int xx = q1[sz1].second;
            int yy = q2[l].second;
            if (yy < xx) {
                ans[i] = yy - i;
            } else {
                if (ans[xx] == -1) ans[i] = -1;
                else ans[i] = ans[xx] + xx - i;
            }
        } else {
            int y = q1[sz1].second;
            if (ans[y] == -1) ans[i] = -1;
            else ans[i] = ans[y] + y - i;
        }
        q1[++sz1] = {a[i], i};
        while (sz2 > 0 && q2[sz2].first > a[i]) --sz2;
        q2[++sz2] = {a[i], i};
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}