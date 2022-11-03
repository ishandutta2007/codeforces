#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100;
const int max_k = 10;
const int max_a = 100;
const int max_sum = max_a * max_n * max_k + max_n * max_a + 222;
const int pos_null = max_n * max_a + 10;

int n, k;
int a[max_n], b[max_n];
int sum[max_sum], sum_swp[max_sum];
int f[max_sum], f_swp[max_sum];

//Sum(bi) * k - Sum(ai)

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    f[pos_null] = f_swp[pos_null] = 1;
    for (int i = 0; i < n; ++i) {
        int cur_sum = k * b[i] - a[i];
        for (int j = 0; j < max_sum; ++j)
            if (f[j]) {
                f_swp[j + cur_sum] = 1;
                sum_swp[j + cur_sum] = max(sum_swp[j + cur_sum], sum[j] + a[i]);
            }
        for (int j = 0; j < max_sum; ++j) {
            sum[j] = sum_swp[j];
            f[j] = f_swp[j];
        }
    }
    if (sum[pos_null] > 0) {
        cout << sum[pos_null] << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}