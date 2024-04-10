#include<stdio.h>
int d[100001],q[100001];
main(){
    int n,i,x,m=0;
    long long an=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&d[i]),d[i]+=d[i-1];
    if(d[n]%3)puts("0");
    else{
        x=d[n]/3;
        for(i=1;i<n;i++)
            if(d[i]==x)q[m++]=i;
        for(i=n-1;i>1;i--){
            if(d[n]-d[i]==x){
                while(m>0&&q[m-1]>=i)m--;
                an+=m;
            }
        }
        printf("%I64d\n",an);
    }
}