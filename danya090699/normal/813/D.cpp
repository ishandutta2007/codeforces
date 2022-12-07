#include <bits/stdc++.h>
using namespace std;
const int sz=5010, sz2=1e5+10;
int be[sz][sz], be2[sz][7], ch[sz2], ch2[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    for(int a=0; a<sz2; a++) ch[a]=-1;
    int ar[n], m=1;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ch[ar[a]]=1;
    }
    for(int a=0; a<sz2; a++)
    {
        if(ch[a]==1)
        {
            ch[a]=m, ch2[m]=a, m++;
        }
    }
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++) be[a][b]=-1;
        for(int b=0; b<7; b++) be2[a][b]=-1;
    }
    be[0][0]=0;
    for(int a=0; a<n; a++)
    {
        int dp[m], nu=ch[ar[a]], nu2=ch[ar[a]-1], nu3=ch[ar[a]+1], os=ar[a]%7;
        for(int b=0; b<m; b++)
        {
            dp[b]=-1;
            dp[b]=max(dp[b], be[0][b]+1);
            if(nu2!=-1) dp[b]=max(dp[b], be[nu2][b]+1);
            if(nu3!=-1) dp[b]=max(dp[b], be[nu3][b]+1);
            dp[b]=max(dp[b], be2[b][os]+1);
        }
        for(int b=0; b<m; b++)
        {
            if(dp[b]>0)
            {
                if(b>0)
                {
                    an=max(an, dp[b]);
                    be2[nu][ch2[b]%7]=max(be2[nu][ch2[b]%7], dp[b]);
                }
                be[nu][b]=max(be[nu][b], dp[b]);
                be[b][nu]=max(be[b][nu], dp[b]);
                be2[b][os]=max(be2[b][os], dp[b]);
            }
        }
    }
    cout<<an;
}