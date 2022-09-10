#include<cstdio>
int abs(int x){return x>0?x:-x;}
int main(){
    int x,y,a=0,b=0,c=0;
    scanf("%d%d",&x,&y);
    for(int i=1;i<=6;i++){
        if(abs(i-x)<abs(i-y))a++;
        else if(abs(i-x)==abs(i-y))b++;
        else if(abs(i-x)>abs(i-y))c++;
    }
    printf("%d %d %d\n",a,b,c);
}