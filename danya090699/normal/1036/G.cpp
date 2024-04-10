#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> sv[sz];
int sq=0, dp[sz], to[sz];
int cou(int v)
{
    if(dp[v]==0)
    {
        if(sv[v].size()==0)
        {
            dp[v]=(1<<sq), sq++;
        }
        else
        {
            for(int a=0; a<sv[v].size(); a++) dp[v]|=cou(sv[v][a]);
        }
    }
    return dp[v];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), to[v]++;
    }
    vector <int> sp;
    for(int a=0; a<n; a++) if(to[a]==0) sp.push_back(cou(a));
    bool ok=1;
    for(int a=1; a<(1<<sq)-1; a++)
    {
        int mask=0;
        for(int i=0; i<sq; i++) if(a&(1<<i)) mask|=sp[i];
        if(__builtin_popcount(mask)==__builtin_popcount(a)) ok=0;
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}