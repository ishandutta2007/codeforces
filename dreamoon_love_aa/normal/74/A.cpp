#include<stdio.h>
#include<string.h>
main(){
    int n,now=-2000000000,i,a[9],x;
    char s[25],an[26];
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        x=0;
        for(i=0;i<7;i++){
            scanf("%d",&a[i]);
            if(i>1)x+=a[i];
        }
        x+=a[0]*100;
        x-=a[1]*50;
        if(x>now){
            now=x;
            strcpy(an,s);
        }
    }
    printf("%s\n",an);
}