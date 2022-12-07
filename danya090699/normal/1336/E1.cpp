#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int SUM(int a, int b)
{
    return (a+b<mod) ? a+b : a+b-mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    int basis[m], an[m+1];
    for(int a=0; a<m; a++) basis[a]=0;
    for(int a=0; a<=m; a++) an[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        for(int i=m-1; i>=0; i--)
        {
            if(x&(1ll<<i))
            {
                if(basis[i]) x^=basis[i];
                else
                {
                    basis[i]=x, q++;
                    break;
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            if(basis[i])
            {
                for(int j=i+1; j<m; j++) if(basis[j]&(1ll<<i)) basis[j]^=basis[i];
            }
        }
    }
    int st=1;
    for(int a=0; a<n-q; a++) st=(st*2)%mod;

    if((1ll<<q)<(1ll<<(m-q))*q*q)
    {
        vector <int> sp;
        for(int i=0; i<m; i++) if(basis[i]) sp.push_back(basis[i]);
        int va[1<<q];
        va[0]=0;
        for(int mask=1; mask<(1<<q); mask++)
        {
            int i=__builtin_ctz(mask);
            va[mask]=sp[i]^va[mask-(1<<i)];
        }
        for(int mask=0; mask<(1<<q); mask++)
        {
            int bq=__builtin_popcountll(va[mask]);
            an[bq]=SUM(an[bq], st);
        }
    }
    else
    {
        int q2=m-q, dp[q+1][1<<q2], dp2[q+1][1<<q2];
        for(int a=0; a<=q; a++)
        {
            for(int mask=0; mask<(1<<q2); mask++)
            {
                dp[a][mask]=0, dp2[a][mask]=0;
            }
        }
        dp[0][0]=1;
        for(int i=0; i<m; i++)
        {
            if(basis[i])
            {
                int j=0, mask=0;
                for(int a=0; a<m; a++)
                {
                    if(!basis[a])
                    {
                        if(basis[i]&(1ll<<a)) mask+=(1<<j);
                        j++;
                    }
                }
                for(int a=0; a<=q; a++)
                {
                    for(int b=0; b<(1<<q2); b++)
                    {
                        if(dp[a][b])
                        {
                            dp2[a][b]=SUM(dp2[a][b], dp[a][b]);
                            dp2[a+1][b^mask]=SUM(dp2[a+1][b^mask], dp[a][b]);
                        }
                    }
                }
                for(int a=0; a<=q; a++)
                {
                    for(int b=0; b<(1<<q2); b++)
                    {
                        dp[a][b]=dp2[a][b], dp2[a][b]=0;
                    }
                }
            }
        }
        for(int a=0; a<=q; a++)
        {
            for(int b=0; b<(1<<q2); b++)
            {
                int bq=__builtin_popcount(b);
                an[a+bq]=(an[a+bq]+dp[a][b]*st)%mod;
            }
        }
    }
    for(int a=0; a<=m; a++) cout<<an[a]<<" ";
}