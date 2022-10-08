#include <stdio.h>
#include <algorithm>
struct data {
    int cnt, chk;
    bool operator < (const data & l) const {
        if(cnt != l.cnt) return cnt < l.cnt;
        else return chk < l.chk;
    }
} d[105];
int main() {
    int N, M, i;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i].cnt);
        d[i].chk = i;
        d[i].cnt = (d[i].cnt-1)/M+1;
    }
    std::sort(d+1, d+N+1);
    printf("%d", d[N].chk);
    return 0;
}