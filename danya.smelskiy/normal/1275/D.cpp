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
long long v[1000005];
long long cnt[20005];
long long dp[20005];

inline vector<long long> get_divisors(long long c) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= c; ++i)
        if (c % i == 0) {
            divisors.push_back(i);
            if (i != c / i) divisors.push_back(c / i);
        }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

long long gcd(long long x, long long y) {
    while (x > 0 && y > 0) {
        if (x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    long long ans = 0;
    for (int i = 0; i < 10; ++i) {
        random_shuffle(v, v + n);
        long long c = v[0];

        vector<long long> div = get_divisors(c);
        int m = (int)div.size();
        map<long long, int> pos;
        for (int j = 0; j < div.size(); ++j)
            pos[div[j]] = j;
        
        for (int j = 0; j < m; ++j)
            cnt[j] = dp[j] = 0;
        for (int j = 0; j < n; ++j)
            ++cnt[pos[gcd(v[j], c)]];
        for (int j = 0; j < m; ++j) {
            for (int k = j; k < m; ++k) if (div[k] % div[j] == 0) {
                dp[j] += cnt[k];
            }
            if (dp[j] >= (n + 1) / 2 && div[j] > ans)
                ans = div[j];
        }
    }
    cout << ans << '\n';
    return 0;
}