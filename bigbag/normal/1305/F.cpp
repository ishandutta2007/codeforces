#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

const int max_p = 1000111;

int used[max_p];
vector<int> pr;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            pr.push_back(i);
            if (1LL * i * i < max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int n, ans;
long long a[max_n];
set<long long> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    if (0) {
        n = 200000;
        for (int i = 0; i < n; ++i) {
            a[i] = rnd();
        }
    } else {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%I64d", &a[i]);
        }
    }
    ans = n;
    for (int it = 0; it < 10; ++it) {
        int pos = rnd(n);
        for (int d = -1; d <= 1; ++d) {
            long long x = a[pos] + d;
            if (x == 0) {
                continue;
            }
            for (int p : pr) {
                if (x % p == 0) {
                    q.insert(p);
                    while (x % p == 0) {
                        x /= p;
                    }
                }
            }
            if (x > 1) {
                q.insert(x);
            }
        }
    }
    for (long long p : q) {
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < p) {
                res += p - a[i];
            } else {
                res += min(a[i] % p, p - a[i] % p);
            }
        }
        //cout << p << ": " << res << endl;
        ans = min(1LL * ans, res);
    }
    cout << ans << "\n";
    return 0;
}