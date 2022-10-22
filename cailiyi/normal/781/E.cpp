#include<bits/stdc++.h>
#define N 100000
#define mod 1000000007
const int inf=2e9+10;
using namespace std;
int h,w,n,ans;
inline void add(int &a,const int &b) {if((a+=b)>=mod) a-=mod;}
struct segment
{
    int u,l,r,s;
    inline void read() {scanf("%d %d %d %d",&u,&l,&r,&s);}
    inline bool operator<(const segment &b) const {return u>b.u;}
}a[N+5];
namespace segment_tree
{
    #define mid ((l+r)>>1)
    #define lson x<<1
    #define rson x<<1|1
    vector<pair<int,int> > st[N+5];
    int t[N*4+5];
    inline int modify(int x,int l,int r,int le,int ri,int s)
    {
        if(l>ri || r<le || t[x]>s) return 0;
        int ret=0;
        if(l==r)
        {
            while(!st[l].empty() && st[l].back().first<=s)
                add(ret,st[l].back().second),st[l].pop_back();
            t[x]=st[l].empty()?inf:st[l].back().first;
            return ret;
        }
        add(ret,modify(lson,l,mid,le,ri,s));
        add(ret,modify(rson,mid+1,r,le,ri,s));
        t[x]=min(t[lson],t[rson]);
        return ret;
    }
    inline void insert(int x,int l,int r,int p,int s,int val)
    {
        if(l==r) return t[x]=s,st[l].push_back({s,val});
        p<=mid?insert(lson,l,mid,p,s,val):insert(rson,mid+1,r,p,s,val);
        t[x]=min(t[lson],t[rson]);
    }
}
using namespace segment_tree;
int main()
{
    scanf("%d %d %d",&h,&w,&n);
    for(int i=1;i<=w;++i) insert(1,1,w,i,h+1,1);
    for(int i=1;i<=n;++i) a[i].read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        int val=modify(1,1,w,a[i].l,a[i].r,a[i].u+a[i].s);
        insert(1,1,w,a[i].l==1?a[i].r+1:a[i].l-1,a[i].u,val);
        insert(1,1,w,a[i].r==w?a[i].l-1:a[i].r+1,a[i].u,val);
    }
    for(int i=1;i<=w;++i) while(!st[i].empty())
        add(ans,st[i].back().second),st[i].pop_back();
    printf("%d",ans);
    return 0;
}