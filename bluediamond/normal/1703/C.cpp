#include<bits/stdc++.h>
using namespace std;
int solve()
{
    int n,a[105];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int b;
        char s[15];
        scanf("%d%s",&b,s);
        for(int j=0;j<b;j++)
        {
            if(s[j]=='D')a[i]=(a[i]+1)%10;
            else a[i]=(a[i]+9)%10;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}