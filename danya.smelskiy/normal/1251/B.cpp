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
int cnt[2];
int len[100];


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
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            len[i] = (int)s.size();
            for (int j = 0; j < s.size(); ++j)
                ++cnt[s[j] - '0'];
        }
        sort(len, len + n);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] & 1) {
                if ((cnt[0] & 1)) len[i]--, cnt[0]--;
                else if ((cnt[1] & 1)) len[i]--, cnt[1]--;
                else if (cnt[0]) len[i]--, cnt[0]--;
                else if (cnt[1]) len[i]--, cnt[1]--;
                else continue;
            }
            int x = cnt[0] / 2;
            int y = cnt[1] / 2;
            if ((x + y) * 2 < len[i]) continue;
            if (x + x >= len[i]) {
                ++res;
                cnt[0] -= len[i];
            } else {
                len[i] -= x + x;
                cnt[0] -= x + x;
                ++res;
                cnt[1] -= len[i];
            }
        }
        cout << res << '\n';
    }
    return 0;
}