#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll x, y;
char S[100005];
int L[3][100005];
int R[3][100005];
int main() {
    scanf("%s%lld%lld", S + 1, &x, &y);
    n = strlen(S + 1);
    for (int i = 1; i <= n; i++) {
        L[0][i] = L[0][i - 1] + (S[i] == '0');
        L[1][i] = L[1][i - 1] + (S[i] == '1');
        L[2][i] = L[2][i - 1] + (S[i] == '?');
    }
    for (int i = n; i >= 1; i--) {
        R[0][i] = R[0][i + 1] + (S[i] == '0');
        R[1][i] = R[1][i + 1] + (S[i] == '1');
        R[2][i] = R[2][i + 1] + (S[i] == '?');
    }
    ll ans, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (S[i] == '0') sum += x * (R[1][i + 1] + R[2][i + 1]) + y * (L[1][i - 1] + L[2][i - 1]);
        else sum += x * L[0][i - 1] + y * R[0][i + 1];
    }
    ans = sum;
    for (int i = 1; i <= n; i++) {
        if (S[i] != '?') continue;
        sum -= 2 * (x * (L[0][i - 1] + L[2][i - 1]) + y * R[0][i + 1]);
        sum += 2 * (x * (R[1][i + 1] + R[2][i + 1]) + y * L[1][i - 1]);
        ans = min(ans, sum);
    }
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (S[i] != '1') sum += x * R[1][i + 1] + y * L[1][i - 1];
        else sum += x * (L[0][i - 1] + L[2][i - 1]) + y * (R[0][i + 1] + R[2][i + 1]);
    }
    ans = min(ans, sum);
    for (int i = 1; i <= n; i++) {
        if (S[i] != '?') continue;
        sum += 2 * (x * L[0][i - 1] + y * (R[0][i + 1] + R[2][i + 1]));
        sum -= 2 * (x * R[1][i + 1] + y * (L[1][i - 1] + L[2][i - 1]));
        ans = min(ans, sum);
    }
    printf("%lld\n", ans / 2);
}