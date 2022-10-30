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
long long m;
long long a[200005], p[200005];
vector<long long> v;
long long f[200005];

void add(int x) {
    while (x <= n) {
        f[x]++;
        x = (x | (x + 1));
    }
    return;
}

long long get(int x) {
    long long res = 0;
    while (x >= 0) {
        res += f[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}

inline long long get_pos(long long x) {
    int l = 0;
    int r = v.size() - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (v[mid] <= x) l = mid;
        else r = mid - 1;
    }
    if (v[l] <= x)
    return l;
    return -1;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        v.push_back(p[i]);
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    add(get_pos(0));
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += i - get(get_pos(p[i] - m));
        add(get_pos(p[i]));
    }
    cout << ans << '\n';
}