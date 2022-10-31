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
int a[maxn];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while (ch != '-' && (ch < '0' || '9' < ch)) ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read();
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    int c = 0;
    for (int i = n; i; -- i)
        if (a[i] == a[n])
            ++ c;
        else
            break;
    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        if (a[i] == a[n])
            ans = max(ans, n - c - i);
        else
            ans = max(ans, n - i);
    cout << ans << endl;
}