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


int n, m, d, all;
pair<int, int> a[200005];
int used[200005];
int q[200005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    int ans = 0, last = 1;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ++ans;
            used[i] = ++all;
        }
        last = max(last, i);
        while (last <= n && (a[last].first - a[i].first <= d || used[last])) ++last;
        if (last <= n) {
            used[last] = used[i];
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; ++i)
        q[a[i].second] = used[i];
    for (int i = 1; i <= n; ++i) {
        if (i - 1) cout << " ";
        cout << q[i];
    }
    cout << '\n';
}