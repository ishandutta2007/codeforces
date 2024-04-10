/**
 *  created: 06/03/2021, 16:31:12
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, mod = 1000000007;

const int max_p = max_n;

int used[max_p];
vector<int> primes;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            primes.push_back(i);
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}


int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int a, int b) {
    int res = 1 % mod;
    while (b) {
        if (b % 2) {
            res = mul(res, a);
        }
        b /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    return power(x, mod - 2);
}

int n, q, a[max_n], num[max_n];
map<int, int> cnt[max_n];
multiset<int> all[max_n];

vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    for (int p : primes) {
        if (1LL * p * p > x) {
            break;
        }
        int cnt = 0;
        while (x % p == 0) {
            x /= p;
            ++cnt;
        }
        if (cnt) {
            res.push_back({p, cnt});
        }
    }
    if (x > 1) {
        res.push_back({x, 1});
    }
    return res;
}

int get_power(int p) {
    if (all[num[p]].size() == n) {
        return *all[num[p]].begin();
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    for (int i = 0; i < primes.size(); ++i) {
        num[primes[i]] = i;
    }
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        for (auto p : factorize(a[i])) {
            //cout << i << ": " << p.first << " " << p.second << endl;
            all[num[p.first]].insert(p.second);
            cnt[i][p.first] = p.second;
        }
    }
    int ans = 1;
    for (int p : primes) {
        ans = mul(ans, power(p, get_power(p)));
    }
    while (q--) {
        int pos, x;
        scanf("%d%d", &pos, &x);
        --pos;
        for (auto p : factorize(x)) {
            int old = cnt[pos][p.first];
            int np = cnt[pos][p.first] += p.second;
            //cout << p.first << ": " << old << " -> " << np << endl;
            int old_power = get_power(p.first);
            if (old) {
                all[num[p.first]].erase(all[num[p.first]].find(old));
            }
            all[num[p.first]].insert(np);
            int new_power = get_power(p.first);
            ans = mul(ans, power(p.first, new_power - old_power));
        }
        printf("%d\n", ans);
    }
    return 0;
}