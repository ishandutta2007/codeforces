#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=200005;
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
long long iv6;
int n,q,i,j,a[N],t[N],k,mp[N],ans[N],le[N];
struct str{
	int l,r,d,x;
}b[N];
bool cmp(str a,str b)
{
	return a.r<b.r;
}
struct T{
	long long tree[N*4];
	void pushup(int i)
	{
		tree[i]=(tree[i<<1]+tree[i<<1|1])%M;
	}
	void modify(int i,int l,int r,int x,int y)
	{
		if(l==r)
		{
			tree[i]=(tree[i]+y)%M;
			return;
		}
		int mid=l+r>>1;
		if(mid>=x)
			modify(i<<1,l,mid,x,y);
		else
			modify(i<<1|1,mid+1,r,x,y);
		pushup(i);
	}
	int Query(int i,int l,int r,int ll,int rr)
	{
		if(l>=ll&&r<=rr)
			return tree[i];
		int mid=l+r>>1,as=0;
		if(mid>=ll)
			as+=Query(i<<1,l,mid,ll,rr);
		if(mid<rr)
			as+=Query(i<<1|1,mid+1,r,ll,rr);
		return as%M;
	}
}u;
long long Sum(long long n)
{
	return n*(n+1)/2%M;
}
long long S2(long long n)
{
	return n*(n+1)%M*(2*n+1)%M*iv6%M;
}
int Find(int x)
{
	int y=lower_bound(t+1,t+1+k,x)-t;
	if(t[y]==x)
		return mp[y];
	else
		return 0;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		t[++k]=a[i];
		le[i]=(a[i]==a[i-1]?le[i-1]:i);
	}
	sort(t+1,t+1+k);
	for(i=1;i<=q;++i)
	{
		scanf("%d %d %d",&b[i].l,&b[i].r,&b[i].d);
		b[i].x=i;
	}
	iv6=qpow(6,M-2);
	sort(b+1,b+1+q,cmp);
	int l=1;
	for(i=1;i<=q;++i)
	{
		while(l<=b[i].r)
		{
			int x=lower_bound(t+1,t+1+k,a[l])-t;
			if(mp[x])
				u.modify(1,1,n,mp[x],-1ll*a[l]*a[l]%M);
			u.modify(1,1,n,l,1ll*a[l]*a[l]%M);
			mp[x]=l;
			++l;
		}
		if(b[i].d==0)
		{
			ans[b[i].x]=(le[b[i].r]<=b[i].l);
			continue;
		}
		long long iv=qpow(b[i].d,M-2);
		long long t=(u.Query(1,1,n,b[i].l,b[i].r)*iv%M*iv%M+M)%M;
		long long tp=a[b[i].r]*iv%M;
		int l=0,r=b[i].r-b[i].l+1;
		while(l<r)
		{
			int mid=l+r>>1;
			int y=(1ll*(tp-mid)*b[i].d%M+M)%M;
			//cout<<y<<endl;
			if(Find(y)>=b[i].l)
				l=mid+1;
			else
				r=mid;
		}
		--l;
		//cout<<t<<' '<<((S2(b[i].r-b[i].l+1+tp-l+M-1)-S2(tp-l+M-1))%M+M)%M<<endl;
		ans[b[i].x]=(((S2(b[i].r-b[i].l+1+tp-l+M-1)-S2(tp-l+M-1))%M+M)%M==t);
	}
	for(i=1;i<=q;++i)
		puts(ans[i]?"Yes":"No");
}