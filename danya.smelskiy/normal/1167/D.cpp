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
string s;
string ans;
int q[200005];
int sz;
int lft[200005], rght[200005];

void solve(int l, int r, int xx) {
    if (l >= r) return;
    ans[l - 1] = ans[r - 1] = char('0' + xx);
    int ll = l + 1;
    while (ll < r) {
        int x = rght[ll];
        solve(ll, x, 1 - xx);
        ll = x + 1;
    }
    return;
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') q[++sz] = i;
        else {
            int x = q[sz];
            --sz;
            rght[x] = i;
            lft[i] = x;
        }
    }
    ans = "";
    for (int i = 1; i <= n; ++i)
        ans += "0";
    solve(1, n, 0);
    cout << ans << '\n';
}