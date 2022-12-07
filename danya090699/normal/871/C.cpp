#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, mod=1e9+7;
vector <int> sv[sz*2];
map <int, int> x, y;
int q=0, qq, st[sz*2];
bool us[sz*2], cy;
void dfs(int v, int pr)
{
    us[v]=1, qq++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(us[ne]) cy=1;
            else dfs(ne, v);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1;
    cin>>n;
    st[0]=1;
    for(int a=1; a<=n*2; a++) st[a]=(st[a-1]*2)%mod;
    for(int a=0; a<n; a++)
    {
        int cx, cy;
        scanf("%d%d", &cx, &cy);
        if(x.find(cx)==x.end())
        {
            x[cx]=q, q++;
        }
        if(y.find(cy)==y.end())
        {
            y[cy]=q, q++;
        }
        int u=x[cx], v=y[cy];
        sv[v].push_back(u);
        sv[u].push_back(v);
    }
    for(int a=0; a<q; a++)
    {
        if(us[a]==0)
        {
            cy=0, qq=0, dfs(a, -1);
            qq=st[qq];
            if(cy==0) qq--;
            an=(1ll*an*qq)%mod;
        }
    }
    cout<<an;
}