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

inline bool check(int x) {
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

void solve(int n) {
    vector<pair<int, int> > res;
    for (int i = 1; i < n; ++i)
        res.push_back({i, i + 1});
    res.push_back({1, n});
    int c = n;
    int last = 1;
    while (!check(c)) {
        res.push_back({last, last + 2});
        if ((last & 1)) ++last;
        else last += 3;
        ++c;
    }
    if (last > n) {
        exit(0);
        return;
    }
    cout << (int)res.size() << '\n';
    for (int i = 0; i < (int)res.size(); ++i)
        cout << res[i].first << " " << res[i].second << '\n';
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    solve(n);
    return 0;
}