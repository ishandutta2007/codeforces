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

const int max_n = 1e3 + 1e2;

int n;
int a[max_n];
int dp[max_n][max_n], f[max_n][max_n];
int pr1[max_n][max_n], pr2[max_n][max_n];

void update(int& value, int& found, int& pr1, int& pr2, 
                int new_pr1, int new_pr2, int new_value) {
    if (!found || new_value < value) {
        value = new_value;
        found = 1;
        pr1 = new_pr1;
        pr2 = new_pr2;
    }
}

int main() {    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    update(dp[0][1], f[0][1], pr1[0][1], pr2[0][1], -1, -1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n + 10; ++j)
            if (f[i][j]) {
                if (j < n) 
                    update(dp[j + 1][j + 2], f[j + 1][j + 2], pr1[j + 1][j + 2], pr2[j + 1][j + 2],
                            i, j, dp[i][j] + max(a[i], a[j]));
                if (j + 1 < n)
                    update(dp[j][j + 2], f[j][j + 2], pr1[j][j + 2], pr2[j][j + 2],
                            i, j, dp[i][j] + max(a[i], a[j + 1]));
                if (j + 1 < n)
                    update(dp[i][j + 2], f[i][j + 2], pr1[i][j + 2], pr2[i][j + 2], 
                            i, j, dp[i][j] + max(a[j], a[j + 1]));
                if (j >= n)
                    update(dp[j][j + 1], f[j][j + 1], pr1[j][j + 1], pr2[j][j + 1],
                            i, j, dp[i][j] + a[i]);
            }
    }
    int val_ans = max_int;
    for (int i = n; i < max_n; ++i)
        for (int j = i + 1; j < max_n; ++j)
            if (f[i][j])
                val_ans = min(val_ans, dp[i][j]);
    cout << val_ans << endl;
    vector<pair<int, int> > ans;
    for (int i = n; i < max_n; ++i)
        for (int j = i + 1; j < max_n; ++j)
            if (f[i][j] && dp[i][j] == val_ans) {
                int c_pr1 = i;
                int c_pr2 = j;
                while (true) {
                    int n_pr1 = pr1[c_pr1][c_pr2];
                    int n_pr2 = pr2[c_pr1][c_pr2];
                    if (n_pr1 == -1 && n_pr2 == -1) break;
                    if (c_pr1 == n_pr2 + 1 && c_pr2 == n_pr2 + 2) {
                        ans.push_back(make_pair(n_pr1 + 1, n_pr2 + 1));
                    }
                    if (c_pr1 == n_pr2 && c_pr2 == n_pr2 + 2) {
                        ans.push_back(make_pair(n_pr1 + 1, c_pr2));
                    }
                    if (c_pr1 == n_pr1 && c_pr2 == n_pr2 + 2) {
                        ans.push_back(make_pair(n_pr2 + 1, c_pr2));
                    }
                    if (c_pr1 == n_pr2 && c_pr2 == n_pr2 + 1) {
                        ans.push_back(make_pair(n_pr1 + 1, 0));
                    }
                    c_pr1 = n_pr1;
                    c_pr2 = n_pr2;
                }
            }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i].first;
        if (ans[i].second) {
            cout << " " << ans[i].second;
        }
        cout << endl;
    }
    return 0;
}