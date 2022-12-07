#include <bits/stdc++.h>
using namespace std;
struct el
{
    int a, b, i;
    bool operator < (el x)
    {
        return b<x.b;
    }
};
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n, k;
        cin>>n>>k;
        el ar[n];
        for(int a=0; a<n; a++)
        {
            cin>>ar[a].a>>ar[a].b;
            ar[a].i=a+1;
        }
        sort(ar, ar+n);
        int dp[n+1][k+1], pr[n+1][k+1];
        for(int a=0; a<=n; a++) for(int b=0; b<=k; b++) dp[a][b]=-1;
        dp[0][0]=0;
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<=k; b++)
            {
                if(dp[a][b]!=-1)
                {
                    int va=dp[a][b]+(k-1)*ar[a].b;
                    if(dp[a+1][b]<va)
                    {
                        dp[a+1][b]=va;
                        pr[a+1][b]=0;
                    }
                    va=dp[a][b]+b*ar[a].b+ar[a].a;
                    if(b<k and dp[a+1][b+1]<va)
                    {
                        dp[a+1][b+1]=va;
                        pr[a+1][b+1]=1;
                    }
                }
            }
        }
        int s=k;
        vector <int> in, out;
        for(int a=n; a; a--)
        {
            if(pr[a][s])
            {
                in.push_back(ar[a-1].i), s--;
            }
            else out.push_back(ar[a-1].i);
        }
        reverse(in.begin(), in.end());
        cout<<k+(n-k)*2<<"\n";
        for(int a=0; a<k-1; a++) cout<<in[a]<<" ";
        for(int a=0; a<out.size(); a++) cout<<out[a]<<" -"<<out[a]<<" ";
        cout<<in[k-1]<<"\n";
    }
}