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

const int max_n = 222222, mod = 1000000007;

int n, a[max_n], pref[max_n], suf[max_n];
vector<pair<int, int> > v;

int power(int a, long long b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % mod;
}

int rv(int x) {
    return power(x, mod - 2);
}

int get(int poz) {
    int res1 = 1, res2 = 1;
    if (poz > 0) {
        res1 = pref[poz - 1];
    }
    if (poz + 1 < v.size()) {
        res2 = suf[poz + 1];
    }
    return (1LL * res1 * res2) % (mod - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        ++a[x];
    }
    for (int i = 0; i < max_n; ++i) {
        if (a[i]) {
            v.push_back(make_pair(i, a[i]));
        }
    }
    pref[0] = v[0].second + 1;
    int sz = v.size();
    for (int i = 1; i < sz; ++i) {
        pref[i] = (1LL * pref[i - 1] * (v[i].second + 1)) % (mod - 1);
    }
    suf[sz - 1] = v.back().second + 1;
    for (int i = sz - 2; i >= 0; --i) {
        suf[i] = (1LL * suf[i + 1] * (v[i].second + 1)) % (mod - 1);
    }
    int ans = 1;
    for (int i = 0; i < sz; ++i) {
        long long sum = (1LL * v[i].second * (v[i].second + 1)) / 2;
        int p = power(power(v[i].first, sum), get(i));
        ans = (1LL * ans * p) % mod;
    }
    printf("%d\n", ans);
    return 0;
}