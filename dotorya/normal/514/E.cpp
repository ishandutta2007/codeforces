#include <stdio.h>
const long long MOD = 1000000007;
long long m_gen[105][105];
int pow_2[35];
int cnt[105];
long long f[105];
long long f_sum[105];
struct matrix {
    long long d[101][101];
    matrix() {
        for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) d[i][j] = m_gen[i][j];
    }
    matrix operator * (const matrix & l) const {
        for(int i = 0; i < 101; i++) for(int j = 0; j < 101; j++) m_gen[i][j] = 0;
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                for(int k = 0; k < 101; k++) {
                    m_gen[i][j] += d[i][k] * l.d[k][j];
                    m_gen[i][j] %= MOD;
                }
            }
        }
        return matrix();
    }
};
long long get_ans(int x) {
    if(x <= 101) return f_sum[x];
    int t = x-101, i, j;
    int bin_t[35] = {0};
    m_gen[0][0] = (1+cnt[1])%MOD;
    for(i = 1; i < 100; i++) m_gen[0][i] = cnt[i+1]-cnt[i];
    m_gen[0][100] = -cnt[100];
    for(i = 1; i < 101; i++) {
        for(j = 0; j < 101; j++) {
            if(i-j == 1) m_gen[i][j] = 1;
            else m_gen[i][j] = 0;
        }
    }
    matrix tmp = matrix();
    for(i = 0; i < 101; i++) {
        for(j = 0; j < 101; j++) {
            if(i == j) m_gen[i][j] = 1;
            else m_gen[i][j] = 0;
        }
    }
    matrix ANS = matrix();
    for(i = 0; t != 0; i++) {
        bin_t[i] = t%2;
        t /= 2;
    }
    for(i = 0; i <= 30; i++) {
        if(bin_t[i] == 1) ANS = ANS * tmp;
        tmp = tmp * tmp;
    }
    long long return_ans = 0;
    for(i = 0; i < 101; i++) {
        return_ans += ANS.d[0][i] * f_sum[101-i];
        return_ans %= MOD;
    }
    if(return_ans < 0) return_ans += MOD;
    return return_ans;
}
long long ans_chk[10050];
long long ans_chk_sum[10050];
int main() {
    int i, j, N, X, t;
    scanf("%d %d", &N, &X);
    pow_2[0] = 1;
    for(i = 1; i <= 30; i++) pow_2[i] = pow_2[i-1]*2;
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        cnt[t]++;
    }
    f[0] = 1, f[1] = cnt[1];
    for(i = 2; i <= 101; i++) {
        for(j = 0; j < i; j++) {
            f[i] += f[j] * cnt[i-j];
            f[i] %= MOD;
        }
    }
    f_sum[0] = 1;
    for(i = 1; i <= 101; i++) f_sum[i] = (f_sum[i-1]+f[i])%MOD;
    printf("%lld", get_ans(X));
    return 0;
}