#include <bits/stdc++.h>
using namespace std;
const int sz=100;
int dp[sz][3];
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, go[3], x=-1, y=-1;
        cin>>n>>go[0]>>go[1]>>go[2];
        for(int a=5; ; a++)
        {
            for(int i=0; i<3; i++)
            {
                bool us[4]={0, 0, 0, 0};
                for(int j=0; j<3; j++)
                {
                    if(!(i==j and i)) us[dp[a-go[j]][j]]=1;
                }
                for(int j=0; ; j++)
                {
                    if(!us[j])
                    {
                        dp[a][i]=j;
                        break;
                    }
                }
            }
            for(int b=a-1; b>=4; b--)
            {
                bool ok=1;
                for(int c=0; c<5; c++)
                {
                    for(int i=0; i<3; i++)
                    {
                        if(dp[a-c][i]!=dp[b-c][i])
                        {
                            ok=0;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(ok)
                {
                    x=b, y=a;
                    break;
                }
            }
            if(x!=-1) break;
        }
        int an=0, sum=0, s[n];
        for(int a=0; a<n; a++)
        {
            long long q;
            scanf("%lld", &q);
            q+=4;
            if(q>x)
            {
                q=x+(q-x)%(y-x);
                if(q==x) q=y;
            }
            s[a]=q, sum^=dp[q][0];
        }
        for(int a=0; a<n; a++)
        {
            sum^=dp[s[a]][0];
            for(int i=0; i<3; i++)
            {
                an+=(sum==dp[s[a]-go[i]][i]);
            }
            sum^=dp[s[a]][0];
        }
        printf("%d\n", an);
    }
}