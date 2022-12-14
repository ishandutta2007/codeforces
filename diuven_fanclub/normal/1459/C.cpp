#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int n, m;
ll A[200005];
ll B[200005];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
    for (int i = 1; i <= m; i++) scanf("%lld", &B[i]);
    ll g = 0;
    for (int i = 2; i <= n; i++) {
        g = gcd(abs(A[i] - A[1]), g);
    }
    for (int i = 1; i <= m; i++) {
        printf("%lld ", gcd(A[1] + B[i], g));
    }
}