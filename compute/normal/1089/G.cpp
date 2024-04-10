#include <bits/stdc++.h>
using namespace std;

int a[7];

int main(void)
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k;
        scanf("%d",&k);
        
        int tem=0;
        for(int i=0;i<7;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)
                tem++;
        }
        int t=(k-1)%tem+1;
       // printf("tem%d\n",tem);
        if(t==0)

        int maxx=-1;
        bool flag=false;
        int minn=10;
        for(int i=0;i<7;i++)
        {
            int cnt=0;
            for(int j=0;j<7;j++)
            {
                if(a[(i+j)%7]==1)
                    cnt++;
                if(cnt==t)
                {
                    if((j+1)<minn)
                    {
                        minn=j+1;
                    }
                    break;
                }
            }
        }
//        printf("debug %d\n",minn);
        if(k<tem)
        {
            printf("%d\n",minn);
            continue;
        }
        int ans=0;
        if(k%tem==0)
            ans=(k)/tem-1;
        else
            ans=k/tem;
        ans*=7;
        ans+=minn;
        cout<<ans<<endl;
    }
    return 0;
}