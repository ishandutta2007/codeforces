#include<stdio.h>
main(){
    int x,y,i;
    char s[16];
    scanf("%d : %d",&x,&y);
    y++;
    do{
        if(y==60)y=0,x++;
        if(x==24)x=0;
        sprintf(s,"%02d:%02d",x,y);
        for(i=0;i<2;i++){
            if(s[i]!=s[4-i])break;
        }
        if(i==2)break;
        y++;
    }while(1);
    puts(s);
}