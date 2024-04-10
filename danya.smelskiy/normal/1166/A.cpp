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
long long ans;
int cnt[100];

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        ++cnt[x];
    }
    for (int i = 0; i < 26; ++i) {
        int cur = 1e9;
        for (int j = 0; j <= cnt[i]; ++j) {
            int x = j;
            int y = cnt[i] - j;
            int z = 0;
            z += (x * (x - 1)) / 2;
            z += (y * (y - 1)) / 2;
            cur = min(cur, z);
        }
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}