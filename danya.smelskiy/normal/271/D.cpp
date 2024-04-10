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
string s, bl;
vector<int> p;

inline bool cmp(int x, int y) {
    while (x < n && y < n) {
        if (s[x] != s[y]) return s[x] < s[y];
        ++x;
        ++y;
    }
    return (x == n);
}

int get_lcp(int x, int y) {
    int res = 0;
    int l = x;
    int r = y;
    while (l < n && r < n && s[l] == s[r]) {
        ++res;
        ++l;
        ++r;
    }
    return res;
}

int add(int x, int y) {
    int res = 0;
    y = x + y;
    int cur = 0;
    for (int i = x; i < y; ++i)
        if (bl[(s[i] - 'a')] == '0') ++cur;
    for (int i = y; i < n; ++i) {
        if (bl[(s[i] - 'a')] == '0') ++cur;
        if (cur <= m) ++res;
    }
    return res;
}


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    cin >> bl;
    cin >> m;
    n = (int)s.size();
    for (int i = 0; i < n; ++i)
        p.push_back(i);
    sort(p.begin(), p.end(), cmp);
    int x = p[0];
    int ans = add(x, 0);
    for (int i = 1; i < n; ++i) {
        ans += add(p[i], get_lcp(p[i - 1], p[i]));
    }
    cout << ans << '\n';
}