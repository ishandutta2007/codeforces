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
int s1, s2, c;
int v1[500005];
int v2[500005];


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        s1 = 0, s2 = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '(') ++s2;
            else --s2;
            s1 = min(s1, s2);
        }
        if (s2 == 0) {
            if (s1 < 0) continue;
            ++c;
            continue;
        }
        if (s2 > 0) {
            if (s1 < 0) continue;
            v1[s2]++;
        } else {
            s2 = -s2;
            s1 = -s1;
            if (s1 <= s2) ++v2[s2];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 500000; ++i) ans += min(v1[i], v2[i]);
    ans += c/2;
    cout << ans << '\n';
}