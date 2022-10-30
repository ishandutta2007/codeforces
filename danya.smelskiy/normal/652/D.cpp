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


int n, sz;
int x, y;
vector<int> v;
map<int, int> mt;
pair<pair<int, int>, int> a[200005];
int ans[200005];
int t[2000005];

inline bool cmp(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
    return x.first.second < y.first.second;
}

void update(int x) {
    x += sz - 1;
    while (x) {
        t[x]++;
        x >>= 1;
    }
}

int get(int l, int r, int ll, int rr, int x) {
    if (l > r || ll > r || l > rr || ll > rr) return 0;
    if (l >= ll && r <= rr) return t[x];
    int mid = (l + r) >> 1;
    return get(l, mid, ll, rr, x + x) + get(mid + 1, r, ll, rr, x + x + 1);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        a[i] = {{x, y}, i};
        v.push_back(x);
        v.push_back(y);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        mt[v[i]] = i + 1;
    sz = 1;
    while (sz < (int)v.size()) sz += sz;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        x = a[i].first.first;
        x = mt[x];
        update(x);
        ans[a[i].second] = get(1, sz, x + 1, sz, 1);
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
}