#include <bits/stdc++.h>
using namespace std;
const int al=26, inf=1e9;
void build_pf(string s, int (*aut)[al])
{
    int n=s.size();
    int pf[n];
    pf[0]=0;
    for(int a=1; a<n; a++)
    {
        int t=pf[a-1];
        while(t)
        {
            if(s[t]!=s[a]) t=pf[t-1];
            else break;
        }
        if(s[t]==s[a]) t++;
        pf[a]=t;
    }

    for(int a=0; a<n; a++)
    {
        for(int i=0; i<al; i++)
        {
            if(s[a]-'a'==i) aut[a][i]=a+1;
            else
            {
                if(a) aut[a][i]=aut[pf[a-1]][i];
                else aut[a][i]=0;
            }
        }
    }
    for(int i=0; i<al; i++) aut[n][i]=aut[pf[n-1]][i];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string st, s, t;
    cin>>st>>s>>t;
    int n=s.size(), m=t.size();
    int saut[n+1][al], taut[m+1][al];
    build_pf(s, saut), build_pf(t, taut);

    int dp[n+1][m+1], dp2[n+1][m+1];
    for(int a=0; a<=n; a++)
    {
        for(int b=0; b<=m; b++)
        {
            dp[a][b]=-inf, dp2[a][b]=-inf;
        }
    }
    dp[0][0]=0;
    for(int a=0; a<st.size(); a++)
    {
        int l=0, r=25;
        if(st[a]!='*') l=st[a]-'a', r=l;
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<=m; c++)
            {
                if(dp[b][c]!=-inf)
                {
                    for(int d=l; d<=r; d++)
                    {
                        int nb=saut[b][d], nc=taut[c][d], add=0;
                        if(nb==n) add++;
                        if(nc==m) add--;
                        dp2[nb][nc]=max(dp2[nb][nc], dp[b][c]+add);
                    }
                }
            }
        }
        for(int b=0; b<=n; b++)
        {
            for(int c=0; c<=m; c++)
            {
                dp[b][c]=dp2[b][c], dp2[b][c]=-inf;
            }
        }
    }
    int an=-inf;
    for(int a=0; a<=n; a++) for(int b=0; b<=m; b++) an=max(an, dp[a][b]);
    cout<<an;
}