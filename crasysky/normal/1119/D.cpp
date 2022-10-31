#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int maxn = 100005;
long long s[maxn], sum[maxn];
long long read(){
    long long c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        s[i] = read();
    sort(s + 1, s + 1 + n);
    for (int i = 1; i < n; ++ i)
        s[i] = s[i + 1] - s[i];
    sort(s + 1, s + n);
    for (int i = 1; i < n; ++ i)
        sum[i] = sum[i - 1] + s[i];
    int q = read();
    while (q --){
        long long l = read(), r = read();
        long long len = r - l + 1;
        int t = upper_bound(s + 1, s + n, len) - s - 1;
        printf("%lld ", sum[t] + 1LL * (n - t) * len);
    }
}