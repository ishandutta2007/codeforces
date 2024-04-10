#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,k;
int w[100005];
int ans=0,sum,cnt=0;
int main()
{
    int i,j,l;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        sum=0;
        if(w[i]%k!=0)sum++;
        sum+=(w[i]/k);
        ans+=sum;
        }
    if(ans%2==1)cnt++;
    cnt+=(ans/2);
    printf("%d",cnt);
    return 0;
}