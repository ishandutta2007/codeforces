#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, mod=1e9+7;
vector <int> sv[sz];
int us[sz];
int dfs(int v)
{
    us[v]=-1;
    int q=1;
    for(int a=0; a<sv[v].size(); a++) q+=dfs(sv[v][a]);
    return q;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1;
    cin>>n;
    int to[n*2];
    for(int a=0; a<n*2; a++)
    {
        to[a]=-1, us[a]=-2;
    }
    for(int a=0; a<n; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        to[u]=v;
        sv[v].push_back(u);
    }
    for(int a=0; a<n*2; a++) if(to[a]==-1) an=(1ll*an*dfs(a))%mod;
    for(int a=0; a<n*2; a++)
    {
        if(us[a]==-2)
        {
            int cu=a;
            while(us[cu]==-2)
            {
                us[cu]=a, cu=to[cu];
            }
            if(us[cu]==a and to[cu]!=cu) an=(an*2)%mod;
        }
    }
    cout<<an;
}