#include <stdio.h>
const long long MOD = 1000000009;
struct data {
    long long a, b;
} sum[1000050];
long long pow_31[1000050];
long long pow_37[1000050];
char d[1000050];
int ANS[1000050];
int ANS_t[1000050];
int main() {
    int N, K, i, j, st, en, mi, ans;
    long long t, t2, t3, p, p2, p3;
    scanf("%d %d", &N, &K);
    scanf("%s", &d[1]);
    if(K == 1) {
        for(i = 1; i <= N; i++) printf("1");
        return 0;
    }
    pow_31[0] = 1;
    for(i = 1; i <= N; i++) pow_31[i] = (pow_31[i-1]*31)%MOD;
    for(i = 1; i <= N; i++) pow_37[i] = (pow_37[i-1]*37)%MOD;
    for(i = 1; i <= N; i++) sum[i].a = (sum[i-1].a+d[i]*pow_31[i-1])%MOD;
    for(i = 1; i <= N; i++) sum[i].b = (sum[i-1].b+d[i]*pow_37[i-1])%MOD;
    for(i = 1; i*K <= N; i++) {
        t = sum[i].a;
        p = sum[i].b;
        for(j = 2; j <= K; j++) {
            t2 = (sum[j*i].a-sum[(j-1)*i].a+MOD)%MOD;
            p2 = (sum[j*i].b-sum[(j-1)*i].b+MOD)%MOD;
            t3 = (t*pow_31[(j-1)*i])%MOD;
            p3 = (p*pow_37[(j-1)*i])%MOD;
            if(t2 != t3 || p2 != p3) break;
        }
        if(j == K+1) {
            ANS_t[i*K]++;
            ans = 0;
            st = 1, en = i;
            while(st <= en) {
                mi = (st+en)/2;
                t2 = (sum[mi].a * pow_31[i*K])%MOD;
                p2 = (sum[mi].b * pow_37[i*K])%MOD;
                t3 = (sum[i*K+mi].a-sum[i*K].a+MOD)%MOD;
                p3 = (sum[i*K+mi].b-sum[i*K].b+MOD)%MOD;
                if(t2 == t3 && p2 == p3) {
                    ans = mi;
                    st = mi+1;
                }
                else en = mi-1;
            }
            ANS_t[i*K+ans+1]--;
        }
    }
    for(i = 1; i <= N; i++) {
        ANS[i] = ANS[i-1]+ANS_t[i];
        if(ANS[i] >= 1) printf("1");
        else printf("0");
    }
    return 0;
}