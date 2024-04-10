/**
 *  created: 25/12/2020, 16:52:30
**/

#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define fir first
#define sec second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

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

    static bool is_prime(long long x) { // works for x <= 3.8 * 10^18
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

const int max_n = 1011, inf = 1000111222;

int n, k;
long long x[max_n];

void write(vector<long long> ans) {
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    if (k == 1) {
        puts("0");
        return 0;
    }
    vector<long long> ans, not_p;
    vector<pair<long long, long long>> ps;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        auto v = f.factorize(x[i]);
        if (v[0] == v.back()) {
            ps.push_back({v[0], x[i]});
        } else {
            not_p.push_back(x[i]);
        }
    }
    sort(ps.begin(), ps.end());
    vector<long long> diff;
    vector<pair<long long, vector<long long>>> ans_p;
    int tot_p = 0;
    for (int i = 0; i < ps.size(); ) {
        int pos = i;
        while (i < ps.size() && ps[i].first == ps[pos].first) {
            ++i;
        }
        if (i - pos > 1) {
            for (int j = pos; j < i; ++j) {
                ans.push_back(ps[j].second);
            }

            tot_p += ans.size();
            diff.push_back(ps[pos].first);
            ans_p.push_back({ps[pos].first, ans});
            ans.clear();
        }
    }
    for (long long x : not_p) {
        long long y = x;
        for (auto p : diff) {
            while (x % p == 0) {
                x /= p;
            }
        }
        if (x == 1) {
            ans.push_back(y);
        }
    }
    //cout << "@" << ans.size() << " " << tot_p << endl;
    if (ans.size() + tot_p < k) {
        cout << 0 << "\n";
        return 0;
    }
    if (tot_p <= k) {
        for (auto p : ans_p) {
            for (auto x : p.second) {
                ans.push_back(x);
            }
        }
        reverse(ans.begin(), ans.end());
        write(ans);
    }
    if (k % 2 == 0) {
        //cout << "#" << endl;
        vector<long long> v1, v2;
        for (auto p : ans_p) {
            v1.push_back(p.second[0]);
            v1.push_back(p.second[1]);
            for (int i = 2; i < p.second.size(); ++i) {
                v2.push_back(p.second[i]);
            }
        }
        for (auto x : v2) {
            v1.push_back(x);
        }
        write(v1);
    }
    for (int i = 0; i < ans_p.size(); ++i) {
        if (ans_p[i].second.size() != 2) {
            vector<long long> v1, v2;
            v1.push_back(ans_p[i].second[0]);
            v1.push_back(ans_p[i].second[1]);
            v1.push_back(ans_p[i].second[2]);
            for (int j = 3; j < ans_p[i].second.size(); ++j) {
                v2.push_back(ans_p[i].second[j]);
            }
            for (int k = 0; k < ans_p.size(); ++k) {
                if (i == k) {
                    continue;
                }
                v1.push_back(ans_p[k].second[0]);
                v1.push_back(ans_p[k].second[1]);
                for (int i = 2; i < ans_p[k].second.size(); ++i) {
                    v2.push_back(ans_p[k].second[i]);
                }
            }
            for (auto x : v2) {
                v1.push_back(x);
            }
            write(v1);
        }
    }
    int mn = inf;
    for (long long x : not_p) {
        long long y = x;
        int cnt = 0;
        for (auto p : diff) {
            if (x % p == 0) {
                ++cnt;
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x == 1 && mn > cnt) {
            ans.clear();
            ans.push_back(y);
            mn = cnt;
        }
    }
    if (2 * mn + 1 <= k) {
        set<long long> ok_p;
        long long x = ans[0];
        for (auto p : diff) {
            if (x % p == 0) {
                ok_p.insert(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        vector<long long> v1, v2;
        for (auto p : ans_p) {
            if (!ok_p.count(p.first)) {
                continue;
            }
            v1.push_back(p.second[0]);
            v1.push_back(p.second[1]);
            for (int i = 2; i < p.second.size(); ++i) {
                v2.push_back(p.second[i]);
            }
        }
        for (auto p : ans_p) {
            if (ok_p.count(p.first)) {
                continue;
            }
            v1.push_back(p.second[0]);
            v1.push_back(p.second[1]);
            for (int i = 2; i < p.second.size(); ++i) {
                v2.push_back(p.second[i]);
            }
        }
        for (auto x : v1) {
            ans.push_back(x);
        }
        for (auto x : v2) {
            ans.push_back(x);
        }
        write(ans);
    }
    puts("0");
    return 0;
}