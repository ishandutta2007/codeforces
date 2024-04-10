#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1005];
int n, m, c, tot;
int main(){
    scanf("%d%d%d", &n, &m, &c);
    tot = n;
    while(m --){
        int x;
        scanf("%d", &x);
        if(x <= (c >> 1)){
            for (register int i = 1;i <= n;i ++){
                if(!a[i] || a[i] > x){
                    printf("%d\n", i);
                    fflush(stdout);
                    if(!a[i]) tot --;
                    a[i] = x;
                    break;
                }
            }
        }
        else{
            for (register int i = n;i >= 1;i --){
                if(!a[i] || a[i] < x){
                    printf("%d\n", i);
                    fflush(stdout);
                    if(!a[i]) tot --;
                    a[i] = x;
                    break;
                }
            }
        }
        if(!tot) return 0;
    }
}