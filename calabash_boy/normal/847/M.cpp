#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
inline int readInt() {
    int s = 1, a = 0; char ch = getchar();
    while (ch < '0' || ch > '9') {if ('-' == ch) s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
    return s * a;
}
inline LL readLL() {
    LL s = 1, a = 0; char ch = getchar();
    while (ch < '0' || ch > '9') {if ('-' == ch) s = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {a = a * 10 + ch - '0'; ch = getchar();}
    return s * a;
}

const int N = 109;
int a[N];
int main() {
    int n = readInt();
    for (int i = 1; i <= n; i++) a[i] = readInt();
    int d = a[2] - a[1];
    for (int i = 3; i <= n; i++) if (a[i] - a[i - 1] != d) return 0 * printf("%d\n", a[n]);
    return 0 * printf("%d\n", a[n] + d);
}