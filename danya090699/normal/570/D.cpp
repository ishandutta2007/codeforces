#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
int n, m, tin[sz], tout[sz], he[sz], timer=0;
bitset <26> pref[sz];
char s[sz];
vector <int> sp[sz], sv[sz];
bool comp(int a, int b){return tin[a]<tin[b];}
bool comp2(int a, int b){return tout[a]<tout[b];}
void dfs(int v, int h)
{
    tin[v]=timer, timer++;
    he[v]=h;
    sp[h].push_back(v);
    pref[v][s[v]-'a']=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne, h+1);
    }
    tout[v]=timer, timer++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=1; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        sv[x-1].push_back(a);
    }
    for(int a=0; a<n; a++) scanf(" %c", &s[a]);
    dfs(0, 0);
    for(int a=0; a<n; a++)
    {
        for(int c=1; c<sp[a].size(); c++)
        {
            int pr=sp[a][c-1], cu=sp[a][c];
            pref[cu]^=pref[pr];
        }
    }
    for(int a=0; a<m; a++)
    {
        int v, h;
        scanf("%d%d", &v, &h);
        v--, h--;
        if(h<he[v]) printf("Yes\n");
        else
        {
            int l=lower_bound(sp[h].begin(), sp[h].end(), v, comp)-sp[h].begin();
            l--;
            int r=lower_bound(sp[h].begin(), sp[h].end(), v, comp2)-sp[h].begin();
            r--;
            bitset <26> qq;
            if(r!=-1) qq=pref[sp[h][r]];
            if(l!=-1) qq^=pref[sp[h][l]];
            if(qq.count()<2) printf("Yes\n");
            else printf("No\n");
        }
    }
}