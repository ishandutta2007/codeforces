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
int a[300005];
vector<int> v[300005];
int x, y;
bool used[300005];
int all;
int ans;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
    }
    used[a[n]] = true;
    all = 1;
    for (int i = n - 1; i > 0; --i) {
        bool tt = false;
        int x = a[i];
        int c = 0;
        for (int j = 0; j < v[x].size(); ++j) {
            int to = v[x][j];
            if (used[to]) ++c;
            if (to == a[n]) tt = true;
        }
        if (c < all) {
            used[x] = true;
            ++all;
        } else ++ans;
    }
    cout << ans << '\n';
}