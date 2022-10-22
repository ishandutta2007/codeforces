#include<bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
    return ans*f;
}

const int N=3005;
int t,n,sum[N][N],a[N],ans;

signed main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
        {
            a[i]=read();
            for(int j=1;j<=n;++j)
                sum[i][j]=sum[i-1][j];
            sum[i][a[i]]++;
            // 
        }
        ans=0;

        // j,k O(1)  
        for(int j=2;j<=n;++j)
            for(int k=j+1;k<=n-1;++k)
                ans+=(sum[j-1][a[k]])*(sum[n][a[j]]-sum[k][a[j]]);
        printf("%lld\n",ans);
    }
    return 0;
}