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
int sz;
int nn;
long long q[1000005];
pair<pair<int, int>, int> s[1000005];
int a[1000005];

void update(int l, int r, int x) {
    q[l] += x;
    q[r + 1] -= x;
    return;
}

void solve(int n) {
    sz = 0;
    q[1] += a[1];
    q[m - n + 2] -= a[1];
    s[++sz] = {{1, m - n + 1}, a[1]};
    for (int i = 2; i <= n; ++i) {
        int l = i;
        int r = m - (n - i);
        update(r, r, a[i]);
        while (sz > 0 && s[sz].second < a[i]) {
            if (s[sz].first.second < l) break;
            if (s[sz].first.first >= l) {
                update(s[sz].first.first, s[sz].first.second, a[i] - s[sz].second);
                --sz;
                continue;
            }
            update(l, s[sz].first.second, a[i] - s[sz].second);
            s[sz].first.second = l - 1;
            break;
        }
        ++sz;
        s[sz] = {{s[sz - 1].first.second + 1, r}, a[i]};
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> nn >> m;
    m += 2;
    for (int i = 1; i <= nn; ++i) {
        cin >> n;
        a[1] = 0;
        for (int j = 1; j <= n; ++j)
            cin >> a[j + 1];
        n += 2;
        a[n] = 0;
        solve(n);
    }
    long long last = 0;
    for (int i = 1; i <= m; ++i) {
        last += q[i];
        if (i >= 2 && i <= m - 1) cout << last << " ";
    }
    cout << '\n';
}