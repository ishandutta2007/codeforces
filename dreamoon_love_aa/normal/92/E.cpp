#include<stdio.h>
#define SIZE 100010
#define MOD 1000000009
int d[SIZE],r[SIZE],en[SIZE];
int an;
void f(int x,int y){
    while(x!=d[x])x=d[x];
    while(y!=d[y])y=d[y];
    if(x!=y){
        if(r[x]<r[y]){
            d[x]=y;
            en[y]+=en[x];
        }
        else if(r[x]>r[y]){
            d[y]=x;
            en[x]+=en[y];
        }
        else{
            d[x]=y;
            en[y]+=en[x];
            r[y]++;
        }
        return ;
    }
    an<<=1;
    an%=MOD;
}
main(){
    int n,m,i,x,y;
    an=1;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)d[i]=i;
    while(m--){
        scanf("%d%d",&x,&y);
        f(x,y);
        printf("%d\n",(an+MOD-1)%MOD);
    }
}