#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 202222, inf = 1011111111;

int n, m, f[max_n], dp[max_n];
vector<int> all[max_n], x, ans;

int gcd(int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    while (n--) {
        int x;
        scanf("%d", &x);
        f[x] = 1;
    }
    for (int i = 1; i < m; ++i) {
        if (f[i] == 0) {
            all[__gcd(i, m)].push_back(i);
        }
    }
    for (int i = m - 1; i > 0; --i) {
        for (int j = 2 * i; j < m; j += i) {
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += all[i].size();
    }
    pair<int, int> mx = make_pair(-1, -1);
    for (int i = 1; i < m; ++i) {
        mx = max(mx, make_pair(dp[i], i));
    }
    int pos = mx.second;
    if (pos != -1 && all[pos].size()) {
        while (true) {
            //cout << pos << endl;
            for (int j = 0; j < all[pos].size(); ++j) {
                x.push_back(all[pos][j]);
            }
            int to = -1;
            for (int j = 2 * pos; j < m; j += pos) {
                if (dp[pos] == all[pos].size() + dp[j]) {
                    to = j;
                    break;
                }
            }
            if (to == -1) {
                break;
            }
            pos = to;
        }
    }
    if (x.size()) {
        ans.push_back(x[0]);
        for (int i = 1; i < x.size(); ++i) {
            int k1, k2;
            int g = gcd(x[i - 1], m, k1, k2);
            long long k = k1;
            if (k < 0) {
                k += (1LL * x[i - 1] * m) / g;
            }
            k %= m;
            if (x[i] % g) {
                while (1);
            }
            k *= x[i];
            k /= g;
            k %= m;
            //cout << x[i - 1] << " -> " << x[i] << "   " << k1 << " " << k2 << "   g = " << g << endl;
            ans.push_back(k);
        }
    }
    if (f[0] == 0) {
        ans.push_back(0);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}