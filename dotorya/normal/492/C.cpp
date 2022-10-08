#include <stdio.h>
#include <algorithm>
struct data {
    long long cnt, num;
    bool operator < (const data & l) const {
        return num < l.num;
    }
} d[100050];
int main() {
    long long N, R, AVG, i, t1, t2, sum = 0, t = 0;
    scanf("%lld %lld %lld", &N, &R, &AVG);
    for(i = 1; i <= N; i++) {
        scanf("%lld %lld", &t1, &t2);
        sum += t1;
        if(t1 != R) {
            t++;
            d[t].cnt = R-t1, d[t].num = t2;
        }
    }
    if(sum > N*AVG) {
        printf("0");
        return 0;
    }
    sum = N*AVG - sum;
    long long ans = 0;
    std::sort(d+1, d+t+1);
    for(i = 1; i <= t; i++) {
        if(sum <= d[i].cnt) {
            ans += sum * d[i].num;
            break;
        }
        ans += d[i].cnt * d[i].num;
        sum -= d[i].cnt;
    }
    printf("%lld", ans);
    return 0;
}