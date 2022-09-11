#include<stdio.h>
#include<stdlib.h>
bool is_digit(char c){return c>='0'&&c<='9';}
void f1(char s[]){
    int y=0,x,i,iter=1,tmp=0;
    for(i=0;!is_digit(s[i]);i++){
        tmp+=iter;
        y*=26;
        y+=s[i]-'A';
        iter*=26;
    }
    y+=tmp;
    x=atoi(s+i);
    printf("R%dC%d\n",x,y);
}
void print(int x,int y){
    if(y<0)return;
    print(x/26,y-1);
    printf("%c",'A'+x%26);
}
void f2(char s[]){
    int x,y,i,iter=26;
    y=atoi(s+1);
    for(i=1;is_digit(s[i]);i++);
    x=atoi(s+i+1);
    x--;
    i=0;
    while(x>=iter){
        x-=iter;
        iter*=26;
        i++;
    }
    print(x,i);
    printf("%d\n",y);
}
main(){
    char s[19];
    int i,T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        for(i=0;s[i]&&!is_digit(s[i]);i++);
        for(;s[i]&&is_digit(s[i]);i++);
        if(!s[i])f1(s);
        else f2(s);
    }
}