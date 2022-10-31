#include <stdio.h>
int main(){
    int res=0;
    int clock,month,number,k;
    scanf("%d%d",&clock,&month);
    for(k=0;k<month-1;k++){
        scanf("%d",&number);
        res += clock-number;
    }
    scanf("%d",&number);
    printf("%d",res);
    return 0;
}