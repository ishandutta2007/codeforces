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

const int max_n = 555, max_p = 33333, inf = 1000000007;

int used[max_p];
vector<int> p;

void get_all_prime() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            p.push_back(i);
            for (int j = 2; i * j < max_p; ++j) {
                used[i * j] = 1;
            }
        }
    }
}

struct very_long1 {
    int cnt[2 * max_p];
    very_long1() {
        memset(cnt, 0, sizeof(cnt));
    }
    void operator = (int x) {
        if (x == 1) {
            ++cnt[1];
            return;
        }
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                ++cnt[p[i]];
            }
        }
        if (x != 1) {
            ++cnt[x];
        }
    }
    void operator *= (int x) {
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                ++cnt[p[i]];
            }
        }
        if (x != 1) {
            ++cnt[x];
        }
    }
    void operator /= (int x) {
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            int q = 0;
            while (x % p[i] == 0) {
                x /= p[i];
                --cnt[p[i]];
            }
        }
        if (x != 1) {
            --cnt[x];
        }
    }
};

long long step(long long a, int b, long long mod) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a % mod;
    }
    if (b % 2 == 0) {
        return step(a * a, b / 2, mod) % mod;
    }
    return (a * step(a, b - 1, mod)) % mod;
}

long long very_long1_to_long_long_mod(very_long1 x, long long mod) {
    long long res = 1;
    for (int i = 2; i < 2 * max_p; ++i) {
        if (x.cnt[i] != 0) {
            res = (res * step(i, x.cnt[i], mod)) % mod;
        }
    }
    return res % mod;
}

long long get_cnk_mod(int n, int k, long long mod) {
    very_long1 C;
    C = 1;
    for (int i = k + 1; i <= n; ++i) {
        C *= i;
    }
    for (int i = 2; i <= n - k; ++i) {
        C /= i;
    }
    //cout << n << ' ' << k << "  -  " << very_long1_to_long_long_mod(C, mod) % mod << endl;
    return very_long1_to_long_long_mod(C, mod) % mod;
}

int n;
set<int> s;
map<int, int> m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_prime();
    cin >> n;
    long long res = 1;
    for (int q = 0; q < n; ++q) {
        int x;
        cin >> x;
        for (int i = 0; p[i] * p[i] <= x; ++i) {
            if (x % p[i] == 0) {
                s.insert(p[i]);
                while (x % p[i] == 0) {
                    x /= p[i];
                    ++m[p[i]];
                }
            }
        }
        if (x != 1) {
            s.insert(x);
            ++m[x];
        }
    }
    while (s.size() != 0) {
        int x = *s.begin();
        s.erase(x);
        res = (res * get_cnk_mod(m[x] + n - 1, n - 1, inf)) % inf;
    }
    cout << res % inf << endl;
    return 0;
}