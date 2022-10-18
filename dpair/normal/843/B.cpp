#include <bits/stdc++.h>
using namespace std;

namespace My_Rand{
    int index, MT[624];
    inline void srand(int seed){
        index = 0;
        MT[0] = seed;
        for (register int i = 1;i < 624;i ++){
            int t = 1812433253 * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
            MT[i] = t & 0xffffffff;
        }
    }
    inline void rotate(){
        for (register int i = 0;i < 624;i ++){
            int tmp = (MT[i] & 0x80000000) + (MT[(i + 1) % 624] & 0x7fffffff);
            MT[i] = MT[(i + 397) % 624] ^ (tmp >> 1);
            if(tmp & 1) MT[i] ^= 2567483615;
        }
    }
    inline int rand(){
        if(!index) rotate();
        int ret = MT[index];
        ret = ret ^ (ret >> 11);
        ret = ret ^ ((ret << 7) & 2636928640);
        ret = ret ^ ((ret << 15) & 4022730752);
        ret = ret ^ (ret >> 18);
        index = (index + 1) % 624;
        return ret;
    }
} // namespace My_Rand

int n, m, x;
int pos, ans;
int main(){
    My_Rand :: srand(20171302);
    scanf("%d%d%d", &n, &m, &x);
    pos = m;
    printf("? %d\n", pos);
    fflush(stdout);
    int tmp;
    scanf("%d %d", &ans, &tmp);
    int TIM = 998;
    while(TIM --){
        int num, nxt;
        tmp = My_Rand :: rand() % n + 1;
        printf("? %d\n", tmp);
        fflush(stdout);
        scanf("%d %d", &num, &nxt);
        if(num < x && num > ans) {
            ans = num;
            pos = tmp;
        }
    }
    TIM = 998;
    while(TIM --){
        int num, nxt;
        printf("? %d\n", pos);
        fflush(stdout);
        scanf("%d %d", &num, &nxt);
        if(num >= x){
            printf("! %d\n", num);
            fflush(stdout);
            return 0;
        }
        if(nxt == -1) break;
        pos = nxt;
    }
    printf("! -1\n");
    fflush(stdout);
    return 0;
}