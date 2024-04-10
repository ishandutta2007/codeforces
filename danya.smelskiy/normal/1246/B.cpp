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
map<vector<pair<int, int> >, int> mt;

vector<pair<int, int> > get_vector(int x) {
    vector<pair<int, int> > res;
    for (int i = 2; i * i <= x; ++i) if (x % i == 0) {
        int cur = 0;
        while (x % i == 0) {
            ++cur;
            x /= i;
        }
        cur %= m;
        if (cur > 0) res.push_back({i, cur});
    }
    if (x > 1 && m != 1) res.push_back({x, 1});
    sort(res.begin(), res.end());
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<pair<int, int> > v, vv;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v = get_vector(a[i]);
        vv.clear();
        for (int j = 0; j < v.size(); ++j)
            vv.push_back({v[j].first, m - v[j].second});
        if (mt.count(vv)) res += mt[vv];
        mt[v]++;
    }
    cout << res << '\n';
    return 0;
}