#include <bits/stdc++.h>
using namespace std;
int n, cnt1;
inline int get0(int l, int r){
    printf("? ");
    for (register int i = 1;i <= n;i ++) putchar(48 + (i <= r && i >= l));
    putchar(10);
    fflush(stdout);
    int res;scanf("%d", &res);
    return r - l + 1 - ((r - l + 1 + cnt1 - res) >> 1);
}
inline int get1(int l, int r){
    return r - l + 1 - get0(l, r);
}
inline int getpos(int l, int r){
    printf("? ");
    for (register int i = 1;i <= n;i ++) putchar(48 + (i == r || i == l));
    putchar(10);
    fflush(stdout);
    int res;scanf("%d", &res);
    return (2 + cnt1 - res) >> 1;
}
int main(){
    scanf("%d", &n);
    printf("? ");
    for (register int i = 1;i <= n;i ++) putchar(48);
    putchar(10);
    fflush(stdout);
    scanf("%d", &cnt1);
    srand(time(NULL));
    if(cnt1 >= (n >> 1)){
        int tot = 14;
        int l = 1, r = n, pos;
        while(l <= r){
            int mid = (l + r) >> 1;
            tot --;
            if(get0(l, mid)) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        while(tot --){
            int x = rand() % n + 1;
            int x2 = rand() % n + 1;
            while(x == x2){
                x = rand() % n + 1;
                x2 = rand() % n + 1;
            }
            int res = getpos(x, x2);
            if(res == 2){
                printf("! %d %d\n", pos, x);
                fflush(stdout);
                return 0;
            }
            if(res == 1){
                if(!get0(x, x)){
                    printf("! %d %d\n", pos, x);
                    fflush(stdout);
                    return 0;
                }
                else{
                    printf("! %d %d\n", pos, x2);
                    fflush(stdout);
                    return 0;
                }
            }
        }
    }
    else{
        int tot = 14;
        int l = 1, r = n, pos;
        while(l <= r){
            int mid = (l + r) >> 1;
            tot --;
            if(get1(l, mid)) pos = mid, r = mid - 1;
            else l = mid + 1;
        }
        while(tot --){
            int x = rand() % n + 1;
            int x2 = rand() % n + 1;
            while(x == x2){
                x = rand() % n + 1;
                x2 = rand() % n + 1;
            }
            int res = getpos(x, x2);
            if(res == 0){
                printf("! %d %d\n", x, pos);
                fflush(stdout);
                return 0;
            }
            if(res == 1){
                if(get0(x, x)){
                    printf("! %d %d\n", x, pos);
                    fflush(stdout);
                    return 0;
                }
                else{
                    printf("! %d %d\n", x2, pos);
                    fflush(stdout);
                    return 0;
                }
            }
        }
    }
}