#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;
const int P = (1e9) + 7;
int c[1003][1003];
int fpw(int x, int y){
    int ans = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P)
        if (y & 1)
            ans = 1LL * ans * x % P;
    return ans;
}
int read(){
    int c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int n = read(), k = read(), ans = 0;
    for (int i = 0; i <= n; ++ i){
        c[i][0] = 1;
        for (int j = 1; j <= i; ++ j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
    }
    for (int i = 0; i <= n; ++ i)
        for (int j = 0; j <= n; ++ j){
            int flag = (i + j) % 2 == 0 ? 1 : P - 1;
            flag = 1LL * flag * c[n][i] % P * c[n][j] % P;
            int have = (n - i) * (n - j);
            ans = (ans + 1LL * flag * fpw(k - 1, n * n - have) % P * fpw(k, have)) % P;
        }
    cout << ans << endl;
}