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
int a[200005];
int cnt[200005];

bool f(int mid) {
    long long ans = 0;
    for (int i = 0; i < mid; ++i) {
        cnt[i] = 0;
    }
    int last = 0;
    for (int i = n; i > 0; --i) {
        if (a[i] > cnt[last]) {
            ans += a[i] - cnt[last];
            ++cnt[last];
            ++last;
            if (last == mid) last = 0;
        }
    }
    return (ans >= m);
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1;
    int r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (f(mid)) r = mid;
        else l = mid + 1;
    }
    if (f(l)) cout << l << '\n';
    else cout << "-1\n";
    
}