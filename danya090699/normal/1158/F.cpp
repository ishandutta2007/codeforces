#include <bits/stdc++.h>
using namespace std;
const int bg=12, mod=998244353;
inline int sum(int a, int b)
{
    return (a+b<mod) ? (a+b) : (a+b-mod);
}
inline int dif(int a, int b)
{
    return (a-b>=0) ? (a-b) : (a-b+mod);
}
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, c;
    cin>>n>>c;
    int m=n/c, ar[n], an[n+1];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], ar[a]--;
        an[a]=0;
    }
    an[n]=0;
    if(c<bg)
    {
        int dp[m+1][1<<c], dp2[m+1][1<<c];
        for(int b=0; b<=m; b++) for(int mask=0; mask<(1<<c); mask++) dp[b][mask]=dp2[b][mask]=0;
        dp[0][0]=1;

        short int one=1;

        for(short int a=0; a<n; a++)
        {
            for(short int b=0; b<=m; b++)
            {
                for(short int mask=0; mask<(one<<c); mask++)
                {
                    if(dp[b][mask])
                    {
                        dp2[b][mask]=sum(dp2[b][mask], dp[b][mask]);

                        short int nmask=(mask|(one<<ar[a])), nb=b;
                        if(nmask==(one<<c)-one) nmask=0, nb++;

                        dp2[nb][nmask]=sum(dp2[nb][nmask], dp[b][mask]);
                    }
                }
            }
            for(short int b=0; b<=m; b++) for(short int mask=0; mask<(one<<c); mask++) dp[b][mask]=dp2[b][mask], dp2[b][mask]=0;
        }
        for(int a=0; a<=m; a++)
        {
            for(int mask=0; mask<(1<<c); mask++) an[a]=sum(an[a], dp[a][mask]);
        }
    }
    else
    {
        int st2[n+1], rev_st2[n+1];
        st2[0]=0, rev_st2[0]=0;
        for(int a=1; a<=n; a++)
        {
            st2[a]=(st2[a-1]*2+1)%mod;
            rev_st2[a]=po(st2[a], mod-2);
        }
        int add[n][n];
        for(int a=0; a<n; a++)
        {
            int q[c], dc=0, x=1;
            for(int i=0; i<c; i++) q[i]=0;
            for(int b=a; b<n; b++)
            {
                if(dc==c)
                {
                    x=(1ll*x*rev_st2[q[ar[b]]])%mod;
                    q[ar[b]]++;
                    x=(1ll*x*st2[q[ar[b]]])%mod;
                }
                else
                {
                    if(q[ar[b]]==0) dc++;
                    q[ar[b]]++;
                    if(dc==c)
                    {
                        for(int i=0; i<c; i++) x=(1ll*x*st2[q[i]])%mod;
                    }
                }
                if(dc==c)
                {
                    x=(1ll*x*rev_st2[q[ar[b]]])%mod;

                    add[a][b]=x;

                    x=(1ll*x*st2[q[ar[b]]])%mod;
                }
                else add[a][b]=0;
            }
        }
        int dp[n+1][m+1];
        for(int a=0; a<=n; a++) for(int b=0; b<=m; b++) dp[a][b]=0;
        dp[0][0]=1;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<m; b++)
            {
                if(dp[a][b])
                {
                    for(int r=n-1; r>=a; r--)
                    {
                        if(add[a][r]) dp[r+1][b+1]=(dp[r+1][b+1]+1ll*dp[a][b]*add[a][r])%mod;
                        else break;
                    }
                }
            }
        }
        int st=1, bad=0, q[c], dc=0;
        for(int i=0; i<c; i++) q[i]=0;
        for(int a=n; a>=0; a--)
        {
            if(a<n)
            {
                if(dc==c)
                {
                    bad=(1ll*bad*rev_st2[q[ar[a]]])%mod;
                    q[ar[a]]++;
                    bad=(1ll*bad*st2[q[ar[a]]])%mod;
                }
                else
                {
                    if(q[ar[a]]==0) dc++;
                    q[ar[a]]++;
                    if(dc==c)
                    {
                        bad=1;
                        for(int i=0; i<c; i++) bad=(1ll*bad*st2[q[i]])%mod;
                    }
                }
            }

            for(int b=0; b<=m; b++)
            {
                an[b]=(an[b]+1ll*dp[a][b]*dif(st, bad))%mod;
            }

            st=sum(st, st);
        }
    }
    an[0]=dif(an[0], 1);
    for(int a=0; a<=n; a++) cout<<an[a]<<" ";
}