#include <bits/stdc++.h>
using namespace std;

int d[200010];
int main() {
    int a, b; cin >> a >> b;
    if(a > b) swap(a, b);

    d[0] = 1;
    const int mod = 1000000007;

    int ans = 0, sum = 0;
    for(int i = 1; i < 1010; ++i) {
        bool ok = false;
        int tmp = 0;
        sum += i;
        for(int j = a; j >= 0; --j) {
            if(j - i >= 0) d[j] = (d[j] + d[j - i]) % mod;
            if(j + b >= sum) {
                ok = true;
                tmp = (tmp + d[j]) % mod;
            }
        }

        if(ok) ans = tmp;
        else break;
    }

    printf("%d\n", ans);


    return 0;
}