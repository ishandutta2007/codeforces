/**
 *  task: https://codeforces.com/contest/1033/problem/D
 *  author: https://codeforces.com/profile/BigBag
 *  created: 21.09.2020
**/

#include <bits/stdc++.h>

using namespace std;

class Factorizer {
public:
    Factorizer(): generator(time(0)) {
        memset(d, 0, sizeof(d));
        for (int i = 2; i < max_p; ++i) {
            if (!d[i]) {
                d[i] = i;
                for (long long j = 1LL * i * i; j < max_p; j += i) {
                    if (!d[j]) {
                        d[j] = i;
                    }
                }
            }
        }
    }

    static long long mul(long long a, long long b, long long mod) {
        long long x = (long double) a * b / mod;
        long long y = (a * b - x * mod) % mod;
        return y < 0 ? y + mod : y;
    }

    static long long power(long long a, long long b, long long mod) {
        long long res = 1 % mod;
        while (b) {
            if (b % 2) {
                res = mul(res, a, mod);
            }
            b /= 2;
            a = mul(a, a, mod);
        }
        return res;
    }

    static bool is_prime(long long x) {
        for (int val : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
            if (x == val) {
                return true;
            }
            if (!miller_simple(x, val)) {
                return false;
            }
        }
        return true;
    }

    vector<long long> factorize(long long x) {
        vector<long long> res;
        factorize(x, res);
        sort(res.begin(), res.end());
        return res;
    }

private:
    static const int max_p = 1000000;

    int d[max_p];
    mt19937_64 generator;
    vector<long long> p;

    static bool miller_simple(long long a, long long b) {
        long long c = a - 1;
        int k = __builtin_ctzll(c);
        c >>= k;

        b = power(b, c, a);
        if (b == 1) {
            return true;
        }
        for (int i = 0; i < k; ++i) {
            if (b + 1 == a) {
                return true;
            }
            b = mul(b, b, a);
        }
        return false;
    }

    long long polard_rho(long long a) {
        const int max_v = 25;
        while (true) {
            long long p0 = generator() % a;
            long long p1 = p0;
            long long c = generator() % a;
            long long ans = 1;
            int t = 0;
            int pos = 0;
            vector<long long> arr{p1};

            while (true) {
                for (int i = 0; i < 2; ++i) {
                    p1 = mul(p1, p1, a) + c;
                    if (p1 >= a) {
                        p1 -= a;
                    }
                    arr.push_back(p1);
                }
                p0 = arr[pos++];
                if (p0 == p1) {
                    break;
                }
                ans = mul(ans, llabs(p1 - p0), a);
                if (ans == 0) {
                    return __gcd(llabs(p1 - p0), a);
                }
                if ((++t) == max_v) {
                    t = 0;
                    ans = __gcd(ans, a);
                    if (ans > 1 && ans < a) {
                        return ans;
                    }
                }
            }

            ans = __gcd(ans, a);
            if (ans > 1 && ans < a) {
                return ans;
            }
        }
    }

    void factorize(long long a, vector<long long> &res) {
        while (a > 1 && a < max_p) {
            res.push_back(d[a]);
            a /= d[a];
        }
        for (long long x : p) {
            if (a % x == 0) {
                a /= x;
                res.push_back(x);
            }
        }
        if (a < 2) {
            return;
        }
        if (is_prime(a)) {
            p.push_back(a);
            res.push_back(a);
        } else {
            long long d = polard_rho(a);
            assert(d > 1 && d < a);
            factorize(d, res);
            factorize(a / d, res);
        }
    }
};

Factorizer f;

const int mod = 998244353;

int n;
map<int, int> cnt;

int main() {
    cin >> n;
    while (n--) {
        long long a;
        cin >> a;
        for (long long x : f.factorize(a)) {
            ++cnt[x];
        }
    }
    int ans = 1;
    for (const auto &p : cnt) {
        ans = f.mul(ans, p.second + 1, mod);
    }
    cout << ans << endl;
    return 0;
}