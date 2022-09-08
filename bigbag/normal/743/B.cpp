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

const int max_n = 55, inf = 1011111111;

int n;
long long k, len[max_n];

int solve(int n, long long pos) {
    //cout << n << " " << pos << endl;
    if (n == 0) {
        return 1;
    }
    if (pos <= len[n - 1]) {
        return solve(n - 1, pos);
    }
    if (pos == 1 + len[n - 1]) {
        return n + 1;
    }
    return solve(n - 1, pos - len[n - 1] - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    len[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        len[i] = 2LL * len[i - 1] + 1;
    }
    cout << solve(54, k) << endl;
    return 0;
}