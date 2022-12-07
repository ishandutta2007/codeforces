#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
vector <int> sv[sz];
bool us[sz];
int cs;
void dfs(int v)
{
    us[v]=1, cs++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v, ty;
        scanf("%d%d%d", &u, &v, &ty);
        u--, v--;
        if(ty==0)
        {
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
    }
    int an=1;
    for(int a=0; a<k; a++) an=(1ll*an*n)%mod;
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            cs=0, dfs(a);
            int cu=1;
            for(int b=0; b<k; b++) cu=(1ll*cu*cs)%mod;

            an-=cu;
            if(an<0) an+=mod;
        }
    }
    cout<<an;
}