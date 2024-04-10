#include<stdio.h>
#include<stdlib.h>
int d[30]={3000,2000,1000,900,800,700,600,500,400,300,200,100,90,80,70,60,50,40,30,20,10,9,8,7,6,5,4,3,2,1};
char e[30][8]={"MMM","MM","M","CM","DCCC","DCC","DC","D","CD","CCC","CC","C","XC","LXXX","LXX","LX","L","XL","XXX","XX","X","IX","VIII","VII","VI","V","IV","III","II","I"};
void print(long long x,int b){
    if(x==0)return;
    print(x/b,b);
    if(x%b<10)printf("%d",x%b);
    else printf("%c",x%b-10+'A');
}
main(){
    int a,b,i;
    long long x;
    char s[8],c[1024];
    scanf("%d%s%s",&a,s,c);
    x=0;
    for(i=0;c[i];i++){
        x*=a;
        if(c[i]>='0'&&c[i]<='9')x+=c[i]-'0';
        else x+=c[i]-'A'+10;
    }
    if(s[0]!='R'){
        b=atoi(s);
        if(x==0)puts("0");
        else{
            print(x,b);
            puts("");
        }
    }
    else{
        for(i=0;i<30;i++){
            if(x>=d[i]){
                x-=d[i];
                printf("%s",e[i]);
            }
        }
        puts("");
    }
}