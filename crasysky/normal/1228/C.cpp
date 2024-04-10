#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int P = (1e9) + 7;
int fpw(int x, long long y){
    int ans = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P)
        if (y & 1)
            ans = 1LL * ans * x % P;
    return ans;
}
long long read(){
    long long c = 0; char ch = getchar();
    while (ch < '0' || '9' < ch) ch = getchar();
    while ('0' <= ch && ch <= '9') c = c * 10 + ch - '0', ch = getchar();
    return c;
}
int main(){
    int x = read(), ans = 1;
    long long n = read();
    for (int i = 2; i * i <= x && x != 1; ++ i)
        if (x % i == 0){
            while (x % i == 0)
                x /= i;
            for (long long j = i; j <= n; j *= i){
                long long p = n / j;
                if (n / j >= i)
                    p -= n / (i * j);
                ans = 1LL * fpw(j % P, p) * ans % P;
                if (n / j < i)
                    break;
            }
        }
    if (x != 1){
        int i = x;
        for (long long j = i; j <= n; j *= i){
            long long p = n / j;
            if (n / j >= i)
                p -= n / (i * j);
            ans = 1LL * fpw(j % P, p) * ans % P;
            if (n / j < i)
                break;
        }
    }
    cout << ans << endl;
}