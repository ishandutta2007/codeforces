#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
const long long INF = 1LL << 60;
const int maxn = 1e6 + 6;
int a[maxn], b[maxn], car[maxn], mx[maxn];
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
    for (int i = 1; i <= n; ++ i){
        b[i] = read();
        car[b[i]] = i;
    }
    for (int i = 1; i <= n; ++ i)
        mx[i] = max(mx[i - 1], car[a[i]]);
    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        if (car[a[i]] < mx[i - 1])
            ++ ans;
    cout << ans << endl;
}