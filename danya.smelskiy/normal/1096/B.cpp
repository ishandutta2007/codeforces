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
string s;
int last_pos[200];
long long ans = 0;

int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = n; i > 0; --i) if (!last_pos[s[i] - 'a'])
        last_pos[s[i] - 'a'] = i;
    for (int i = 1; i <= n; ++i) {
        int r = i - 1;
        for (int j = 0; j < 26 ; ++j) {
            if (i == 1) {
                if (last_pos[j] != n) r = max(r, last_pos[j]);
            } else if (j != s[i - 1] - 'a') r = max(r, last_pos[j]);
        }
//  //      cout << r << '\n';
        ans += n - r + 1;
        if (i > 1 && s[i] != s[i - 1]) break;
    }
    ans %= 998244353;
    cout << ans << '\n';
}