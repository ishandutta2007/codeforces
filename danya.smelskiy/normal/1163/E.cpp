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

void solve(int x) {
    int y = (1 << x) - 1;
    vector<int> b, q;
    for (int i = 1; i <= n && a[i] <= y; ++i) {
        int cur = a[i];
        for (int j = 0; j < (int)b.size(); ++j)
            if ((b[j] ^ cur) < cur) cur ^= b[j];
        if (cur) {
            b.push_back(cur);
            sort(b.begin(), b.end());
            reverse(b.begin(), b.end());
            q.push_back(a[i]);
        }
    }
    if ((int)b.size() != x) return;
    cout << x << '\n';
    for (int i = 0; i <= y; ++i) {
        int c = (i ^ (i >> 1));
        int cur = 0;
        for (int j = 0; j < x; ++j)
            if ((c & (1 << j))) cur ^= q[j];
        cout << cur << " ";
    }
    cout << '\n';
    exit(0);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 19; i >= 0; --i)
        solve(i);
    return 0;
}