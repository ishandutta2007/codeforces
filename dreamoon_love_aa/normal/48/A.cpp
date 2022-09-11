#include<stdio.h>
int T(int x){return x%3;}
char f(int a[3]){
    int i;
    for(i=0;i<3;i++)
        if(a[i]==T(a[T(i+1)]+1)&&a[i]==T(a[T(i+2)]+1))break;
    if(i==0)return 'F';
    else if(i==1)return 'M';
    else if(i==2)return 'S';
    return '?';
}
main(){
    char s[9];
    int i,a[3];
    for(i=0;i<3;i++){
        scanf("%s",s);
        if(s[0]=='p')a[i]=0;
        else if(s[0]=='s')a[i]=1;
        else a[i]=2;
    }
    printf("%c\n",f(a));
}