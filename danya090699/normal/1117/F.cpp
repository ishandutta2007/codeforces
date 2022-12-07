#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p;
    cin>>n>>p;
    char s[n+1];
    scanf("%s", s);
    int ma[p][p], pref[p], q[p];
    for(int a=0; a<p; a++)
    {
        pref[a]=-1, q[a]=0;
        for(int b=0; b<p; b++) cin>>ma[a][b];
    }
    vector <int> sp[p][p];
    for(int a=0; a<n; a++)
    {
        int sy=s[a]-'a';
        pair <int, int> ar[p];
        for(int b=0; b<p; b++) ar[b]={pref[b], b};
        int mask=0;
        sort(ar, ar+p, greater <pair <int, int> >());
        for(int b=0; (b<p and ar[b].first!=-1); b++)
        {
            int prsy=ar[b].second;
            if(ma[sy][prsy]==0)
            {
                if(sy<=prsy) sp[sy][prsy].push_back(mask);
                else sp[prsy][sy].push_back(mask);
            }
            mask+=(1<<prsy);
        }
        pref[sy]=a, q[sy]++;
    }
    int bad[1<<p];
    for(int a=0; a<(1<<p); a++) bad[a]=0;
    for(int a=0; a<p; a++)
    {
        for(int b=a; b<p; b++)
        {
            char dp[1<<p];
            for(int c=0; c<(1<<p); c++) dp[c]=0;
            for(int c=0; c<sp[a][b].size(); c++) dp[sp[a][b][c]]=1;
            for(int i=0; i<=p; i++)
            {
                for(int mask=0; mask<(1<<p); mask++)
                {
                    if(__builtin_popcount(mask)==i and dp[mask])
                    {
                        if((mask&(1<<a))==0 and (mask&(1<<b))==0)
                        {
                            bad[mask]=1;
                        }
                        for(int j=0; j<p; j++) if((mask&(1<<j))==0) dp[mask+(1<<j)]=1;
                    }
                }
            }
        }
    }
    int dp[1<<p], an=n;
    for(int a=0; a<(1<<p); a++) dp[a]=-1;
    dp[0]=0;
    for(int i=0; i<=p; i++)
    {
        for(int mask=0; mask<(1<<p); mask++)
        {
            if(__builtin_popcount(mask)==i and dp[mask]!=-1)
            {
                an=min(an, n-dp[mask]);
                for(int j=0; j<p; j++)
                {
                    if((mask&(1<<j))==0)
                    {
                        int nmask=mask+(1<<j);
                        if(bad[nmask]==0) dp[nmask]=dp[mask]+q[j];
                    }
                }
            }
        }
    }
    cout<<an;
}