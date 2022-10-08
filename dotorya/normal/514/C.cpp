#include <stdio.h>
#include <algorithm>
char d[600050];
int N, M;
struct data {
    data() {
        data(0,0,0);
    }
    data(int c, long long a, long long b) {
        L = c, chk1 = a, chk2 = b;
    }
    int L;
    long long chk1, chk2;
    bool operator < (const data & l) const {
        if(L != l.L) return L < l.L;
        else if(chk1 != l.chk1) return chk1 < l.chk1;
        else return chk2 < l.chk2;
    }
    bool operator == (const data & l) const {
        return L == l.L && chk1 == l.chk1 && chk2 == l.chk2;
    }
} hash[300050];
bool bin_search(data x) {
    int st = 1, en = N, mi;
    while(st <= en) {
        mi = (st+en)/2;
        if(x == hash[mi]) return true;
        if(x < hash[mi]) en = mi-1;
        else st = mi+1;
    }
    return false;
}
int main() {
    int i, j, k, t_l;
    long long t1 = 0, t2 = 0, t3, t4, t5, t6;
    const long long MOD = 1234567890123456L;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%s", d);
        t1 = t2 = 0;
        for(j = 0; d[j] != 0; j++) {
            t1 *= 5;
            t1 += d[j]-'a'+1;
            t1 %= MOD;
            t2 *= 11;
            t2 += d[j]-'a'+1;
            t2 %= MOD;
        }
        hash[i].L = j, hash[i].chk1 = t1, hash[i].chk2 = t2;
        for(j = 0; d[j] != 0; j++) d[j] = 0;
    }
    std::sort(hash+1, hash+N+1);
    for(i = 1; i <= M; i++) {
        scanf("%s", d);
        t1 = t2 = 0;
        for(j = 0; d[j] != 0; j++) {
            t1 *= 5;
            t1 += d[j]-'a'+1;
            t1 %= MOD;
            t2 *= 11;
            t2 += d[j]-'a'+1;
            t2 %= MOD;
        }
        t3 = 1, t4 = 1, t_l = j;
        for(j = j-1; j >= 0; j--) {
            for(k = 'a'; k <= 'z'; k++) {
                if(k == d[j]) continue;
                t5 = t1-t3*(d[j]-k);
                t5 %= MOD;
                if(t5 < 0) t5 += MOD;
                t6 = t2-t4*(d[j]-k);
                t6 %= MOD;
                if(t6 < 0) t6 += MOD;
                if(bin_search(data(t_l,t5,t6))) break;
            }
            if(k != 'z'+1) break;
            t3 *= 5;
            t3 %= MOD;
            t4 *= 11;
            t4 %= MOD;
        }
        if(j != -1) printf("YES\n");
        else printf("NO\n");
        for(j = 0; d[j] != 0; j++) d[j] = 0;
    }
    return 0;
}