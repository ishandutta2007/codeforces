#include<bits/stdc++.h>
using namespace std;
const int nmax=300000;
int n,m,val[nmax+5];
vector<int>v[nmax+5];
int sol[nmax+5][30];
bool use[nmax+5];
char ch;
void slove(int nod)
{
    sol[nod][val[nod]]=1;
    use[nod]=1;
    for(int i=0;i<v[nod].size();i++)
    {
        int nod_nou=v[nod][i];
        if(use[nod_nou]==0)
            slove(nod_nou);
        for(int j=0;j<26;j++)
        {
            int value=sol[nod_nou][j];
            if(j==val[nod])
                value++;
            sol[nod][j]=max(sol[nod][j],value);
        }
    }
}
bool use_topol[nmax+5];
bool momentan[nmax+5];
bool ciclu=0;
void dfs_topologic(int nod)
{
    if(ciclu==1)
        return;
    momentan[nod]=1;
    for(int i=0;i<v[nod].size();i++)
    {
        int nod_nou=v[nod][i];
        if(momentan[nod_nou])
        {
            ciclu=1;
            return;
        }
        if(use_topol[nod_nou]==0)
            dfs_topologic(nod_nou);
    }
    momentan[nod]=0;
    use_topol[nod]=1;
}
int main()
{
    cin>>n>>m;
    cin.get();
    for(int i=1;i<=n;i++)
    {
        ch=cin.get();
        val[i]=ch-'a';
    }
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(!use_topol[i])
            dfs_topologic(i);
    if(ciclu==1)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(use[i]==0)
            slove(i);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<26;j++)
            ans=max(ans,sol[i][j]);
    cout<<ans;
    return 0;
}