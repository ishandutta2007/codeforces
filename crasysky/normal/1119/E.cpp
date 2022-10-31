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
const int maxn = 1000006;
int n;
long long a[maxn], b[maxn], c[maxn];
bool check(long long x){
    for (int i = 1; i <= n; ++ i)
        b[i] = a[i], c[i] = 0;
    for (int i = n; i && x; -- i){
        long long t = min(x, b[i] / 2);
        x -= t, b[i] -= 2 * t;
        c[i] += t;
    }
    if (x)
        return false;
    for (int i = 1; i <= n; ++ i){
        b[i] += b[i - 1], c[i] += c[i - 1];
        if (b[i] < c[i])
            return false;
    }
    return true;
}
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    n = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    long long l = 0, r = 1LL << 60, ans = 0;
    while (l <= r){
        long long m = l + r >> 1;
        if (check(m))
            ans = m, l = m + 1;
        else
            r = m - 1;
    }
    cout << ans << endl;
}