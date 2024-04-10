#include <stdio.h>
#include <algorithm>
int v[26];
char d[100050];
long long sum[100050];
int chk[26];
struct data {
    long long n;
    int check;
    char c1, c2;
    bool operator < (const data & l) const {
        if(n != l.n) return n < l.n;
        else return check < l.check;
    }
} d2[100050];
int main() {
    int i, L, en, j;
    long long ans = 0;
    for(i = 0; i <= 25; i++) scanf("%d", &v[i]);
    scanf("%s", d);
    for(L = 0; d[L] != 0; L++) {
        sum[L+1] = sum[L] + v[d[L]-'a'];
    }
    for(i = 1; i <= L-1; i++) {
        d2[i].n = sum[i];
        d2[i].check = i;
        d2[i].c1 = d[i-1];
        d2[i].c2 = d[i];
    }
    std::sort(d2+1, d2+L);
    for(i = 1; i <= L-1;) {
        en = i;
        while(en < L-1) {
            if(d2[en+1].n != d2[i].n) break;
            en++;
        }
        for(j = i; j <= en; j++) chk[d2[j].c2-'a']++;
        for(j = i; j <= en; j++) {
            ans += chk[d2[j].c1-'a'];
            chk[d2[j].c2-'a']--;
        }
        i = en+1;
    }
    printf("%lld", ans);
    return 0;
}