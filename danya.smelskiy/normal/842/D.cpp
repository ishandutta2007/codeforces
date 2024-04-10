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


int n, m, all;
int cnt[2000005];
int nxt[2000005][2];
int res;


void add(int x, int y, int z) {
    if (z < 0) {
        cnt[x] = 1;
        return;
    }
    int xx = 0;
    if (y & (1 << z)) xx = 1;
    if (!nxt[x][xx]) nxt[x][xx] = ++all;
    add(nxt[x][xx], y, z - 1);
    cnt[x] = 0;
    if (nxt[x][0]) cnt[x] += cnt[nxt[x][0]];
    if (nxt[x][1]) cnt[x] += cnt[nxt[x][1]];
    return;
}

void get(int x, int y, int z) {
    if (z < 0) return;
    int xx = 0;
    if (y & (1 << z)) xx = 1;
    if (!nxt[x][xx]) nxt[x][xx] = ++all;
    int yy = (1 << z) - cnt[nxt[x][xx]];
    if (yy) {
        if (xx) res ^= (1 << z);
        get(nxt[x][xx], y, z - 1);
    } else {
        xx = 1 - xx;
        if (xx) res ^= (1 << z);
        if (!nxt[x][xx]) nxt[x][xx] = ++all;
        get(nxt[x][xx], y, z - 1);
    }
    return;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        add(0, x, 18);
    }
    res = 0;
    int last = 0;
    while (m--) {
        int x;
        cin >> x;
        last ^= x;
        res = 0;
        get(0, last, 18);
        res ^= last;
        cout << res << '\n';
    }
}