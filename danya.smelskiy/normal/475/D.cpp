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



map<int, long long> cnt;
pair<int, int> q[100];
int n, x, m, sz, y;

int gcd(int x, int y) {
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int szz;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        q[++sz] = {x, i};
        for (int i = sz; i > 0; --i) {
            y = gcd(q[i].first, x);
            q[i].first = y;
        }
        szz = 0;
        for (int i = 1; i <= sz; ++i)
            if (i == 1 || q[i].first != q[i - 1].first) q[++szz] = q[i];
        sz = szz;
        cnt[q[sz].first] += i - q[sz].second + 1;
        for (int i = sz - 1; i > 0; --i)
            cnt[q[i].first] += q[i + 1].second - q[i].second;
    }
    cin >> m;
    while (m--) {
        cin >> x;
        cout << cnt[x] << '\n';
    }

}