#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
int de(int x, int y){return (1ll*x*po(y, mod-2))%mod;}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, m=0;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(ar[a]==0) m++;
    }
    int re[m+1][m+1], ma[m+1][m+1];
    for(int a=0; a<=m; a++)
    {
        for(int b=0; b<=m; b++) ma[a][b]=0, re[a][b]=(a==b);
        if(m-a<=n-m)
        {
            int tot=n*(n-1)/2, lef=tot, q00=a, q10=m-a, q01=m-a, q11=n-m-q10;
            if(q00 and q11)
            {
                ma[a][a-1]=de(q00*q11, tot);
                lef-=q00*q11;
            }
            if(q10 and q01)
            {
                ma[a][a+1]=de(q10*q01, tot);
                lef-=q10*q01;
            }
            ma[a][a]=de(lef, tot);
        }
    }
    while(k)
    {
        if(k&1)
        {
            int t[m+1][m+1];
            for(int a=0; a<=m; a++)
            {
                for(int b=0; b<=m; b++)
                {
                    t[a][b]=0;
                    for(int c=0; c<=m; c++) t[a][b]=(t[a][b]+1ll*re[a][c]*ma[c][b])%mod;
                }
            }
            for(int a=0; a<=m; a++) for(int b=0; b<=m; b++) re[a][b]=t[a][b];
        }
        k>>=1;
        int t[m+1][m+1];
        for(int a=0; a<=m; a++)
        {
            for(int b=0; b<=m; b++)
            {
                t[a][b]=0;
                for(int c=0; c<=m; c++) t[a][b]=(t[a][b]+1ll*ma[a][c]*ma[c][b])%mod;
            }
        }
        for(int a=0; a<=m; a++) for(int b=0; b<=m; b++) ma[a][b]=t[a][b];
    }
    int s=0;
    for(int a=0; a<m; a++) if(ar[a]==0) s++;
    cout<<re[s][m];
}