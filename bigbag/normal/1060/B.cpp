#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

long long sum(long long x) {
    long long res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

long long triv(long long n) {
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, sum(i) + sum(n - i));
    }
    return ans;
}

long long solve(long long n) {
    long long x = 0;
    while (x * 10 + 9 <= n) {
        x = x * 10 + 9;
    }
    return sum(x) + sum(n - x);
}

long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}