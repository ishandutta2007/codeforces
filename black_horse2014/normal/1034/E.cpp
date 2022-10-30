#include <bits/stdc++.h>
using namespace std;

long long a[1<<21], b[1<<21];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string s, t; cin >> n >> s >> t;
    for (int i = 0; i < 1<<n; i++)
        a[i] = ((long long)(s[i]-'0'))<<(2*__builtin_popcount(i)),
        b[i] = ((long long)(t[i]-'0'))<<(2*__builtin_popcount(i));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1<<n; j++) if (j>>i&1) a[j] += a[j^(1<<i)], b[j] += b[j^(1<<i)];
    for (int j = 0; j < 1<<n; j++) a[j] *= b[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 1<<n; j++) if (j>>i&1) a[j] -= a[j^(1<<i)];
    for (int i = 0; i < 1<<n; i++) putchar(((a[i]>>2*__builtin_popcount(i))&3)+'0');
    return 0;
}