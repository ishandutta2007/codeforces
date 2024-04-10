#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],bit[N],val[N],l[N],r[N],vis[N];
struct node
{
    int l,r,val;
    node(int l,int r,int val):l(l),r(r),val(val){}
    bool operator<(const node&o)const
    {
        if(l==o.l) return r<o.r;
        return l<o.l;
    }
};
vector<node>v;
int f[N];
void add(int x,int val)
{
    while(x<=n) bit[x]=max(bit[x],val),x+=x&-x;
}
int query(int x)
{
    int ans=0;
    while(x)
        ans=max(ans,bit[x]),x-=x&-x;
    return ans;
}
int Dp()
{
    sort(v.begin(),v.end());
    int ans=0;
    for(node x:v)
    {
        int dp=query(x.l-1)+x.val;
        add(x.r,dp);
        ans=max(ans,dp);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),val[a[i]]++;
    for(int i=1;i<=n;i++) l[i]=n+1;
    for(int i=1;i<=n;i++) l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
    int ans=0;
    for(int i=1;i<=n;i++)
        if(r[i])
    {
        v.push_back(node(l[i],r[i],val[i]));
        ans+=val[i];
    }
    for(int i=n;i>=1;i--)
    {
        vis[a[i]]++;
        v.push_back(node(i,n,vis[a[i]]));
    }
    int dp=Dp();
    printf("%d\n",ans-dp);
}