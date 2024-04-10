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
long long a[100005], p[100005];
long long ans;
int cnt[4000005];
int nxt[4000005][2];
int all;

void add(long long x, int y) {
    int last = 0;
    for (long long i = 40; i >= 0; --i) {
        int z;
        cnt[last] += y;
        if (x & (1ll << i)) z = 1;
        else z = 0;
        if (!nxt[last][z]) nxt[last][z] = ++all;
        last = nxt[last][z];
    }
    cnt[last] += y;
    return;
}

long long get(long long x) {
    int last = 0;
    for (long long i = 40; i >= 0; --i) {
        int z;
        if (x & (1ll << i)) z = 0;
        else z = 1;
        if (nxt[last][z] && cnt[nxt[last][z]]) {
            x |= (1ll << i);
            last = nxt[last][z];
        } else {
            last = nxt[last][1 - z];
            if (z == 0) x ^= (1ll << i);
        }
    }
    return x;
}

int main(int argc, const char * argv[]) {
//   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    add(0, 1);
    for (int i = n; i > 0; --i) {
        p[i] = (p[i + 1] ^ a[i]);
        add(p[i], 1);
    }
    ans = get(0);
    long long last = 0;
    for (int i = 1; i <= n; ++i) {
        add(p[i], -1);
        last ^= a[i];
        ans = max(ans, get(last));
    }
    cout << ans << '\n';
}