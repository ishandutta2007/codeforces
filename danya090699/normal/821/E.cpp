#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
struct ma
{
    int m[16][16];
};
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
void um(ma &m1, ma &m2, ma &re, int n)
{
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            re.m[a][b]=0;
            for(int c=0; c<n; c++)
            {
                re.m[a][b]+=m1.m[a][c]*m2.m[c][b];
                re.m[a][b]=re.m[a][b]%mod;
            }
        }
    }
}
ma po(int n, int st)
{
    ma an;
    if(st==0)
    {
        for(int a=0; a<n; a++) for(int b=0; b<n; b++) an.m[a][b]=(a==b);
    }
    else
    {
        if(st%2==0)
        {
            ma m1=po(n, st/2), m2;
            m2=m1;
            um(m1, m2, an, n);
        }
        else
        {
            ma m1=po(n, st-1), m2;
            for(int a=0; a<n; a++) for(int b=0; b<n; b++) m2.m[a][b]=(mo(a-b)<=1);
            um(m1, m2, an, n);
        }
    }
    return an;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int dp[n+1][16];
    for(int a=0; a<=n; a++) for(int b=0; b<=15; b++) dp[a][b]=0;
    dp[0][0]=1;
    for(int a=0; a<n; a++)
    {
        int l, r, h;
        cin>>l>>r>>h;
        r=min(r, k);
        ma nel=po(h+1, r-l);
        for(int b=0; b<=h; b++)
        {
            for(int c=0; c<=h; c++)
            {
                dp[a+1][b]+=dp[a][c]*nel.m[c][b];
                dp[a+1][b]=dp[a+1][b]%mod;
            }
        }
    }
    cout<<dp[n][0];
}