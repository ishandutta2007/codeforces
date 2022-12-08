// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
int rest;
int kkkkkkkkkk;
long long ans = 0;
int kkk;
int a[300010], n;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) {
        if(a[i] / 2 >= rest) {
            ans += rest;
            a[i] -= 2 * rest;
            rest = 0;
        }
        else {
            ans += a[i] / 2;
            rest -= a[i] / 2;
            a[i] %= 2;
        }
        ans += a[i] / 3;
        rest += a[i] % 3;
    }
    return cout << ans << endl, 0;
}