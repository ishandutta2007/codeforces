#include<bits/stdc++.h>
#define N 100000
using namespace std;
inline int Div(int x,int y) {return (x-1)/y+1;}
int n,s[N+5],m[N+5],k[N+5];
namespace chairman_tree
{
    #define mid ((l+r)>>1)
    struct node
    {
        int lson,rson;
        long long m,k;
    }t[N<<5];
    int tot,root[N+5];
    inline void insert(const int &last,int &x,int l,int r,int p,int i)
    {
        x=++tot,t[x].m=t[last].m+m[i],t[x].k=t[last].k+k[i];if(l==r) return;
        if(p<=mid) t[x].rson=t[last].rson,insert(t[last].lson,t[x].lson,l,mid,p,i);
        else t[x].lson=t[last].lson,insert(t[last].rson,t[x].rson,mid+1,r,p,i);
    }
    inline long long querym(const int &x,int l,int r,int ri)
    {
        if(r<=ri) return t[x].m;
        if(l>ri) return 0;
        return querym(t[x].lson,l,mid,ri)+querym(t[x].rson,mid+1,r,ri);
    }
    inline long long queryk(const int &x,int l,int r,int le)
    {
        if(l>=le) return t[x].k;
        if(r<le) return 0;
        return queryk(t[x].lson,l,mid,le)+queryk(t[x].rson,mid+1,r,le);
    }
}
using namespace chairman_tree;
inline long long query(int l,int r,int time)
{
    static bool vis[N+5];
    if(l+1==r && !vis[r]) return vis[r]=1,min(s[r]+1ll*k[r]*time,1ll*m[r]);
    if(time>=N) return t[root[r]].m-t[root[l]].m;
    return querym(root[r],1,N,time)-querym(root[l],1,N,time)+
    (queryk(root[r],1,N,time+1)-queryk(root[l],1,N,time+1))*time;
}
set<int> se;
int last[N+5];
int main()
{
    scanf("%d",&n),se.insert(0);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d %d",s+i,m+i,k+i),se.insert(i);
        if(!k[i] || !m[i]) root[i]=root[i-1];
        else insert(root[i-1],root[i],1,N,Div(m[i],k[i]),i);
    }
    int q,l,r,time;
    scanf("%d",&q);
    while(q--)
    {
        long long ans=0;
        scanf("%d %d %d",&time,&l,&r);
        last[l-1]=last[*se.lower_bound(l-1)];
        set<int>::iterator end=se.insert(l-1).first;
        last[r]=last[*se.lower_bound(r)];
        for(set<int>::iterator it=se.insert(r).first;it!=end;se.erase(it--))
            ans+=query(*prev(it),*it,time-last[*it]);
        last[r]=time,se.insert(r);
        printf("%lld\n",ans);
    }
    return 0;
}