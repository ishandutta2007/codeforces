#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long sum[maxn*4];
long long lazy[maxn*4];
int n;
long long k[maxn];
long long pre[maxn];
void pushup(int rt)
{
	sum[rt]=sum[rt*2]+sum[rt*2+1];
}
void build(int l=1,int r=n,int rt=1)
{
	lazy[rt]=INF;
	if(l==r)
	{
		scanf("%lld",&sum[rt]);
		return;
	}
	int mid=l+r>>1;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	pushup(rt);
}
long long add(int l,int r,long long val)
{
	return pre[r]-pre[l-1]+val*(r-l+1);
}
void pushdown(int rt,int L,int R)
{
	if(lazy[rt]<INF)
	{
		int mid=L+R>>1;
		lazy[rt*2]=lazy[rt];
		lazy[rt*2+1]=lazy[rt];
		sum[rt*2]=add(L,mid,lazy[rt]);
		sum[rt*2+1]=add(mid+1,R,lazy[rt]);
		lazy[rt]=INF;
	}
}
void update(int l,int r,long long val,int L=1,int R=n,int rt=1)
{
	if(l<=L&&r>=R)
	{
		sum[rt]=add(L,R,val);
		lazy[rt]=val;
		return;
	}
	int mid=L+R>>1;
	pushdown(rt,L,R);
	if(l<=mid) update(l,r,val,L,mid,rt*2);
	if(r>mid) update(l,r,val,mid+1,R,rt*2+1);
	pushup(rt);
}
long long query(int l,int r,int L=1,int R=n,int rt=1)
{
	if(l<=L&&r>=R)
	{
		return sum[rt];
	}
	pushdown(rt,L,R);
	int mid=L+R>>1;
	long long ret=0;
	if(l<=mid) ret+=query(l,r,L,mid,rt*2);
	if(r>mid) ret+=query(l,r,mid+1,R,rt*2+1);
	return ret;
}
int main()
{
	scanf("%d",&n);
	build();
	for(int i=2;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		k[i]+=k[i-1];
	}
	for(int i=2;i<=n;i++) pre[i]=pre[i-1]+k[i];
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char op[10];
		scanf("%s",op);
		if(op[0]=='+')
		{
			int i,x;
			scanf("%d%d",&i,&x);
			int l=i,r=n,pos=i;
			long long cur=query(i,i);
			while(l<=r)
			{
				int mid=l+r>>1;
				if(x+cur+k[mid]-k[i]>query(mid,mid)) l=mid+1,pos=mid;
				else r=mid-1;
			}
			update(i,pos,cur+x-k[i]);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			long long ans=query(l,r);
			printf("%lld\n",ans);
		}
	}
}