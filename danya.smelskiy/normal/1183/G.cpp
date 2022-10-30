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
pair<int, int> c[200005];
vector<int> q[200005];
int cc[200005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            c[i] = {0, 0}, cc[i] = 0;
            q[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            ++c[x].first;
            c[x].second += y;
        }
        sort(c + 1, c + n + 1);
        int last = 1e9;
        long long ans1 = 0, ans2 = 0;
        for (int i = n; i > 0; --i) {
            last = max(last - 1, 0);
            last = min(last, c[i].first);
            q[c[i].first].push_back(c[i].second);
            ans1 += last;
            ++cc[last];
        }
        multiset<long long> s;
        for (int i = n; i > 0; --i) {
            for (int j = 0; j < (int)q[i].size(); ++j)
                s.insert(q[i][j]);
            while (cc[i]--) {
                int x = *s.rbegin();
                s.erase(s.find(x));
                ans2 += min(x, i);
            }
        }
        cout << ans1 << " " << ans2 << '\n';
    }
    return 0;
}