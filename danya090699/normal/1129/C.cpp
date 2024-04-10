#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int z(string s)
{
    int n=s.size(), re=0;
    int zf[n], l=0, r=-1;
    zf[0]=0;
    for(int a=1; a<n; a++)
    {
        zf[a]=0;
        if(r>=a) zf[a]=min(zf[a-l], r-a+1);
        while(a+zf[a]<n)
        {
            if(s[zf[a]]==s[a+zf[a]]) zf[a]++;
            else break;
        }
        re=max(re, zf[a]);
        if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int dp[n][4][1<<3], dp2[n][4][1<<3];
    for(int a=0; a<n; a++)
    {
        for(int q=0; q<4; q++)
        {
            for(int m=0; m<(1<<q); m++)
            {
                dp[a][q][m]=0, dp2[a][q][m]=0;
            }
        }
    }
    int an=0;
    string s;
    for(int a=0; a<n; a++)
    {
        dp[a][0][0]=1;
        int x;
        cin>>x;
        s.push_back('0'+x);
        for(int b=0; b<=a; b++)
        {
            for(int q=0; q<4; q++)
            {
                for(int m=0; m<(1<<q); m++)
                {
                    int nm=m+(x<<q), cu=dp[b][q][m];
                    if(q+1<4)
                    {
                        dp2[b][q+1][nm]+=cu;
                        if(dp2[b][q+1][nm]>=mod) dp2[b][q+1][nm]-=mod;
                    }
                    if(q!=3 or (nm!=12 and nm!=10 and nm!=7 and nm!=15))
                    {
                        dp2[b][0][0]+=cu;
                        if(dp2[b][0][0]>=mod) dp2[b][0][0]-=mod;
                    }
                }
            }
        }
        reverse(s.begin(), s.end());
        int l=z(s);
        reverse(s.begin(), s.end());
        for(int b=0; b<=a; b++)
        {
            for(int q=0; q<4; q++)
            {
                for(int m=0; m<(1<<q); m++)
                {
                    dp[b][q][m]=dp2[b][q][m], dp2[b][q][m]=0;
                    if(q==0 and a+1-b>l)
                    {
                        an+=dp[b][q][m];
                        if(an>=mod) an-=mod;
                    }
                }
            }
        }
        cout<<an<<"\n";
    }
}