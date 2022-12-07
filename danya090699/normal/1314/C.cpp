#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
const long long inf=1.5e18;
int cl[sz][10], p[sz][sz];
bool comp(pair <int, int> a, pair <int, int> b)
{
    int l1=a.second-a.first, l2=b.second-b.first, l=min(l1, l2);
    int i=31-__builtin_clz(l);
    if(cl[a.first][i]!=cl[b.first][i]) return cl[a.first][i]<cl[b.first][i];
    else
    {
        a.first+=l-(1<<i), b.first+=l-(1<<i);
        if(cl[a.first][i]!=cl[b.first][i]) return cl[a.first][i]<cl[b.first][i];
        else return l1<l2;
    }
}
main()
{
	//freopen("input.txt", "r", stdin);
    int n, m;
    long long k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    for(int i=0; (1<<i)<=n; i++)
    {
        vector <pair <string, int> > sp;
        for(int a=0; a+(1<<i)<=n; a++) sp.push_back({s.substr(a, 1<<i), a});
        sort(sp.begin(), sp.end());
        cl[sp[0].second][i]=0;
        for(int a=1; a<sp.size(); a++)
        {
            cl[sp[a].second][i]=cl[sp[a-1].second][i]+(sp[a-1].first<sp[a].first);
        }
    }
    vector <pair <int, int> > sp;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<=n; b++) sp.push_back({a, b});
    }
    sort(sp.begin(), sp.end(), comp);
    for(int a=0; a<sp.size(); a++) p[sp[a].first][sp[a].second]=a;

    int l=0, r=sp.size();
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        long long dp[n+1][m+1];
        for(int a=0; a<=n; a++) for(int b=0; b<=m; b++) dp[a][b]=0;
        dp[0][0]=1;
        for(int a=0; a<n; a++)
        {
            for(int b=a+1; b<=n; b++)
            {
                if(p[a][b]>=mid)
                {
                    for(int c=0; c<m; c++) dp[b][c+1]=min(inf, dp[b][c+1]+dp[a][c]);
                    break;
                }
            }
            for(int b=1; b<=m; b++) dp[a+1][b]=min(inf, dp[a+1][b]+dp[a][b]);
        }
        if(dp[n][m]>=k) l=mid;
        else r=mid;
    }
    cout<<s.substr(sp[l].first, sp[l].second-sp[l].first);
}