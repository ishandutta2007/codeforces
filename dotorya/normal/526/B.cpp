#include <stdio.h>
int N;
int it[4096];
int pow_2[15];
int it2[4096];
int MAX(int a, int b) {
    if(a<b) return b;
    else return a;
}
void it_update(int pos, int num) {
    it2[pos] = num;
    int t = pos;
    while(t > 1) {
        t /= 2;
        it2[t] = MAX(it2[t*2], it2[t*2+1]);
    }
    return;
}
int get_ans(int pos) {
    int t = it2[pos];
    if(pos >= pow_2[N]) return 0;
    else return 2*t-it2[pos*2]-it2[pos*2+1]+get_ans(pos*2)+get_ans(pos*2+1);
}
int main() {
    int i, t;
    pow_2[0] = 1;
    for(i = 1; i <= 11; i++) pow_2[i] = pow_2[i-1]*2;
    scanf("%d", &N);
    for(i = 2; i < pow_2[N]; i++) {
        scanf("%d", &t);
        it[i*2] += t+it[i];
        it[i*2+1] += t+it[i];
    }
    int mx = 0;
    for(i = pow_2[N]; i < pow_2[N+1]; i++) {
        scanf("%d", &t);
        it[i] += t;
        if(mx < it[i]) mx = it[i];
    }
    for(i = pow_2[N]; i < pow_2[N+1]; i++) {
        it_update(i, it[i]);
    }
    printf("%d", get_ans(1));
    return 0;
}