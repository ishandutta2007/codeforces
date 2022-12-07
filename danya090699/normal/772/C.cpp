#include <bits/stdc++.h>
using namespace std;
int n, m, f=0;
int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}
int pow(int x, int y)
{
    if(y==0) return 1%m;
    if(y%2) return (1ll*pow(x, y-1)*x)%m;
    else
    {
        int va=pow(x, y/2);
        return (1ll*va*va)%m;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=1; a<=m; a++) if(gcd(a, m)==1) f++;
    int us[m];
    for(int a=0; a<m; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        us[x]=1;
    }
    vector <int> ch[m], div;
    for(int a=1; a<m; a++) if(us[a]==0) ch[gcd(a, m)].push_back(a);
    int dp[m], q[m], pr[m];
    for(int a=0; a<m; a++)
    {
        pr[a]=-1;
        dp[a]=ch[a].size();
        q[a]=dp[a];
        if(dp[a]!=0) div.push_back(a);
    }
    for(int a=1; a<m; a++)
    {
        if(dp[a]!=0)
        {
            for(int b=0; b<div.size(); b++)
            {
                if(div[b]%a==0 and div[b]>a)
                {
                    if(dp[div[b]]<dp[a]+q[div[b]])
                    {
                        dp[div[b]]=dp[a]+q[div[b]];
                        pr[div[b]]=a;
                    }
                }
            }
        }
    }
    int cu=-1, best=-1;
    for(int a=1; a<m; a++)
    {
        if(dp[a]>best)
        {
            best=dp[a], cu=a;
        }
    }
    vector <int> pref;
    while(cu!=-1)
    {
        for(int a=0; a<ch[cu].size(); a++) pref.push_back(ch[cu][a]);
        cu=pr[cu];
    }
    reverse(pref.begin(), pref.end());
    if(us[0]==0) pref.push_back(0);
    cout<<pref.size()<<"\n";
    for(int a=0; a<pref.size(); a++)
    {
        if(a==0) printf("%d ", pref[0]);
        else
        {
            int d=gcd(pref[a-1], m);
            int x=pref[a-1]/d, y=pref[a]/d, z=m/d;
            printf("%d ", (1ll*y*pow(x, f-1))%m);
        }
    }
}