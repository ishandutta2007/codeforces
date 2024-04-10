#include <bits/stdc++.h>

using namespace std;

const int nmax=1000;
int n,m,k;
int gov[nmax+5];
vector<int>v[nmax+5];
bool legat[nmax+5];/// e legat de guvern
void dfs(int nod)
{
    legat[nod]=1;
    for(int i=0;i<v[nod].size();i++)
        if(legat[v[nod][i]]==0)
            dfs(v[nod][i]);
}
int nr_indep=0;
int nr;
int comp[nmax+5],viz[nmax+5];///cate elemente are componenta

void dfs2(int nod)
{
    comp[nr]++;
    viz[nod]=1;
    for(int i=0;i<v[nod].size();i++)
        if(viz[v[nod][i]]==0)
            dfs2(v[nod][i]);
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        cin>>gov[i];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=k;i++)
        dfs(gov[i]);
    for(int i=1;i<=n;i++)
        if(legat[i]==0)
            nr_indep++;
    for(int i=1;i<=n;i++)
    {
        nr++;
        dfs2(gov[i]);
    }
    sort(comp+1,comp+nr+1);
    nr_indep+=comp[nr];
    int total=nr_indep*(nr_indep-1)/2;
    for(int i=1;i<nr;i++)
        total+=comp[i]*(comp[i]-1)/2;
    cout<<total-m;
    return 0;
}
/**


**/