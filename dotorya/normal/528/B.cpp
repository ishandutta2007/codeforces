#include <stdio.h>
#include <algorithm>
const int IT_MAX = 262144;
int it[IT_MAX*2];
int ans[200050];
struct data {
    int a, b;
    bool operator < (const data & l) const {
        if(a!=l.a) return a<l.a;
        else return b<l.b;
    }
} d[200050];
int MAX(int a, int b) {
    if(a<b) return b;
    else return a;
}
void update(int pos, int num) {
    it[pos] = num;
    while(pos > 1) {
        pos /= 2;
        it[pos] = MAX(it[pos*2], it[pos*2+1]);
    }
    return;
}
int get_max(int pos1, int pos2) {
    if(pos1 > pos2) return 0;
    int t = 0;
    if(pos1 == pos2) return it[pos1];
    if(pos1 % 2 == 1) {
        t = it[pos1];
        pos1++;
    }
    if(pos1 == pos2) return MAX(t, it[pos1]);
    if(pos2 % 2 == 0) {
        t = it[pos2];
        pos2--;
    }
    return MAX(t, get_max(pos1/2, pos2/2));
}
int bin_search(int x, int y) {
    int ans = -1, st = 0, en = y-1, mi;
    while(st <= en) {
         mi = (st+en)/2;
         if(d[mi].a <= x) {
             ans = mi;
             st = mi+1;
         }
         else en = mi-1;
    }
    return ans;
}
int main() {
    int N, i, t1, t2;
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        scanf("%d %d", &t1, &t2);
        d[i].a = t1+t2, d[i].b = t1-t2;
    }
    std::sort(d, d+N);
    for(i = 0; i < N; i++) {
        t1 = bin_search(d[i].b, N);
        t2 = get_max(IT_MAX, IT_MAX+t1);
        ans[i] = t2+1;
        update(IT_MAX+i, ans[i]);
    }
    int ANS = 0;
    for(i = 0; i < N; i++) if(ANS < ans[i]) ANS = ans[i];
    printf("%d", ANS);
    return 0;
}