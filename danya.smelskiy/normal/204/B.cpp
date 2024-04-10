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
map<int, int> cnt, cnt2;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int ans = 1e9;
    int x, y;
    int m = (n + 1) / 2;
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        ++cnt[x];
        if (x != y) ++cnt[y], ++cnt2[y];
        v.push_back(x);
        v.push_back(y);
    }
    for (int i = 0; i < v.size(); ++i) {
        x = v[i];
        if (cnt[x] >= m) {
            if (cnt[x] - cnt2[x] >= m) ans = 0;
            else ans = min(ans, m - (cnt[x] - cnt2[x]));
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
    
}