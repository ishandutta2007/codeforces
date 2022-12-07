#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=s.size();
    int pf[m];
    pf[0]=0;
    for(int a=1; a<m; a++)
    {
        pf[a]=pf[a-1];
        while(pf[a]>0 and s[a]!=s[pf[a]]) pf[a]=pf[pf[a]-1];
        if(s[a]==s[pf[a]]) pf[a]++;
        //cout<<pf[a]<<" ";
    }
    int aut[m+1][2];
    for(int a=0; a<=m; a++)
    {
        for(int i=0; i<2; i++)
        {
            if(a<m)
            {
                //cout<<i<<""
                if(i!=(s[a]-'0'))
                {
                    if(a) aut[a][i]=aut[pf[a-1]][i];
                    else aut[a][i]=0;
                }
                else aut[a][i]=a+1;
            }
            else aut[a][i]=aut[pf[a-1]][i];

            //cout<<aut[a][i]<<" ";
        }
        //cout<<"\n";
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int dp[a+1][m+1];
        for(int b=0; b<=a; b++) for(int c=0; c<=m; c++) dp[b][c]=0;
        dp[0][0]=1;
        for(int b=0; b<a; b++)
        {
            for(int c=0; c<=m; c++)
            {
                int va=dp[b][c];
                if(va)
                {
                    for(int i=0; i<2; i++)
                    {
                        int ne=aut[c][i];
                        if(ne!=m)
                        {
                            int nu=n+b-a;
                            if(nu<m)
                            {
                                if(s[nu]-'0'==i) dp[b+1][ne]+=va;
                            }
                            else dp[b+1][ne]+=va;
                        }
                    }
                }
            }
        }
        for(int c=0; c<m; c++)
        {
            int cu=c, ok=1;
            //if(a==2 and dp[a][c]) cout<<dp[a][c]<<" ";
            for(int d=0; d<m; d++)
            {
                if(cu==m)
                {
                    ok=0;
                    break;
                }
                else cu=aut[cu][s[d]-'0'];
            }
            if(ok)
            {
                if(a+m<n) an+=(1ll<<(n-a-m))*dp[a][c];
                else an+=dp[a][c];
            }
        }
        //cout<<an<<" ";
    }
    cout<<an;
}