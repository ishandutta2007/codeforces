#include<stdio.h>
bool p[1000];
int an[1001],q[1000],qn;
main(){
    int i,j,k;
    for(i=2;i*i<1000;i++)
        if(!p[i])
            for(j=i+i;j<1000;j+=i)p[j]=1;
    for(i=2;i<1000;i++)
        if(!p[i])q[qn++]=i;
    for(i=0;i<qn&&q[i]+q[i+1]+1<1000;i++)
        if(!p[q[i]+q[i+1]+1])an[q[i]+q[i+1]+1]=1;
    for(i=2;i<=1000;i++)an[i]+=an[i-1];
    scanf("%d%d",&i,&j);
    if(an[i]>=j)puts("YES");
    else puts("NO");
}