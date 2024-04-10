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
vector<long long> ans;
map<long long, bool> used;

void check(long long x) {
    long long z = (n / x);
    long long res = z - 1ll;
    res *= (z);
    res /= 2ll;
    res *= x;
    res += z;
    if (!used.count(res)) {
        used[res] = true;
        ans.push_back(res);
    }
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1;i * i <= n; ++i)
        if (n % i == 0) {
            check(i);
            check(n / i);
        }
    sort(ans.begin(), ans.end());
    for (int i = 0;i < ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
}