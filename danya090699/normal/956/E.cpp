#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, r;
    cin>>n>>l>>r;
    int ar[n], su=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], su+=ar[a];
    }
    l=su-l, r=su-r, swap(l, r);
    vector <int> sp[2];
    for(int a=0; a<n; a++)
    {
        int ty;
        cin>>ty;
        sp[ty].push_back(ar[a]);
    }
    sort(sp[1].begin(), sp[1].end(), greater <int>());
    int dp[su+1], dp2[su+1];
    for(int a=0; a<=su; a++)
    {
        dp[a]=-1, dp2[a]=-1;
    }
    dp[0]=0;
    for(int i=0; i<2; i++)
    {
        for(int a=0; a<sp[i].size(); a++)
        {
            for(int b=0; b<=su; b++)
            {
                if(dp[b]!=-1)
                {
                    int c=b+sp[i][a], add=0;
                    if(i==1 and c>=l and c<=r) add=1;
                    dp2[b]=max(dp2[b], dp[b]);
                    dp2[c]=max(dp2[c], dp[b]+add);
                }
            }
            for(int b=0; b<=su; b++)
            {
                dp[b]=dp2[b], dp2[b]=-1;
            }
        }
    }
    int an=0;
    for(int a=0; a<=su; a++) an=max(an, dp[a]);
    cout<<an;
}