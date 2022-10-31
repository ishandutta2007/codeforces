#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int maxn = 1000006;
int a[maxn], b[maxn];
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), k = read(), ans = 0;
    for (int i = 1; i <= n; ++ i)
        a[i] = read();
    for (int i = 1; i < n; ++ i)
        b[i] = a[i + 1] - a[i];
    sort(b + 1, b + n);
    for (int i = 1; i <= n - k; ++ i)
        ans += b[i];
    cout << ans << endl;
}