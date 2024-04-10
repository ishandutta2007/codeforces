#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n, m, p;
pair<int,int> a[1000010], b[1000010];
struct nnode 
{
    int x,y,z;
}save[4*1000010];
vector<pair<int,int> >q[1000010];

struct node
{
    long long max,p;
}st[4*1000010];
void build(int t,int l,int r) 
{
    if (l==r) 
    {
        st[t].max=-b[l].second;
        st[t].p=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*t,l,mid);
    build(2*t+1,mid+1,r);
    st[t].max=max(st[2*t].max,st[2*t+1].max);
}
void clear(int t) 
{
    if (!st[t].p)return;
    st[2*t].max+=st[t].p;
    st[2*t+1].max+=st[t].p;
    st[2*t].p+=st[t].p;
    st[2*t+1].p+=st[t].p;
    st[t].p=0;
}
void modify(int t,int l,int r,int a,int b,int k) 
{
    if (a<=l && r<=b)
    {
        st[t].max+=k;
        st[t].p+=k;
        return;
    }
    clear(t);
    int mid=(l+r)/2;
    if (a<=mid)modify(2*t,l,mid,a,b,k);
    if (b>mid)modify(2*t+1,mid+1,r,a,b,k);
    st[t].max=max(st[2*t].max,st[2*t+1].max);
}
long long getmax(int t,int l,int r,int a,int b)
{
    if (a<=l && r<=b)return st[t].max;
    clear(t);
    int mid=(l+r)/2;
    long long ans=-2147483647ll*100000;
    if (a<=mid)ans=max(ans,getmax(2*t,l,mid,a,b));
    if (b>mid)ans=max(ans,getmax(2*t+1,mid+1,r,a,b));
    return ans;
}

int main() 
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].first,&a[i].second);
    for(int i=1;i<=m;i++)scanf("%d%d",&b[i].first,&b[i].second);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=n-1;i>=1;i--)a[i].second=min(a[i].second,a[i+1].second); a[n+1].second=1e9;
    for(int i=m-1;i>=1;i--)b[i].second=min(b[i].second,b[i+1].second); b[m+1].second=1e9;
    for(int i=1;i<=p;i++) 
    {
        scanf("%d%d%d",&save[i].x,&save[i].y,&save[i].z);
        save[i].x=lower_bound(a+1,a+n+1,mp(save[i].x+1,0))-a;
        save[i].y=lower_bound(b+1,b+m+1,mp(save[i].y+1,0))-b;
        if (save[i].x<=n && save[i].y<=m) 
            q[save[i].x].push_back(mp(save[i].y,save[i].z));
    }
    build(1,1,m);
    long long ans=-1e18;
    for (int i=1;i<=n;i++) 
    {
        for (auto t:q[i])modify(1,1,m,t.first,m,t.second);
        ans=max(ans,getmax(1,1,m,1,m)-a[i].second);
    }
    printf("%lld\n",ans);
}