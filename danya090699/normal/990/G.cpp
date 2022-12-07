#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz], sp[sz];
bool us[sz];
int csi;
long long an[sz];
void dfs(int v)
{
    us[v]=0, csi++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        sp[x].push_back(a);
    }
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=1; a<sz; a++)
    {
        vector <int> ve;
        for(int b=a; b<sz; b+=a)
        {
            for(int c=0; c<sp[b].size(); c++)
            {
                ve.push_back(sp[b][c]);
                us[sp[b][c]]=1;
            }
        }
        for(int b=0; b<ve.size(); b++)
        {
            if(us[ve[b]])
            {
                csi=0, dfs(ve[b]);
                an[a]+=(1ll*csi*(csi-1))/2+csi;
            }
        }
    }
    for(int a=sz-1; a>0; a--)
    {
        for(int b=a+a; b<sz; b+=a) an[a]-=an[b];
    }
    for(int a=1; a<sz; a++)
    {
        if(an[a]) printf("%d %lld\n", a, an[a]);
    }
}