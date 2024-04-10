#include <stdio.h>
const int MX = 1<<19;
int MOD = 1000000009;
long long fib[MX+50];
long long fib_sum[MX+50];
struct node {
    long long n;
    int st1, st2;
} it[MX*2+50];
long long get_nth_term(long long n1, long long n2, int t) {
    if(t == 1) return n1;
    if(t == 2) return n2;
    return (fib[t-2]*n1+fib[t-1]*n2)%MOD;
}
long long get_n_sum(long long n1, long long n2, int t) {
    if(t == 2) return n1+n2;
    return (fib[t]*n1 + (fib[t+1]+MOD-1)*n2)%MOD;
}
void init_update(int x, long long y) {
    int t = x;
    it[x].n = y;
    while(t > 1) {
        t /= 2;
        it[t].n = (it[2*t].n+it[2*t+1].n)%MOD;
    }
    return;
}
void update(int n, int st, int en, int r1, int r2, long long u1, long long u2) {
    if(st == r1 && en == r2) {
        if(r2 == r1) {
            it[n].n = (it[n].n+u1)%MOD;
            return;
        }
        it[n].n = (it[n].n + get_n_sum(u1, u2, en-st+1))%MOD;
        it[n].st1 = (it[n].st1 + u1)%MOD;
        it[n].st2 = (it[n].st2 + u2)%MOD;
        return;
    }
    if(r1>r2) return;
    it[n].n = (it[n].n+get_n_sum(u1, u2, r2-r1+1))%MOD;
    int mi = (st+en)/2;
    if(mi+1 <= r1) {
        update(2*n+1, mi+1, en, r1, r2, u1, u2);
    }
    else if(mi >= r2) {
        update(2*n, st, mi, r1, r2, u1, u2);
    }
    else {
        update(2*n, st, mi, r1, mi, u1, u2);
        update(2*n+1, mi+1, en, mi+1, r2, get_nth_term(u1, u2, mi-r1+2), get_nth_term(u1, u2, mi-r1+3));
    }
    return;
}
long long read(int n, int st, int en, int r1, int r2, int ran) {
    if(st == r1 && en == r2) return it[n].n;
    if(r1>r2) return 0;
    if(ran == 2) {
        it[2*n].n = (it[2*n].n + it[n].st1) % MOD;
        it[2*n+1].n = (it[2*n+1].n + it[n].st2) % MOD;
        it[n].st1 = it[n].st2 = 0;
        if(st == r1) return it[2*n].n;
        else return it[2*n+1].n;
    }
    it[2*n].n = (it[2*n].n+get_n_sum(it[n].st1, it[n].st2, ran/2))%MOD;
    it[2*n].st1 = (it[2*n].st1+it[n].st1)%MOD;
    it[2*n].st2 = (it[2*n].st2+it[n].st2)%MOD;
    it[2*n+1].n = (it[2*n+1].n+get_n_sum(get_nth_term(it[n].st1, it[n].st2, ran/2+1), get_nth_term(it[n].st1, it[n].st2, ran/2+2), ran/2))%MOD;
    it[2*n+1].st1 = (it[2*n+1].st1+get_nth_term(it[n].st1, it[n].st2,ran/2+1))%MOD;
    it[2*n+1].st2 = (it[2*n+1].st2+get_nth_term(it[n].st1, it[n].st2,ran/2+2))%MOD;
    it[n].st1 = it[n].st2 = 0;
    int mi = (st+en)/2;
    if(mi+1 <= r1) {
        return read(2*n+1, mi+1, en, r1, r2, ran/2);
    }
    else if(mi >= r2) {
        return read(2*n, st, mi, r1, r2, ran/2);
    }
    else {
        return (read(2*n, st, mi, r1, mi, ran/2) + read(2*n+1, mi+1, en, mi+1, r2, ran/2))%MOD;
    }
}
int main() {
    int N, M, i, t1, t2, chk;
    scanf("%d %d", &N, &M);
    fib[1] = fib[2] = 1;
    for(i = 3; i <= MX; i++) fib[i] = (fib[i-1]+fib[i-2])%MOD;
    for(i = 1; i <= MX; i++) fib_sum[i] = (fib[i]+fib_sum[i-1])%MOD;
    for(i = 0; i < N; i++) {
        long long t1;
        scanf("%lld", &t1);
        init_update(MX+i, t1);
    }
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d", &chk, &t1, &t2);
        if(chk == 1) update(1, 0, MX-1, t1-1, t2-1, 1, 1);
        else printf("%lld\n", read(1, 0, MX-1, t1-1, t2-1, MX));
    }
    return 0;
}