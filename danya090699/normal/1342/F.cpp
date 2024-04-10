#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int getpos(vector <int> &sp, int x)
{
    for(int a=0; ; a++)
    {
        if(sp[a]==x) return a;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int ar[n];
        vector <int> sp(n);
        for(int a=0; a<n; a++)
        {
            scanf("%d", &ar[a]);
            sp[a]=a;
        }
        int su[1<<n], dp[n+1][n+1][1<<n], pr[n+1][n+1][1<<n];
        for(int mask=0; mask<(1<<n); mask++)
        {
            su[mask]=0;
            for(int i=0; i<n; i++) if(mask&(1<<i)) su[mask]+=ar[i];
        }
        for(int a=0; a<=n; a++)
        {
            for(int q=0; q<=n; q++)
            {
                for(int mask=0; mask<(1<<n); mask++)
                {
                    dp[a][q][mask]=inf;
                }
            }
        }
        dp[0][0][(1<<n)-1]=0;
        for(int a=0; a<n; a++)
        {
            for(int q=0; q<=n; q++)
            {
                for(int mask=0; mask<(1<<n); mask++)
                {
                    if(dp[a][q][mask]!=inf)
                    {
                        if(dp[a+1][q][mask]>dp[a][q][mask])
                        {
                            dp[a+1][q][mask]=dp[a][q][mask];
                            pr[a+1][q][mask]=0;
                        }
                        if(mask&(1<<a))
                        {
                            for(int mask2=mask-(1<<a); ; mask2=(mask2-1)&(mask-(1<<a)))
                            {
                                int add=mask2+(1<<a);
                                if(dp[a][q][mask]<su[add] and dp[a+1][q+1][mask-add]>su[add])
                                {
                                    dp[a+1][q+1][mask-add]=su[add];
                                    pr[a+1][q+1][mask-add]=add;
                                }
                                if(mask2==0) break;
                            }
                        }
                    }
                }
            }
        }
        for(int q=n; q; q--)
        {
            if(dp[n][q][0]!=inf)
            {
                printf("%d\n", n-q);
                int mask=0;
                for(int a=n; a; a--)
                {
                    int add=pr[a][q][mask];
                    if(add)
                    {
                        for(int i=0; i<n; i++)
                        {
                            if(i!=a-1 and add&(1<<i))
                            {
                                int p1=getpos(sp, i), p2=getpos(sp, a-1);
                                printf("%d %d\n", p1+1, p2+1);
                                sp.erase(sp.begin()+p1);
                            }
                        }
                        mask+=add, q--;
                    }
                }
                break;
            }
        }
    }
}