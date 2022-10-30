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
string s;
vector<int> v1, v2;
int dp[100005][2];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') v1.push_back(i);
        else v2.push_back(i);
    }
    if (v1.empty() || v2.empty() || v1.back() - v1[0] + 1 <= m || v2.back() - v2[0] + 1 <= m) {
        cout << "tokitsukaze\n";
        return 0;
    }
    if (m + m < n || v1.back() - v1[0] - 1 >= m || v2.back() - v2[0] - 1 >= m) {
        cout << "once again\n";
        return 0;
    }
    cout << "quailty\n";
    return 0;
}