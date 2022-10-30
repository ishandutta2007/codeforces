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
long long a[200005];
long long b[200005];
map<long long, int> mt;
long long cur, x;
vector<int> v[200005];

int get(int x, int y) {
    int l = 0;
    int r = v[x].size() - 1;
    if (l > r) return 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (v[x][mid] >= y) r = mid;
        else l = mid + 1;
    }
    if (v[x][l] >= y) return (int)v[x].size() - l;
    return 0;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    for (int i = 1; i <= n + n; ++i) {
        a[i] += a[i - 1];
        b[i] = a[i];
    }
    sort(b + 1, b + n + n + 1);
    int last = 0;
    for (int i = 1; i <= n + n; ++i)
        if (i == 1 || b[i] != b[i - 1]) {
            ++last;
            mt[b[i]] = last;
        }
    int ans = 1e9;
    for (int i = 1; i <= n + n; ++i) {
        x = a[i];
        x = mt[x];
        a[i] = x;
        v[x].push_back(i);
        if (i >= n) {
            cur = n - get(a[i - n], i - n + 1);
            if (cur < ans) ans = cur;
        }
    }
    cout << ans << '\n';

}