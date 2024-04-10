#include <cstring>
#include <cstdio>
int n;
int p[5005], b[5005], pb[5005], bp[5005];
inline bool judge(){
    for (register int i = 0;i < n;i ++){
        if(p[b[i]] ^ i) return 0;
    }
    return 1;
}
int main(){
    scanf("%d", &n);
    for (register int i = 0;i < n;i ++){
        printf("? 0 %d\n", i);
        fflush(stdout);
        scanf("%d", &pb[i]);
    }
    for (register int i = 0;i < n;i ++){
        printf("? %d 0\n", i);
        fflush(stdout);
        scanf("%d", &bp[i]);
    }
    int ans = 0;
    int res[5005];

    for (p[0] = 0;p[0] < n;p[0] ++){
        for (register int i = 0;i < n;i ++) b[i] = p[0] ^ pb[i];
        for (register int i = 0;i < n;i ++) p[i] = b[0] ^ bp[i];
        if(judge()){
            ans ++;
            if(ans == 1) memcpy(res, p, sizeof(res));
        }
    }
    printf("!\n%d\n", ans);
    for (register int i = 0;i < n;i ++) printf("%d ", res[i]);
    printf("\n");
    fflush(stdout);
}