#include <bits/stdc++.h>
using namespace std;
int n, cnt[15];
int main(){
    scanf("%d", &n);
    for (register int i = 1;i <= n;i ++){
        int x;scanf("%1d", &x);
        switch (x){
            case 2 :{
                cnt[2] ++;
                break;
            }
            case 3:{
                cnt[3] ++;
                break;
            }
            case 4:{
                cnt[3] ++;
                cnt[2] += 2;
                break;
            }
            case 5:{
                cnt[5] ++;
                break;
            }
            case 6:{
                cnt[3] ++;
                cnt[5] ++;
                break;
            }
            case 7:{
                cnt[7] ++;
                break;
            }
            case 8:{
                cnt[7] ++;
                cnt[2] += 3;
                break;
            }
            case 9:{
                cnt[7] ++;
                cnt[2] ++;
                cnt[3] += 2;
            }
            default: break;
        }
    }
    for (register int i = 9;i >= 2;i --) {
        while (cnt[i] --){
            putchar(i + 48);
        }
    }
    putchar(10);
}