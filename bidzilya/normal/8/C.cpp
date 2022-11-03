#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 24;
const int max_mask_n = (1 << 24);

int bit(int mask, int i) {
    return ((mask >> i) & 1);
}

int n;
int xs, ys;
int x[max_n], y[max_n];
int dp[max_mask_n], f[max_mask_n], pr[max_mask_n];
int max_mask, full_mask;
int r[max_n + 1][max_n + 1];

void relax(int& val, int& fnd, int& pr, int nval, int npr) {
    if (!fnd || nval < val) {
        fnd = 1;
        val = nval;
        pr = npr;
    }
}

int main() { 
    cin >> xs >> ys >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= n; ++i)
        r[0][i] = r[i][0] = (xs - x[i - 1]) * (xs - x[i - 1]) + 
                        (ys - y[i - 1]) * (ys - y[i - 1]);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            r[i][j] = (x[i - 1] - x[j - 1]) * (x[i - 1] - x[j - 1]) + 
                        (y[i - 1] - y[j - 1]) * (y[i - 1] - y[j - 1]);
    f[0] = 1;
    pr[0] = -1;
    max_mask = (1 << n);
    full_mask = max_mask - 1;
    for (int mask = 0; mask < max_mask; ++mask) {
        if (!f[mask]) continue;
        for (int i = 0; i < n; ++i)
            if (!bit(mask, i)) {
                int nmask = mask + (1 << i);
                relax(dp[nmask], f[nmask], pr[nmask], dp[mask] + 2 * r[0][i + 1], mask);
                for (int j = i + 1; j < n; ++j)
                    if (!bit(mask, j)) {
                        nmask = mask + (1 << i) + (1 << j);
                        relax(dp[nmask], f[nmask], pr[nmask],
                            dp[mask] + r[0][i + 1] + r[i + 1][j + 1] + r[0][j + 1], mask);
                    }
                break;
            }
    }
    int ans_mask = -1, ans_val;
    for (int mask = 0; mask < max_mask; ++mask)
        if (f[mask]) {
            int c_val = dp[mask];
            for (int j = 0; j < n; ++j)
                if (!bit(mask, j)) {
                    c_val += 2 * r[0][j + 1];
                }
            if (ans_mask == -1 || c_val < ans_val) {
                ans_val = c_val;
                ans_mask = mask;
            }
        }
    cout << ans_val << endl;
    vector<int> ans;
    ans.push_back(0);
    for (int i = 0; i < n; ++i)
        if (!bit(ans_mask, i)) {
            ans.push_back(i + 1);
            ans.push_back(0);
        }
    for (int mask = ans_mask; mask > 0; mask = pr[mask]) {
        int nmask = pr[mask];
        for (int i = 0; i < n; ++i)
            if (bit(mask, i) != bit(nmask, i))
                ans.push_back(i + 1);
        ans.push_back(0);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); ++i)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}