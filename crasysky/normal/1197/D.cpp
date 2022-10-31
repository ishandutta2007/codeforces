#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
const int maxn = 1000006;
const long long INF = 1LL << 60;
long long s[maxn], mx[102];
int read(){
    int c = 0, f = 1; char ch = getchar();
    while ((ch < '0' || '9' < ch) && ch != '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c * f;
}
int main(){
    int n = read(), m = read(), k = read();
    for (int i = 1; i <= n; ++ i)
        s[i] = s[i - 1] + read();
    for (int i = 1; i < m; ++ i)
        mx[i] = -INF;
    long long ans = 0;
    for (int i = 1; i <= n; ++ i){
        mx[(i - 1) % m] -= k;
        mx[i % m] = max(mx[i % m], -s[i]);
        for (int j = 0; j < m; ++ j)
            ans = max(ans, s[i] + mx[j]);
    }
    cout << ans << endl;
}