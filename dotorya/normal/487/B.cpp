#include <stdio.h>
#include <algorithm>
#define MX 131072
struct data {
    long long num;
    int chk;
    bool operator < (const data & l) const {
        return num < l.num;
    }
} d[100050];
long long D[100050];
int N, S, L;
int t1[100050];
int t2[100050];
int X[100050];
int conv[100050];
int it[250000];
int MAX(int a, int b) {
    if(a<b) return b;
    else return a;
}
void it_input(int a, int n) {
    it[a] = n;
    while(a>1) {
        a /= 2;
        it[a] = MAX(it[2*a], it[2*a+1]);
    }
    return;
}
int get_max(int a, int b, int c) {
    int t = c;
    if(a>b) return c;
    if(a==b) return it[a];
    if(a % 2 == 1) {
        t = it[a];
        a++;
    }
    if(a==b) return MAX(t, it[a]);
    if(b % 2 == 0) {
        t = MAX(t,it[b]);
        b--;
    }
    return MAX(t, get_max(a/2, b/2, c));
}
int lower_bound1(long long a) {
    int st = 1, en = N, mi, ans = 0;
    while(st <= en) {
        mi = (st+en)/2;
        if(d[mi].num >= a) en = mi-1;
        else {
            ans = mi;
            st = mi+1;
        }
    }
    return ans;
}
int lower_bound2(long long a) {
    int st = 1, en = N, mi, ans = N+1;
    while(st <= en) {
        mi = (st+en)/2;
        if(d[mi].num > a) {
            ans = mi;
            en = mi-1;
        }
        else st = mi+1;
    }
    return ans;
}
void input() {
    int i;
    scanf("%d %d %d", &N, &S, &L);
    for(i = 1; i <= N; i++) {
        scanf("%lld", &d[i].num);
        D[i] = d[i].num;
        d[i].chk = i;
    }
    std::sort(d+1, d+N+1);
    for(i = 1; i <= N; i++) conv[d[i].chk] = i;
}
void get_X() {
    int i, t;
    for(i = 1; i <= N; i++) {
        t = conv[i];
        t1[i] = get_max(MX-1, MX-1+lower_bound1(d[t].num-S),0);
        it_input(MX-1+t, i);
    }
    for(i = 1; i <= MX+N-1; i++) it[i] = 0;
    for(i = 1; i <= N; i++) {
        t = conv[i];
        t2[i] = get_max(MX-1+lower_bound2(d[t].num+S), MX+N-1,0);
        it_input(MX-1+t, i);
    }
    for(i = 1; i <= N; i++) X[i] = MAX(t1[i], t2[i]);
    for(i = 1; i <= N; i++) X[i] = MAX(X[i], X[i-1]);
    return;
}
int ANS[100050];
void get_ans() {
    int i, tmp;
    for(i = 1; i <= MX+N; i++) it[i] = -123456789;
    it_input(MX, 0);
    ANS[0] = 0;
    for(i = 1; i <= L-1; i++) ANS[i] = -1;
    for(i = L; i <= N; i++) {
        tmp = get_max(MX+X[i], MX+i-L, -123456789);
        if(tmp == -123456789) ANS[i] = -1;
        else {
            ANS[i] = -tmp+1;
            it_input(MX+i, tmp-1);
        }
    }
    printf("%d", ANS[N]);
    return;
}
int main() {
    input();
    get_X();
    get_ans();
    return 0;
}