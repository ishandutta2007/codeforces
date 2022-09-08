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

const int max_n = 1, mod = 1000000007;

long long f(long long n) {
    if (n == 1) {
        return 1;
    }
    long long result = n;
	for (int i = 2; 1LL * i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			result -= result / i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}
	return result;
}

long long solve(long long n, long long k) {
    //cout << n << " " << k << "#" << endl;
    if (k == 1) {
        return f(n);
    }
    if (k % 2) {
        return f(solve(n, k - 1));
    }
    return solve(n, k - 1);
}

long long n, k;

long long get_ans(long long n, long long k) {
    long long res = f(n);
    for (long long i = 3; i <= k; i += 2) {
        if (res == 1) {
            break;
        }
        res = f(res);
    }
    return res % mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    cout << get_ans(n, k) << endl;
    //cout << solve(n, k) << endl;
    return 0;
}