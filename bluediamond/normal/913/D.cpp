#include <bits/stdc++.h>
using namespace std;
const int nmax=200000;
struct data
{
    int nr,t,ind;
};
int n,t,aux[nmax+5],afis[nmax+5];
data v[nmax+5];
int r=0,pas=1<<25;
bool ok(int val)
{
    int nr=0;
    for(int i=1;i<=n;i++)
        if(v[i].nr>=val)
            nr++;
    if(nr<val)
        return 0;
    return 1;
}
bool cmpaux(int a,int b)
{
    return v[a].t<v[b].t;
}
int best_sum(int val)
{
    int y=0;
    for(int i=1;i<=n;i++)
        if(v[i].nr>=val)
            aux[++y]=i;
    sort(aux+1,aux+y+1,cmpaux);
    int sum=0;
    for(int i=1;i<=val;i++)
        sum+=v[aux[i]].t;
    if(sum<=t)
        for(int i=1;i<=val;i++)
            afis[i]=v[aux[i]].ind;
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].nr>>v[i].t;
        v[i].ind=i;
    }
    while(pas)
    {
        if(r+pas<=n and ok(r+pas) and best_sum(r+pas)<=t)
            r+=pas;
        pas/=2;
    }
    cout<<r<<"\n"<<r<<"\n";
    for(int i=1;i<=r;i++)
        cout<<afis[i]<<" ";
    return 0;
}
/**
**/