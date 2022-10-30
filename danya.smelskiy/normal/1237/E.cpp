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
int sz, all;
int lft[1000005];
int rght[1000005];
int clr[1000005];
int cnt[1000005];
int val[1000005];
bool is_ans;

void add(int x, int y) {
    if (lft[x]) {
        if (cnt[lft[x]]) {
            add(lft[x], y);
            cnt[x] = cnt[lft[x]] + cnt[rght[x]] + (val[x] == 0);
        } else if (!val[x]) {
            val[x] = y;
            if (y % 2 != clr[x]) is_ans = false;
            cnt[x] = cnt[lft[x]] + cnt[rght[x]];
        } else if (cnt[rght[x]]) {
            add(rght[x], y);
            cnt[x] = cnt[lft[x]] + cnt[rght[x]] + (val[x] == 0);
        } else {
            is_ans = false;
        }
    } else {
        if (clr[x] == y % 2) {
            val[x] = y;
            cnt[x] = 0;
        } else {
            lft[x] = ++all;
            clr[all] = 1 - clr[x];
            cnt[all] = 0;
            val[all] = y;
        }
        return;
    }
}

void solve(int x) {
    memset(cnt, 0, sizeof(cnt));
    memset(clr, 0, sizeof(clr));
    memset(lft, 0, sizeof(lft));
    memset(rght, 0, sizeof(rght));
    memset(val, 0, sizeof(val));
    sz = 0;
    while (((1 << (sz + 1)) - 1) <= n) ++sz;
    all = (1 << sz) - 1;
    int all2 = all;
    clr[1] = x;
    for (int i = 1; i <= all; ++i) {
        val[i] = 0;
        if (i <= all / 2) {
            lft[i] = i + i;
            clr[i + i] = 1 - clr[i];
            rght[i] = i + i + 1;
            clr[i + i + 1] = clr[i];
        } else {
            cnt[i] = 1;
        }
    }
    for (int i = all / 2; i > 0; --i)
        cnt[i] = cnt[i + i] + cnt[i + i + 1] + 1;
    is_ans = true;
    for (int i = 1; i <= n && is_ans; ++i)
        add(1, i);
    for (int i = 1; i <= all2; ++i)
        if (!val[i]) return;
    if (is_ans) {
        cout << 1 << '\n';
        exit(0);
    }
}

int main(int argc, const char * argv[]) {
#ifdef __APPLE__
    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    solve(1);
    solve(0);
    cout << 0 << '\n';
    return 0;
}