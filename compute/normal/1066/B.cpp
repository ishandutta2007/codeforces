#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,r;
    int arr[5005];
    while(~scanf("%d%d",&n,&r))
    {
        memset(arr,0,sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int ans=0;
        int flag=0;
        int i=-r+1;
        while(i+r-1<n)
        {
            for(int j=i+2*r-1;j>i;j--)
            {
                if(j<0)
                {
                    flag=1;
                    break;
                }
                if(arr[j])
                {
                    ans++;
                    i=j;
                    break;
                }
                if(j==i+1||j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) ans=-1;
        cout<<ans<<endl;
    }

}