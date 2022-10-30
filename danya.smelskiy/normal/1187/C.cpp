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
int p[1005], ans[1005];
vector<pair<int, int> > q;

int get(int x) {
    if (x == p[x]) return x;
    return p[x] = get(p[x]);
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if (tp == 0) {
            q.push_back({l, r});
            continue;
        }
        for (int j = l + 1; j <= r; ++j) {
            int x = get(j);
            int y = get(l);
            if (x != y) p[x] = y;
        }
    }
    int last = n + 1;
    for (int i = 1; i <= n; ++i) {
        if (get(i) == i) --last;
        ans[i] = last;
    }
    for (int i = 0; i < (int)q.size(); ++i) {
        int l = q[i].first;
        int r = q[i].second;
        bool f = false;
        for (int j = l + 1; j <= r; ++j)
            if (ans[j - 1] > ans[j]) f = true;
        if (!f) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << '\n';
    return 0;
}