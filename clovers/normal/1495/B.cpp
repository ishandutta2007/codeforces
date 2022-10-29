#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}
 
const int N = 1e5 + 5;
 
int a[N], l[N], r[N];
int n, maxn, ans, cnt;
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        if (i != 1 && a[i - 1] < a[i]) l[i] = l[i - 1];
        else l[i] = i;
    }
    for (int i = n; i >= 1; i--) {
        if (i != n && a[i + 1] < a[i]) r[i] = r[i + 1];
        else r[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int len = max(i - l[i] + 1, r[i] - i + 1);
        if (len > maxn) maxn = len, cnt = 1;
        else if (len == maxn) ++cnt;
    }
    for (int i = 1; i <= n; i++) {
        if (l[i] == i || r[i] == i) continue;
        if (i - l[i] != r[i] - i) continue;
        int len = i - l[i] + 1;
        if (len % 2 == 0) continue;
        if (len < maxn || (len == maxn && cnt > 1)) continue;
        ++ans;
    }
    print(ans, '\n');
    return 0;
}