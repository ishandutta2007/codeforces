//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=110, sz2=2010;;
int ar[sz][3], p[sz];
bool comp(int a, int b){return (ar[a][1]<ar[b][1]);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        p[a]=a;
        for(int b=0; b<3; b++) cin>>ar[a][b];
    }
    sort(p, p+n, comp);
    int dp[n+1][sz2], pr[n+1][sz2];
    for(int a=0; a<=n; a++) for(int b=0; b<sz2; b++) dp[a][b]=-1;
    dp[0][0]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sz2; b++)
        {
            if(dp[a][b]!=-1)
            {
                if(dp[a+1][b]<dp[a][b])
                {
                    dp[a+1][b]=dp[a][b];
                    pr[a+1][b]=b;
                }
                int t=ar[p[a]][0], d=ar[p[a]][1], pri=ar[p[a]][2];
                if(b+t<d)
                {
                    if(dp[a+1][b+t]<dp[a][b]+pri)
                    {
                        dp[a+1][b+t]=(dp[a][b]+pri);
                        pr[a+1][b+t]=b;
                    }
                }
            }
        }
    }
    int be=0, cu;
    for(int a=0; a<sz2; a++)
    {
        if(dp[n][a]>=be)
        {
            be=dp[n][a];
            cu=a;
        }
    }
    vector <int> an;
    for(int a=n-1; a>=0; a--)
    {
        int ne=pr[a+1][cu];
        if(ne!=cu) an.push_back(p[a]+1);
        cu=ne;
    }
    cout<<be<<"\n"<<an.size()<<"\n";
    reverse(an.begin(), an.end());
    for(int a=0; a<an.size(); a++) cout<<an[a]<<" ";
}