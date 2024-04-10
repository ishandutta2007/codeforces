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
int a[200005];
map<int, int> cnt;
long long ans = 0;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    unsigned long long s1 = 0, s2 = 0;
    unsigned long long s = 0;
    for (int i = n; i > 0; --i) {
        int x = a[i];
        long long ss = s - (cnt[x] * 1ll * x) - (cnt[x + 1] * 1ll * (x + 1)) - (cnt[x - 1] * 1ll * (x - 1));
        s1 += ss;
        int cc = n - i - cnt[x] - cnt[x + 1] - cnt[x - 1];
        s2 += cc * 1ll * x;
        s += x;
        ++cnt[x];
    }
    if (s1 < s2) {
        s2 -= s1;
        cout << "-" << s2 << '\n';
    } else cout << s1 - s2 << '\n';
}