#include<stdio.h>
typedef long long ll;
int main()
{
    int cnt=0;
    for(int i=0;i<2520;i++)
    {
        bool f=true;
        for(int j=2;j<=10;j++)if(i%j==0)f=false;
        if(f)cnt++;
    }
    ll z;
    scanf("%I64d",&z);
    ll ans=(z/2520)*cnt;
    z%=2520;
    for(int i=1;i<=z;i++)
    {
        bool f=true;
        for(int j=2;j<=10;j++)if(i%j==0)f=false;
        if(f)ans++;
    }
    printf("%I64d\n",ans);
}