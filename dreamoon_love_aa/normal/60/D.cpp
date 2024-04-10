#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000001
int d[SIZE],an;
bool p[4000];
int pp[1000],pn;
long long gcd(long long x,long long y){
    if(y)while((x%=y)&&(y%=x));
    return x+y;
}
void joint(int x,int y){
    while(x!=d[x])x=d[x];
    while(y!=d[y])y=d[y];
    if(x==y)return;
    if(rand()&1)d[x]=y;
    else d[y]=x;
    an--;
}
void Do(long long x,long long y){
    long long z=x*x/y;
    if(!((z+y)&1)&&gcd(x,(z+y)>>1)==1){
        if(((z+y)>>1)<SIZE&&d[(z+y)>>1])joint(x,(z+y)>>1);
        if(((z-y)>>1)<SIZE&&d[(z-y)>>1])joint(x,(z-y)>>1);
    }
}
struct data{
    int p,n;
};
long long pow(long long x,int y){
    long long an=1;
    while(y){
        if(y&1)an*=x;
        x*=x;
        y>>=1;
    }
    return an;
}
void dfs(data X[],long long v,int now,int n,int x){
    if(v>=x)return;
    if(now==n){
        Do(x,v);
        return;
    }
    int i;
    if(X[now].p==2){
        for(i=1;i<=X[now].n;i++){
            v*=X[now].p;
            dfs(X,v,now+1,n,x);
        }
    }
    else{
        dfs(X,v,now+1,n,x);
        dfs(X,v*pow(X[now].p,X[now].n),now+1,n,x);
    }
}
void Go(int x){
    int i,n=0,xx=x;
    data a[20];
    for(i=0;i<pn&&pp[i]*pp[i]<=x;i++){
        if(x%pp[i]==0){
            a[n]=(data){pp[i],0};
            while(x%pp[i]==0){
                x/=pp[i];
                a[n].n+=2;
            }
            n++;
        }
    }
    if(x!=1)a[n++]=(data){x,2};
    dfs(a,1,0,n,xx);
}
main(){
    int n,x,i,j;
    for(i=2;i*i<SIZE;i++)
        if(!p[i])
            for(j=i+i;j*j<SIZE;j+=i)p[j]=1;
    pp[0]=2;
    pn=1;
    for(i=3;i*i<SIZE;i+=2)
        if(!p[i])pp[pn++]=i;
    scanf("%d",&n);
    an=n;
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        d[x]=x;
    }
    for(i=3;i<=10000000;i++)
        if(d[i]){
            Go(i);
        }
    printf("%d\n",an);
}