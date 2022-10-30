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


long long n, m, ans;
long long a[200005], b[200005];
int cnt[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        ans += a[i] * m;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (a[n] > b[1] || b[m] < a[1]) {
        cout << "-1\n";
        return 0;
    }
    int l = m;
    multiset<int> s;
    for (int i = n; i > 0; --i) {
        int x = a[i];
        while (l >= 1 && b[l] >= a[i]) {
            s.insert(b[l]);
            --l;
        }
        if ((int)s.size() == m - l) {
            if (s.empty()) {
                cout << "-1\n";
                return 0;
            }
            int y = *s.begin();
            s.erase(s.find(y));
            while (!s.empty()) {
                int z = *s.begin();
                s.erase(s.find(z));
                ans += z - a[i];
            }
            if (y != a[i]) s.insert(y);
        } else {
            while (!s.empty()) {
                int x = *s.begin();
                s.erase(s.find(x));
                ans += x - a[i];
            }
        }
    }
    if (!s.empty()) {
        cout << "-1\n";
        return 0;
    }
    cout << ans << '\n';
    return 0;
}