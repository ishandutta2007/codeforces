#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
const int nm=100005;
vector<int>v[nm];
int n,m,pr[nm],a,b;
struct fint
{
    int ind,x;
};
fint viz[nm];
bool cmp(fint a,fint b)
{
    if(a.x==b.x)
        return pr[a.ind]<pr[b.ind];
    return a.x<b.x;
}
void dfs(int nod,int nr)
{
    viz[nod].x=nr;
    for(int i=0;i<v[nod].size();i++)
        if(viz[v[nod][i]].x==0)
            dfs(v[nod][i],nr);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>pr[i];
    for(int i=1;i<=n;i++)
        viz[i].ind=i;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int nr=0;
    for(int i=1;i<=n;i++)
        if(viz[i].x==0)
            dfs(i,++nr);
    sort(viz+1,viz+n+1,cmp);
    long long sum=0;
    for(int i=1;i<=n;i++)
        if(viz[i].x!=viz[i-1].x)
            sum+=pr[viz[i].ind]*1ll;
    cout<<sum;
    return 0;
}
/**

**/