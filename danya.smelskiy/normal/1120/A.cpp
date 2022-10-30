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



int n, m, k, s;
int a[500005];
int now, all;
int cnt[500005], cnt2[500005];
bool used[500005];

void add(int x) {
    ++cnt2[x];
    if (cnt2[x] == cnt[x]) ++now;
    return;
}

void del(int x) {
    if (cnt2[x] == cnt[x]) --now;
    --cnt2[x];
    return;
}

void prnt_ans(int l, int r) {
    for (int i = 1; i <= 5e5; ++i)
        cnt2[i] = 0;
    now = 0;
    for (int i = l; i <= n; ++i) {
        ++cnt2[a[i]];
        if (cnt2[a[i]] <= cnt[a[i]]) {
            used[i] = true;
            ++now;
        }
    }
    for (int i = l; i <= n; ++i) if (!used[i] && now < m) {
        used[i] = true;
        ++now;
    }
    for (int i = r + 1; i <= n; ++i)
        used[i] = true;
    now = (l - 1) - (l - 1) % m;
    now = min(now, (k - 1) * m);
    int z = 0;
    for (int i = 1; i < l && z < now; ++i) {
        used[i] = true;
        ++z;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (used[i] == false) {
            ++res;
        }
    cout << res << '\n';
    for (int i = 1; i <= n; ++i)
        if (!used[i]) cout << i << " ";
    cout << '\n';
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= s; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
        if (cnt[x] == 1) ++all;
    }
    int r = n;
    int cur, rr;
    
    for (int i = n; i > 0; --i) {
        add(a[i]);
        while (r > i) {
            del(a[r]);
            if (now != all) {
                add(a[r]);
                break;
            }
            --r;
        }
        if (now == all) {
            cur = (i - 1) / m;
            rr = max(r, i + m - 1);
            if (rr > n) continue;
            ++cur;
            cur += (n - rr) / m;
            if (cur >= k) {
                prnt_ans(i, rr);
                return 0;
            }
        }
    }
    cout << "-1\n";
}