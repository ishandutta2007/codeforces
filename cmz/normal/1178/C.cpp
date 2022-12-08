#include <bits/stdc++.h>
using namespace std;
int mod=998244353;
inline int power(int a, int b) {
    long long res = a, ans = 1;
    for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
    return ans;
}
int kkk;
int main() {
    int w, h;
    scanf("%d%d", &w, &h);
    printf("%d\n", power(2, w + h));
    return 0;
};