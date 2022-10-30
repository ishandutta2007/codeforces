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
int a[400005];
vector<int> v;
int lp[3750145];
int cnt[3750145];

void init() {
    int mx = 2750131;
    for (int i = 2; i * i <= mx; ++i) if (!lp[i]) {
        lp[i] = i;
        for (int j = i + i; j <= mx; j += i) {
            if (!lp[j] || lp[j] > i) lp[j] = i;
        }
        v.push_back(i);
    }
    for (int i = 2; i <= mx; ++i)
        if (!lp[i]) {
            lp[i] = i;
            v.push_back(i);
        }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    n += n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a + 1, a + n + 1);
    init();
    int x;
    vector<int> ans;
    for (int i = n; i > 0; --i) {
        x = a[i];
        if (lp[x] == x || !cnt[x]) continue;
        --cnt[x];
        ans.push_back(x);
        x /= lp[x];
        --cnt[x];
    }
    for (int i = 1; i <= n; ++i) {
        x = a[i];
        if (lp[x] != x || !cnt[x]) continue;
        --cnt[x];
        ans.push_back(x);
        x = v[x - 1];
        --cnt[x];
    }
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}