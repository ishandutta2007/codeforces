#include<cstdio>
#include<vector>
#include<algorithm> 
#include<iostream>
#include<map>
#define N 100010
using namespace std;
vector<pair<int,int> > vec[N];
map<pair<int,int>,int> anss;
int a,b,c,n,m,i,j,q,k;
int l[N],r[N],f[N],ans[N];
int gf(int x)
{
    int p,t;
    p=x;
    while (p!=f[p]) p=f[p];
    while (x!=p)
    {
        t=f[x];
        f[x]=p;
        x=t;
    }
    return p;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        vec[c].push_back(make_pair(a,b));
    }
    for (i=1;i<=n;i++)
    f[i]=i; 
    scanf("%d",&q);
    for (i=1;i<=q;i++)
    scanf("%d%d",&l[i],&r[i]);
    for (i=1;i<=m;i++)
    {
        if (vec[i].size()==0) continue;
        vector<int> v;
        for (j=0;j<vec[i].size();j++)
        {
            v.push_back(vec[i][j].first);
            v.push_back(vec[i][j].second);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for (j=0;j<v.size();j++)
            f[v[j]]=v[j];
        for (j=0;j<vec[i].size();j++)
        f[gf(vec[i][j].first)]=gf(vec[i][j].second);
        int o=v.size();
        if (o*o>=n)
        {
            for (j=1;j<=q;j++)
            if (gf(l[j])==gf(r[j])) ans[j]++;
        }
        else
        {
            for (j=0;j<o;j++)
            for (k=j+1;k<o;k++)
            if (gf(v[j])==gf(v[k]))
            {
            anss[make_pair(v[j],v[k])]++;
            anss[make_pair(v[k],v[j])]++;
            }
        }
        for (j=0;j<v.size();j++)
        f[v[j]]=v[j];
    }
    for (i=1;i<=q;i++)
    printf("%d\n",ans[i]+anss[make_pair(l[i],r[i])]);
}