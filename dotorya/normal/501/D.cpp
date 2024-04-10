#include <stdio.h>
const int IT_MAX = 262144;
int it[3][IT_MAX*2];
int d[200050][2];
int t[200050];
int ANS[200050];
void update(int chk, int pos, int num) {
    it[chk][pos] = num;
    while(pos > 1) {
        pos /= 2;
        it[chk][pos] = it[chk][pos*2]+it[chk][pos*2+1];
    }
    return;
}
int get_sum(int chk, int pos1, int pos2) {
    if(pos1 > pos2) return 0;
    int t = 0;
    if(pos1 == pos2) return it[chk][pos1];
    if(pos1 % 2 == 1) {
        t += it[chk][pos1];
        pos1++;
    }
    if(pos1 == pos2) return t+it[chk][pos1];
    if(pos2 % 2 == 0) {
        t += it[chk][pos2];
        pos2--;
    }
    return t+get_sum(chk, pos1/2, pos2/2);
}
int main() {
    int N, i, j, st, en, mi, ans, tmp;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i][0]);
    for(i = 1; i <= N; i++) scanf("%d", &d[i][1]);
    for(i = 0; i <= 1; i++) {
        for(j = N; j >= 1; j--) {
            t[j] += get_sum(i, IT_MAX, IT_MAX+d[j][i]-1);
            update(i, IT_MAX+d[j][i], 1);
        }
    }
    for(i = N; i >= 1; i--) {
        if(t[i] >= N+1-i) {
            t[i-1]++;
            t[i] -= N+1-i;
        }
    }
    for(i = 1; i <= N; i++) update(2, IT_MAX+i-1, 1);
    for(i = 1; i <= N; i++) {
        st = 0, en = N-1, ans = 0;
        while(st <= en) {
            mi = (st+en)/2;
            tmp = get_sum(2, IT_MAX, IT_MAX+mi-1);
            if(tmp <= t[i]) {
                ans = mi;
                st = mi+1;
            }
            else en = mi-1;
        }
        printf("%d ", ans);
        update(2, IT_MAX+ans, 0);
    }
    return 0;
}