#include <cstdio>
int main(){
    int d[10] = {0}, n, sum=0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int x; scanf("%d", &x);
        d[x]++; sum += x;
    }
    if(sum%3)for(int i = 1; i < 10; ++i){
        if(d[i] && sum%3==i%3){
            --d[i];
            sum -= i;
            break;
        }
    }
    for(int j = 0; j < 2; ++j)
        for(int i = 1; i < 10; ++i)
            if(sum % 3 && i % 3 && d[i]){
                --d[i];
                sum -= i;
                break;
            }
    if(!sum) d[0] = 1;
    if(!d[0] || sum % 3){
        puts("-1"); return 0;
    }
    for(int i = 9; i >= 0; --i)
        while(d[i]--) printf("%d" ,i);
    puts("");
    return 0;
}