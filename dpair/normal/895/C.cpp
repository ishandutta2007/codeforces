#include <bits/stdc++.h>
using namespace std;

int n;

int prime[21], tot, cnt[71];
bitset <105> b;
int c[71];
inline void init(){
    for (register int i = 2;i <= 70;i ++){
        if(!b[i]) prime[++ tot] = i;
        for (register int j = 1;j <= tot && i * prime[j] <= 70;j ++){
            b[i * prime[j]] = 1;
            if(!(i % prime[j])) break;
        }
    }
}
typedef long long LL;
const LL MOD = 1000000007;
LL dp[(1 << 19)], base[100005];
int main(){
    init();
    // printf("%d\n", tot);
    scanf("%d", &n);
    base[0] = 1;
    for (register int i = 1;i <= n;i ++) base[i] = (base[i - 1] << 1) % MOD;
    for (register int i = 1;i <= 70;i ++){
        for (register int j = 1;j <= tot;j ++){
            int tmp = 0, temp = i;
            while(temp % prime[j] == 0) tmp ++, temp /= prime[j];
            if(tmp & 1) c[i] |= (1 << (j - 1));
        }
    }
    while(n --){
        int x;scanf("%d", &x);
        cnt[x] ++;
    }
    dp[0] = 1;
    for (register int i = 1;i <= 70;i ++){
        if(!cnt[i]) continue;
        cnt[i] --;
        for (register int j = 0;j < (1 << 19);j ++){
            int num = j ^ c[i];
            if(num < j) continue;
            LL tmp = (dp[num] + dp[j]) % MOD;
            dp[num] = dp[j] = (tmp * base[cnt[i]]) % MOD;
        }
    }
    printf("%lld\n", (dp[0] - 1 + MOD) % MOD);
}