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

const int max_n = 62, inf = 1011111111;
const int dp[] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

int n;
int tm, f[max_n];
map<pair<int, long long>, int> q;

bool get_bit(long long mask, int pos) {
    return (bool) (mask & (1LL << pos));
}

void get_dp(int x, long long mask) {
    pair<int, long long> p = make_pair(x, mask);
    if (q.count(p)) {
        return;
    }
    for (int i = 1; i <= x; ++i) {
        if (!get_bit(mask, i)) {
            get_dp(x - i, mask | (1LL << i));
        }
    }
    ++tm;
    for (int i = 1; i <= x; ++i) {
        if (!get_bit(mask, i)) {
            f[q[make_pair(x - i, mask | (1LL << i))]] = tm;
        }
    }
    for (int i = 0; ; ++i) {
        if (i == 61) {
            cout << "FAIL" << endl;
            exit(0);
        }
        if (f[i] != tm) {
            q[p] = i;
            return;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*for (int i = 1; i <= 60; ++i) {
        get_dp(i, 0);
        dp[i] = q[make_pair(i, 0)];
        cout << dp[i] << ", ";
    }*/
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        ans ^= dp[x];
    }
    if (ans) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}