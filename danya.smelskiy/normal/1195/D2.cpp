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
const long long md = 998244353;


int n;
long long pw[100];
string s[100005];
int cnt[100];
long long ans;
int len[100005];
long long cur, x;

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    pw[0] = 1;
    for (int i = 1; i <= 36; ++i) {
        pw[i] = pw[i - 1] * 10ll;
        pw[i] %= md;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        len[i] = (int)s[i].size();
        ++cnt[len[i]];
    }
    for (int i = 1; i <= n; ++i) {
        int l = len[i];
        for (int j = 1; j <= l; ++j) {
            x = s[i][j - 1] - '0';
            for (int k = 1; k <= 10; ++k) {
                if (k < j) {
                    cur = pw[j + k - 1];
                    cur *= x;
                    cur *= cnt[k];
                    ans += cur;
                    ans += cur;
                } else {
                    cur = pw[j + j - 2];
                    cur *= x;
                    cur *= cnt[k];
                    ans += cur;
                    cur = pw[j + j - 1];
                    cur *= x;
                    cur *= cnt[k];
                    ans += cur;
                }
            }
        }
        ans %= md;
    }
    cout << ans << '\n';
    return 0;
}