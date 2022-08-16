#include <bits/stdc++.h>
using namespace std;

#define N 200200
typedef long long ll;
const int base = 731;
const ll mod = 1e13 + 7;

ll Hash(char *s) {
    int n = strlen(s);
    ll rlt = 0;
    for (int i = 0; i < n; i ++) rlt = (rlt * base + s[i]) % mod;
    return rlt;
}

int a[N], b[N];
char s[N], t[N];
vector <ll> vec[N];

int main() {
    scanf("%s", t);
    int n;
    scanf("%d", &n);
    while (n --) {
        scanf("%s", s);
        vec[strlen(s)].push_back(Hash(s));
    }
    n = strlen(t);
    for (int l = 1; l < N; l ++) if (!vec[l].empty()) {
        sort(vec[l].begin(), vec[l].end());
        ll cur = 0, pw = 1;
        for (int i = 0; i < l; i ++) cur = (cur * base + t[i]) % mod, pw = pw * base % mod;
        for (int i = 0; i < n - l + 1; i ++) {
            int cnt = upper_bound(vec[l].begin(), vec[l].end(), cur) - lower_bound(vec[l].begin(), vec[l].end(), cur);
            a[i] += cnt, b[i+l] += cnt;
            cur = (cur * base + t[i+l] - pw * t[i]) % mod;
            if (cur < 0) cur += mod;
        }
    }
    ll rlt = 0;
    for (int i = 0; i < n; i ++) rlt += 1ll * a[i] * b[i];
    printf("%I64d\n", rlt);
}