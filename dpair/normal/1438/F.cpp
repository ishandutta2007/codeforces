#include <cstring>
#include <cstdio>
#include <random>
#include <ctime>
using std :: mt19937;
mt19937 rnd(time(NULL));
int h, n;
int cnt[1 << 20 | 5];
int main(){
    scanf("%d", &h);n = (1 << h) - 1;
    int TIM = 420;
    while(TIM --){
        int u, v, w;
        u = rnd() % n + 1;
        v = rnd() % n + 1;
        w = rnd() % n + 1;
        while(u == v || u == w || v == w){
            u = rnd() % n + 1;
            v = rnd() % n + 1;
            w = rnd() % n + 1;
        }
        printf("? %d %d %d\n", u, v, w);
        fflush(stdout);
        scanf("%d", &u);cnt[u] ++;
    }
    int fst = 0, sec = 0;
    for (register int i = 1;i <= n;i ++){
        if(cnt[i] > cnt[fst]) sec = fst, fst = i;
        else if(cnt[i] > cnt[sec]) sec = i;
    }
    for (register int i = 1;i <= n;i ++){
        if(i == fst || i == sec) continue;
        printf("? %d %d %d\n", fst, sec, i);
        fflush(stdout);
        int x;scanf("%d", &x);
        if(x == i){
            printf("! %d\n", i);
            fflush(stdout);
            return 0;
        }
    }
}