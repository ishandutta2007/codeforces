#include<bits/stdc++.h>
using namespace std;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
const int M=998244353;
int n,m,c,a[1000005],k,l[505],r[505],s[2005],i;
int tree[2000005];
long long f[2005][2005];
void Build(int i,int l,int r)
{
	if(l==r)
	{
		tree[i]=a[l];
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	tree[i]=min(tree[i<<1],tree[i<<1|1]);
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1,ans=1<<30;
	if(mid>=ll)
		ans=Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		ans=min(ans,Query(i<<1|1,mid+1,r,ll,rr));
	return ans;
}
long long dfs(int sl,int sr)
{
	if(sl>=sr)
		return 1;
	if(f[sl][sr]!=0)
		return f[sl][sr];
	int y=Query(1,1,k,sl,sr);
	int i;
	long long ans=1,s1=0,s2=0,la=l[y],s[sr-sl+1];
	for(i=0;i<sr-sl+1;++i)
		s[i]=0;
	for(i=sl;i<=sr;++i)
	{
		++s[l[a[i]]-sl];
		--s[r[a[i]]-sl];
	}
	for(i=sl+1;i<=sr;++i)
		s[i-sl]+=s[i-sl-1];
	for(i=l[y]+1;i<=r[y];++i)
		if(a[i]==y)
		{
			if(la<i-1)
				ans=ans*dfs(la+1,i-1)%M;
			la=i;
		}
	for(i=l[y]-1;i>=sl;--i)
		if(!s[i-sl])
			s1=(s1+dfs(i+1,l[y]-1)*dfs(sl,i))%M;
	s1=(s1+dfs(sl,l[y]-1))%M;
	for(i=r[y];i<=sr;++i)
		if(!s[i-sl])
			s2=(s2+dfs(r[y]+1,i)*dfs(i+1,sr))%M;
	return f[sl][sr]=s1*s2%M*ans%M;
}
int main()
{
	gi(n),gi(m);
	for(i=1;i<=m;++i)
	{
		gi(c);
		if(c!=a[k])
		{
			a[++k]=c;
			if(l[c]==0)
				l[c]=k;
			r[c]=k;
		}
	}
	Build(1,1,k);
	for(i=1;i<=n;++i)
		if(Query(1,1,k,l[i],r[i])<i)
		{
			puts("0");
			return 0;
		}
	cout<<dfs(1,k);
}