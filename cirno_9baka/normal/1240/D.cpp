#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
const int N=1000005;
#define ri register int 
int n,i,k,u,v,w,l[500005],dp[500005],a[500005],j,q,rt[500005];
ll ans;
struct Persistable_Segment_Tree{
    int lc[N*20],rc[N*20],val[N*20],cnt;
    inline void build(int &o,int l,int r){
        o=++cnt;
        if(l==r){val[o]=0;return;}
        int mid=(l+r)>>1;
        build(lc[o],l,mid);build(rc[o],mid+1,r);
    }
    inline void ins(int &o,int pre,int l,int r,int q,int v){
        o=++cnt;lc[o]=lc[pre];rc[o]=rc[pre];val[o]=val[pre];
        if(l==r){val[o]=v;return;}
        int mid=(l+r)>>1;
        if(q<=mid)ins(lc[o],lc[pre],l,mid,q,v);
        else ins(rc[o],rc[pre],mid+1,r,q,v);
    }
    inline int query(int o,int l,int r,int q){
        if(l==r)return val[o];
        int mid=(l+r)>>1;
        if(q<=mid)return query(lc[o],l,mid,q);
        else return query(rc[o],mid+1,r,q);
    }
}T;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		l[0]=-1;
		for(i=0;i<=T.cnt;i++)
			T.lc[i]=T.rc[i]=T.val[i]=0;
		T.cnt=0;
		T.build(rt[0],1,n);
		for(i=1;i<=n;i++)
		{
			int x=T.query(rt[i-1],1,n,a[i]);
			if(x!=0)
			{
				l[i]=x-1;
				T.ins(rt[i],rt[l[i]],1,n,a[i],i);
			}
			else
			{
				l[i]=-1;
				T.ins(rt[i],rt[0],1,n,a[i],i);
			}
		}
		ans=0;
		for(i=1;i<=n;i++)
		{
			if(l[i]!=-1)
				dp[i]=dp[l[i]]+1;
			else
				dp[i]=0;
			ans+=dp[i];
		}
		printf("%lld\n",ans);
	}
}