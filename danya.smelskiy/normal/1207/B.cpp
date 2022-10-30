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
int a[500][500];
int b[500][500];
vector<pair<int, int> > ans;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1] == 4) {
                ans.push_back({i, j});
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != b[i][j]) {
                cout << "-1\n";
                return 0;
            }
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}