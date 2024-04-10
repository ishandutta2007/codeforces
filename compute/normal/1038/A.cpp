#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    int a[30];
    while(~scanf("%d%d",&n,&k))
    {
        memset(a,0,sizeof(a));
        string ss;
        cin>>ss;
        int ans=10000000;
        for(int i=0;i<n;i++)
        {
            a[ss[i]-'A'+1]++;
        }
        for(int i=1;i<=k;i++)
        {
            ans=min(ans,a[i]);
        }
        printf("%d\n",ans*k);
    }
    return 0;
}