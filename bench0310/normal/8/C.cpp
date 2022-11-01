#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int n;
    scanf("%d",&n);
    vector<array<int,2>> v(n);
    for(int i=0;i<n;i++) scanf("%d%d",&v[i][0],&v[i][1]);
    auto sq=[](int a)->int{return a*a;};
    auto one=[&](int a)->int{return 2*(sq(v[a][0]-x)+sq(v[a][1]-y));};
    auto two=[&](int a,int b)->int{return one(a)/2+one(b)/2+sq(v[a][0]-v[b][0])+sq(v[a][1]-v[b][1]);};
    vector<int> dp((1<<n),(1<<30));
    vector<array<int,2>> p((1<<n),{-1,-1});
    dp[0]=0;
    for(int o=0;o<(1<<n)-1;o++)
    {
        if(dp[o]==(1<<30)) continue;
        vector<int> b;
        for(int i=0;i<n;i++) if((o&(1<<i))==0) b.push_back(i);
        int j=b[0];
        for(int i:b)
        {
            if(i==j)
            {
                if(dp[o]+one(i)<dp[o^(1<<i)])
                {
                    dp[o^(1<<i)]=dp[o]+one(i);
                    p[o^(1<<i)]={i,-1};
                }
            }
            else
            {
                if(dp[o]+two(i,j)<dp[o|(1<<i)|(1<<j)])
                {
                    dp[o|(1<<i)|(1<<j)]=dp[o]+two(i,j);
                    p[o|(1<<i)|(1<<j)]={i,j};
                }
            }
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
    int now=(1<<n)-1;
    while(now)
    {
        array<int,2> z=p[now];
        printf("0 ");
        for(int i=0;i<2;i++)
        {
            if(z[i]!=-1)
            {
                printf("%d ",z[i]+1);
                now^=(1<<z[i]);
            }
        }
    }
    printf("0\n");
    return 0;
}