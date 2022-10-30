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


int n, m, k;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int k = min(n, m);
        int x = 5e5, y = 5e5;
        vector<pair<int, int> > ans;
        for (int i = 1; i <= k + k; ++i)
            ans.push_back({x, y + i - 1});
        n -= k;
        m -= k;
        if (m == 0) {
            int c = (int)ans.size();
            for (int i = 0; i < c && n > 0; ++i) {
                int x = ans[i].first;
                int y = ans[i].second;
                if ((x + y) % 2 == 0) {
                    --n;
                    ans.push_back({x - 1, y});
                    if (n) {
                        --n;
                        ans.push_back({x + 1, y});
                    }
                    if (n && i == 0) {
                        ans.push_back({x, y - 1});
                        --n;
                    }
                    if (n && i == c -1 ) {
                        --n;
                        ans.push_back({x, y + 1});
                    }
                }
            }
        } else {
            int c = (int)ans.size();
            swap(n, m);
            for (int i = 0; i < c && n > 0; ++i) {
                int x = ans[i].first;
                int y = ans[i].second;
                if ((x + y) % 2 == 1) {
                    --n;
                    ans.push_back({x - 1, y});
                    if (n) {
                        --n;
                        ans.push_back({x + 1, y});
                    }
                    if (n && i == 0) {
                        ans.push_back({x, y - 1});
                        --n;
                    }
                    if (n && i == c -1 ) {
                        --n;
                        ans.push_back({x, y + 1});
                    }
                }
            }
        }
        if (n + m) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < (int)ans.size(); ++i)
            cout << ans[i].first << " " << ans[i].second << '\n';
    }
    return 0;
}