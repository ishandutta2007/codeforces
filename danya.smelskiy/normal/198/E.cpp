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
long long P, R, X, Y;
long long x, y;
int sz;
long long t[1000005];
vector<pair<long long, long long> > q;

struct iv {
    long long dist, m, p, r;
    iv () {}
} st[250005];


void update(int x) {
    x += sz - 1;
    t[x] = 1e17;
    x >>= 1;
    while (x) {
        t[x] = min(t[x + x], t[x + x + 1]);
        x >>= 1;
    }
    return;
}

int get(int l, int r, int ll, int rr, int x, long long y) {
    if (l > r || ll > r || l > rr || ll > rr || t[x] > y) return 0;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int res = get(l, mid, ll, rr, x + x, y);
    if (!res) res = get(mid + 1, r, ll, rr, x + x + 1, y);
    return res;
}

inline bool cmp(iv x, iv y) {
    return x.dist < y.dist;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> X >> Y >> P >> R >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        st[i].dist = (x - X) * 1ll * (x - X) + (y - Y) * 1ll * (y - Y);
        cin >> st[i].m >> st[i].p >> st[i].r;
    }
    sort(st + 1, st + n + 1, cmp);
    sz = 1;
    while (sz < n) sz += sz;
    for (int i = 1; i <= sz + sz; ++i)
        t[i] = 1e17;
    for (int i = 1; i <= n; ++i)
        t[sz + i - 1] = st[i].m;
    for (int i = sz - 1; i > 0; --i) {
        t[i] = min(t[i + i], t[i + i + 1]);
    }
    q.push_back({P, R});
    int ans = 0;
    for (int i = 0; i < q.size(); ++i) {
        P = q[i].first;
        R = q[i].second;
        R *= R;
        int l, r, pos;
        l = 1;
        r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (st[mid].dist <= R) l = mid;
            else r = mid - 1;
        }
        if (st[l].dist <= R) {
            while (true) {
                pos = get(1, sz, 1, l, 1, P);
                if (!pos) break;
                q.push_back({st[pos].p, st[pos].r});
                ++ans;
                update(pos);
            }
        }
    }
    cout << ans << '\n';
}