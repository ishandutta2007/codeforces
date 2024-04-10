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
bool used[300005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    int x, y;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n * 3; ++i)
            used[i] = false;
        vector<int> ans;
        for (int i = 1; i <= m; ++i) {
            cin >> x >> y;
            if (!used[x] && !used[y]) {
                ans.push_back(i);
                used[x] = true;
                used[y] = true;
            }
        }
        if ((int)ans.size() >= n) {
            cout << "Matching\n";
            for (int i = 0; i < n; ++i)
                cout << ans[i] << " ";
            cout << '\n';
        } else {
            cout << "IndSet\n";
            int c = 0;
            for (int i = 1; i <= n + n + n && c < n; ++i) if (!used[i]) {
                ++c;
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}