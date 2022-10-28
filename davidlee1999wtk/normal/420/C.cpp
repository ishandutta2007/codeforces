#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
using namespace std;
typedef long long LL;
struct Edge
{
    int from,to,pre;
}e[1000000];
int h[300005]={0},cou=0;
int c[300005],ed[300005];
void Addedge(int from,int to)
{
    cou++;
    e[cou]=((Edge){from,to,h[from]});
    h[from]=cou;
}

inline void update(int x)
{
    if(x==0)
    {
        c[0]++;
        return;
    }
    for(;x<=300000;x+=x&-x)
        c[x]++;
}
inline int get(int x)
{
    int sum=0;
    for(;x;x-=x&-x)
        sum+=c[x];
    return sum+c[0];
}
int main()
{
    LL ans=0;
    int sum,i,n,p,a,b,v,j;
    cin>>n>>p;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        Addedge(a,b); Addedge(b,a);
        ed[a]++; ed[b]++;
    }
    for(i=1;i<=n;i++)
        update(ed[i]);
    for(i=1;i<=n;i++)
    {
        if(ed[i]>=p)
            ans+=n-1;
        else
        {
            sum=n-get(p-ed[i]-1);
            if(ed[i]>=p-ed[i]) sum--;
            for(j=h[i];j;j=e[j].pre)
            {
                v=e[j].to;
                if(ed[v]==p-ed[i]) sum--;
                ed[v]--;
            }
            for(j=h[i];j;j=e[j].pre)
            {
                v=e[j].to;
                ed[v]++;
            }
            ans+=sum;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);