#include<bits/stdc++.h>
#define N 200000
using namespace std;
const int w=30;
const long long inf=1e18;
int n,m,b,s_num[w][N+5],bit[N+5],ans;
long long s_val[w][N+5],vala[N+5],valb[N+5];
pair<int,int> a[N+5];
struct segment_tree
{
    #define lson x<<1
    #define rson lson|1
    #define mid ((l+r)>>1)
    long long t1[N*4],t2[N*4];
    inline void build(int x,int l,int r,long long *a,long long *b)
    {
        if(l==r) return t1[x]=a[l],t2[x]=b[l],void();
        build(lson,l,mid,a,b),build(rson,mid+1,r,a,b);
        t1[x]=min(t1[lson],t1[rson]);
        t2[x]=min(t2[lson],t2[rson]);
    }
    inline int query1(int x,int l,int r,int le,long long val)
    {
        if(r<le || t1[x]>val) return n+1;
        if(l==r) return l;
        int lans=query1(lson,l,mid,le,val);
        return lans==n+1?query1(rson,mid+1,r,le,val):lans;
    }
    inline int query2(int x,int l,int r,int le,long long val)
    {
        if(r<le || t2[x]>val) return 0;
        if(l==r) return l;
        int rans=query2(rson,mid+1,r,le,val);
        return rans?rans:query2(lson,l,mid,le,val);
    }
    #undef lson
    #undef rson
    #undef mid
}tree[w];
int main()
{
    scanf("%d",&n);
    for(int i=1,c,q;i<=n;++i)
        scanf("%d %d",&c,&q),a[i]={-q,c};
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i)
    {
        bit[i]=31-__builtin_clz(a[i].second);
        for(int j=0;j<w;++j)
        {
            s_num[j][i]=s_num[j][i-1]+(j>bit[i]);
            s_val[j][i]=s_val[j][i-1]+(j>bit[i]?a[i].second:0);
        }
    }
    for(int j=0;j<w;++j)
    {
        s_num[j][n+1]=s_num[j][n];
        s_val[j][n+1]=s_val[j][n];
    }
    for(int j=0;j<w;tree[j++].build(1,1,n,vala,valb)) for(int i=1;i<=n;++i)
        vala[i]=(j==bit[i]?a[i].second+s_val[j][i]:inf),valb[i]=s_val[j][i];
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&b),ans=0;
        for(int p=1,j=w-1;j>=0;--j)
        {
            long long val=b+s_val[j][p-1];
            int x=tree[j].query1(1,1,n,p,val);
            if(x!=n+1)
            {
                ans+=s_num[j][x]-s_num[j][p-1]+1;
                b-=a[x].second+s_val[j][x]-s_val[j][p-1],p=x+1;
            }
        	else
            {
            	x=tree[j].query2(1,1,n,p-1,val);
            	ans+=s_num[j][x]-s_num[j][p-1];
            	b-=s_val[j][x]-s_val[j][p-1],p=x+1;
            }
        }
        printf("%d ",ans);
    }
    return 0;
}