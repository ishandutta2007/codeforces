//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int n, mod, ef=1, st10[sz], rev[sz], si[sz], cuq, qq, sq, ar[sz][3];
long long an=0;
vector <pair <int, int> > sv[sz];
map <int, int> ma;
int pow(int x, int y)
{
    if(y==0) return 1%mod;
    else if(y%2==1) return (1ll*pow(x, y-1)*x)%mod;
    else
    {
        int x2=pow(x, y/2);
        return (1ll*x2*x2)%mod;
    }
}
void siz(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(ne!=pr)
        {
            siz(ne, v);
            si[v]+=si[ne];
        }
    }
}
int find_ce(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first;
        if(ne!=pr and si[ne]>cuq/2) return find_ce(ne, v);
    }
    if(pr!=-1) si[pr]=cuq-si[v];
    return v;
}
void dfs2(int v, int pr, int h, int v1, int v2)
{
    ar[qq][0]=v2, ar[qq][1]=h, ar[qq][2]=v1, qq++, sq++;
    ma[v1]++;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, zi=sv[v][a].second;
        if(ne!=pr)
        {
            dfs2(ne, v, h+1, (v1+1ll*st10[h]*zi)%mod, (1ll*v2*10+zi)%mod);
        }
    }
}
void dfs(int v, int q)
{
    cuq=q;
    siz(v, -1);
    int ce=find_ce(v, -1);
    qq=1;
    vector <int> len(1);
    len[0]=1;
    ar[0][0]=0, ar[0][1]=0, ar[0][2]=0;
    ma[0]++;
    for(int a=0; a<sv[ce].size(); a++)
    {
        int ne=sv[ce][a].first, zi=sv[ce][a].second;
        sq=0, dfs2(ne, ce, 1, zi%mod, zi%mod);
        len.push_back(sq);
    }
    int yk=0;
    for(int a=0; a<len.size(); a++)
    {
        for(int b=yk; b<yk+len[a]; b++) ma[ar[b][2]]--;
        for(int b=yk; b<yk+len[a]; b++)
        {
            int v2=ar[b][0], h=ar[b][1], v1=ar[b][2];
            int x=(mod-v2)%mod;
            x=(1ll*x*rev[h])%mod;
            if(ma.find(x)!=ma.end()) an+=ma[x];
        }
        for(int b=yk; b<yk+len[a]; b++) ma[ar[b][2]]++;
        yk+=len[a];
    }
    ma.clear();
    while(sv[ce].size()>0)
    {
        int ne=sv[ce].back().first;
        for(int a=0; a<sv[ne].size(); a++)
        {
            if(sv[ne][a].first==ce) sv[ne].erase(sv[ne].begin()+a);
        }
        sv[ce].pop_back();
        dfs(ne, si[ne]);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>mod;
    st10[0]=1%mod;
    for(int a=1; a<n; a++) st10[a]=(1ll*st10[a-1]*10)%mod;
    int x=mod;
    for(int a=2; a*a<=x; a++)
    {
        if(x%a==0)
        {
            int x2=1;
            while(x%a==0)
            {
                x/=a, x2*=a;
            }
            ef*=(x2-(x2/a));
        }
    }
    if(x>1) ef*=x-1;
    for(int a=0; a<n; a++) rev[a]=pow(st10[a], ef-1);
    for(int a=0; a<n-1; a++)
    {
        int u, v, zi;
        scanf("%d%d%d", &u, &v, &zi);
        sv[u].push_back(make_pair(v, zi));
        sv[v].push_back(make_pair(u, zi));
    }
    dfs(0, n);
    cout<<an;
}