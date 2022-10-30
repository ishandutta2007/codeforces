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
int m;
int d[105][105];
int a[1000005];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            if (s[j - 1] == '1') d[i][j] = 1;
            else d[i][j] = 1e9;
        }
        d[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    int l = 1;
    vector<int> ans;
    ans.push_back(a[1]);
    for (int i = 2; i < m; ++i) {
        if (d[a[l]][a[i + 1]] != d[a[l]][a[i]] + d[a[i]][a[i + 1]]) {
            ans.push_back(a[i]);
            l = i;
        }
    }
    ans.push_back(a[m]);
    cout << (int)ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}