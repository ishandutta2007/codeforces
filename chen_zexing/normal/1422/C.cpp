#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define maxn 100005

using namespace std;
char s[100005];
long long mod=1000000007,pre[100005];
long long qpow(long long a,long long b) {
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int main() {
    scanf("%s", s);
    int l = strlen(s);
    long long now = 1, ans = 0;
    for (int i = 1; i <= l; i++) pre[i] = (pre[i - 1] + now * i) % mod, now = now * 10 % mod;
    for (long long i = 0; i < l; i++) {
        long long t = s[i] - '0';
        ans += 1LL * t * (1LL * i * (i - 1) / 2 + i) % mod * qpow(10, l - i - 1);
        ans %= mod;
        ans += t * pre[l - i - 1];
        ans %= mod;
    }
    cout << ans << endl;
}