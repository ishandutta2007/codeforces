#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
 
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;
 
typedef long long ll;

const int max_l = 15e4 + 100;

bool is_prime[max_l];
vector<int> primes;
vector<vector<int> > dels;
int min_del[max_l];
int p;

int bit(int mask, int i) {
    return (mask >> i) & 1;
}

int cnt_bits(int mask, int max_bit) {
    int ans = 0;
    for (int i = 0; i < max_bit; ++i)
        ans += bit(mask, i);
    return ans;
}

pair<int, int> find_sum_cnt(int dx, int l, int r) {
    int ans_sum = (1LL * (r - l + 1) * (l + r) / 2) % p;
    int ans_cnt = (r - l + 1) % p;
    int max_bit = dels[dx].size();
    for (int mask = 1; mask < (1 << max_bit); ++mask) {
        bool good_mask = true;
        for (int i = 1; i < max_bit; ++i)
            if (bit(mask, i) && !bit(mask, i - 1) && dels[dx][i - 1] == dels[dx][i]) {
                good_mask = false;
                break;
            }
        if (!good_mask) continue;
        
        int sign = (bit(cnt_bits(mask, max_bit), 0) == 0 ? 1 : -1);
        
        int d = 1;
        for (int j = 0; j < max_bit; ++j)
            if (bit(mask, j)) 
                d *= dels[dx][j];
        
        int temp1, temp2;
        
        temp1 = l / d;
        if (temp1 * d < l) ++temp1;
        temp2 = r / d;
        if (temp2 < temp1) continue;
        
        int cur_cnt = (temp2 - temp1 + 1) % p;
        int cur_sum = (1LL * (temp1 + temp2) * d * cur_cnt / 2) % p;
        
        ans_sum += sign * cur_sum;
        if (ans_sum < 0) ans_sum += p;
        if (ans_sum >= p) ans_sum -= p;
        
        ans_cnt += sign * cur_cnt;
        if (ans_cnt < 0) ans_cnt += p;
        if (ans_cnt >= p) ans_cnt -= p;
    }
    return make_pair(ans_sum, ans_cnt);
}

int find_answer(int n, int m, int l, int r) {
    int ans = 0;
    for (int dx = 1; dx <= min(n, r); ++dx) {
        ll cur_l2 = 1LL * l * l - 1LL * dx * dx;
        if (cur_l2 < 0) { cur_l2 = 1; }
        ll cur_r2 = min(1LL * m * m, 1LL * r * r - 1LL * dx * dx);
        
        int cur_l = sqrt(cur_l2);
        if (1LL * cur_l * cur_l < cur_l2) ++cur_l;
        cur_l = max(cur_l, 1); 
        int cur_r = sqrt(cur_r2);

        if (cur_l > cur_r) continue;
        
        pair<int, int> sum_cnt = find_sum_cnt(dx, cur_l, cur_r);
        
        int sum = sum_cnt.first;
        int cnt = sum_cnt.second;
        
        int all_sum = (1LL * cnt * (m + 1)) % p;
        
        int diff_sum = all_sum - sum;
        if (diff_sum < 0) diff_sum += p;
     
        ans = ans + (1LL * (n - dx + 1) * diff_sum) % p;
        if (ans >= p) ans -= p;
    }
    ans += ans;
    if (ans >= p) ans -= p;
    if (l == 1) {
        ans += (1LL * (n + 1) * m) % p;
        if (ans >= p) ans -= p;
        ans += (1LL * n * (m + 1)) % p;
        if (ans >= p) ans -= p;
    }
    return ans;
}

int main() {
 //   freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    for (int i = 0; i < max_l; ++i)
        is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < max_l; ++i)
        if (is_prime[i])
            for (int j = i * i; j < max_l; j += i)
                is_prime[j] = false;
    for (int i = 0; i < max_l; ++i)
        if (is_prime[i])
            primes.push_back(i);
    for (int i = 2; i < max_l; ++i)
        if (is_prime[i]) {
            min_del[i] = i;
        } else {
            for (int j = 2; j * j <= i; ++j)
                if (i % j == 0) {
                    min_del[i] = j;
                    break;
                }
        }
        
    dels.resize(max_l + 1);
    for (int i = 1; i < max_l; ++i) 
        for (int j = i; j > 1; ) {
            dels[i].push_back(min_del[j]);
            int d = min_del[j];
            while (j % d == 0) {
                j /= d;
            }
        }
    
    int n, m, l, r;
    while (scanf("%d%d%d%d%d", &n, &m, &l, &r, &p) != EOF) {
        printf("%d\n", find_answer(n, m, l, r));
    }
    
    return 0;
}