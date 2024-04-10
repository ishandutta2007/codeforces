#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <pair <char, int> > sv[sz];
int q=0, us[sz], an[sz], dp[sz];
multiset <int> se;
void dfs(int v, int h)
{
    if(us[v])
    {
        dp[v]=min(dp[v], (*se.begin())+q+1);
        an[us[v]]=dp[v];
    }
    int x=dp[v]-q;
    se.insert(x);
    if(us[v]) q++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int to=sv[v][a].second;
        dp[to]=dp[v]+1, dfs(to, h+1);
    }
    se.erase(se.find(x));
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<=n; a++)
    {
        int pr;
        char s[2];
        scanf("%d%s", &pr, s);
        sv[pr].push_back({s[0], a});
    }
    for(int a=0; a<=n; a++) sort(sv[a].begin(), sv[a].end());
    int k;
    cin>>k;
    for(int a=1; a<=k; a++)
    {
        int v;
        scanf("%d", &v);
        us[v]=a;
    }
    dfs(0, 0);
    for(int a=1; a<=k; a++) printf("%d ", an[a]);
}