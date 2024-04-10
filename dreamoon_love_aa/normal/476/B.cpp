#include<cstdio>
char s1[12],s2[12];
int main(){
    scanf("%s%s",&s1,&s2);
    int qq=0;
    int now=0;
    for(int i=0;s1[i];i++){
        if(s1[i]=='+')now++;
        else now--;
        if(s2[i]=='+')now--;
        else if(s2[i]=='-')now++;
        else qq++;
    }
    if(now<0)now=-now;
    if(qq<now){
        printf("%.12f\n",0.);
        return 0;
    }
    double an=1;
    for(int i=1;i<=qq;i++)an*=i*0.5;
    int lol=(qq-now)/2;
    for(int i=1;i<=lol;i++)an/=i;
    for(int i=1;i<=qq-lol;i++)an/=i;
    printf("%.12f\n",an);
    return 0;
}