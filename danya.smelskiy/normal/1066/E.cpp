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


int n, m;
string s1, s2;
long long p[200005];

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = m - 1; i >= 0; --i) {
        p[i] = p[i + 1];
        if (s2[i] == '1') ++p[i];
    }
    long long pw = 1;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '1') ans += (p[i] * pw) % md;
        pw += pw;
        if (pw >= md) pw -= md;
        if (ans >= md) ans -= md;
    }
    cout << ans << '\n';
}