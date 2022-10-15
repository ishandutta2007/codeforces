#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int nmax=2e5;
int n;
int score[nmax+5];
vector<int>v[nmax+5];
vector<int>v2[nmax+5];
bool viz[nmax+5];
ll S[nmax+5];
void dfs(int nod)
{
    ll adun=0;
    for(int i=0;i<v[nod].size();i++)
    {
        dfs(v[nod][i]);
        adun+=S[v[nod][i]];
    }
    S[nod]=adun+score[nod];
}
ll best[nmax+5];
ll cur=-1e18;
ll aux[nmax+5];
void dfs2(int nod)
{
    best[nod]=S[nod];
    for(int i=0;i<v[nod].size();i++)
    {
        dfs2(v[nod][i]);
        best[nod]=max(best[nod],best[v[nod][i]]);
    }
}
void build(int nod)
{
    viz[nod]=1;
    for(int i=0;i<v2[nod].size();i++)
    {
        if(viz[v2[nod][i]]==0)
        {
            viz[v2[nod][i]]=1;
            v[nod].push_back(v2[nod][i]);
            build(v2[nod][i]);
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>score[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }
    build(1);
    ///
    dfs(1);
    ///
    bool gresit=1;
    for(int i=1;i<=n;i++)
        if(v[i].size()>=2)
            gresit=0;
    if(gresit)
    {
        cout<<"Impossible";
        return 0;
    }
    dfs2(1);
    ll ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>=2)
        {
            for(int j=0;j<v[i].size();j++)
                aux[j]=best[v[i][j]];
            sort(aux,aux+v[i].size());
            reverse(aux,aux+v[i].size());
            ans=max(ans,aux[0]+aux[1]);
        }
    }
    cout<<ans;
    return 0;
}
/**

**/