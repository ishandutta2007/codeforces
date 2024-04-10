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
int ans = 1e9;
string s1;

inline int solve(string x) {
    int res = 0;
    string z = s;
    for (int i = 0; i < n; ++i) {
        int y = i % 3;
        if (s[i] != x[y]) ++res;
        z[i] = x[y];
    }
    if (res < ans) {
        ans = res;
        s1 = z;
    }
    return res;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    solve("RGB");
    solve("RBG");
    solve("BRG");
    solve("BGR");
    solve("GRB");
    solve("GBR");
    cout << ans << '\n';
    cout << s1 << '\n';
}