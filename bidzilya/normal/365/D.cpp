#include <cstdio>
#include <cmath>

#include <queue>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

typedef long long ll;

const int max_n = 50;
const int max_d = 1e4 + 100;
const int max_sum = max_n * max_d;

int n, d;
int sum[max_sum];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    sum[0] = 1;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        for (int i = max_sum - 1; i >= 0; --i)
            if (sum[i] && i + c < max_sum)
                sum[i + c] = 1;
    }
    int ans_sum = 0;
    int ans_step = 0;
    while (true) {
        int new_ans_sum = ans_sum;
        for (int i = ans_sum + 1; i <= min(ans_sum + d, max_sum - 1); ++i)
            if (sum[i])
                new_ans_sum = i;
        if (new_ans_sum == ans_sum) break;
        ans_sum = new_ans_sum;
        ++ans_step;
    }
    cout << ans_sum << " " << ans_step << endl;
    return 0;
}