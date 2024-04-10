#include<stdio.h>
#define MAX 1000000000000000000ll
long long an;
int p[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int d[15];
long long pow(long long x,int y){
    long long an=1;
    while(y){
        if(y&1){
            if(an>MAX/x)return MAX+1;
            an*=x;
        }
        if(x>MAX/x&&y>1)return MAX+1;
        x*=x;
        y>>=1;
    }
    return an;
}
void dfs(int x,int y,int z){
    int i;
    long long tmp=1,tmp2;
    d[z]=y;
    for(i=0;i<=z;i++){
        tmp2=pow(p[i],d[z-i]-1);
        if(tmp>an/tmp2)break;
        tmp*=tmp2;
    }
    if(i>z&&tmp<an)an=tmp;
    
    for(i=x;i*i<=y;i++){
        if(y%i==0){
            d[z]=i;
            dfs(i,y/i,z+1);
        }
    }
}
main(){
    int n;
    scanf("%d",&n);
    if(n==1)puts("1");
    else{
        an=MAX;
        dfs(2,n,0);
        printf("%I64d\n",an);
    }
}