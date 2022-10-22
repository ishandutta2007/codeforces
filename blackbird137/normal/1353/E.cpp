#include<bits/stdc++.h>

using namespace std;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return ans*f;
}

const int N=1e6+5,inf=0x7f7f7f7f;
int t,n,k,dp[N][2],sum[N],ans;
char s[N]; 

int main()
{
    memset(dp,0x7f,sizeof(dp));
    //  dp 
    t=read();
    while(t--)
    {
        n=read();k=read();
        scanf("%s",s+1);
        for(int i=1;i<=n;++i)
        // 
            sum[i]=sum[i-1]+(s[i]-'0');
        ans=sum[n];  //  1  0 
        for(int i=1;i<=n;++i)
        {
            dp[i][0]=sum[i-1];
            // dp[i][0] 
            if(i-k>=1)
                dp[i][1]=min(dp[i-k][1]+sum[i-1]-sum[i-k],dp[i-k][0]+sum[i-1]-sum[i-k]);
            // dp[i][1] 
            if(s[i]=='0')
            {
                if(dp[i][0]!=inf)
                    dp[i][0]++;
                if(dp[i][1]!=inf)
                    dp[i][1]++;
            }

        }
        int num=0;
        //  num
        for(int i=n;i>=1;--i)
        {
            ans=min(ans,min(dp[i][1]+num,dp[i][0]+num));
            if(s[i]=='1')
                num++;
        }

        for(int i=1;i<=n;++i)
        //  memset  T
        {
            sum[i]=0;
            dp[i][0]=inf;
            dp[i][1]=inf;
        } 
        printf("%d\n",ans);
    }
    return 0;
}