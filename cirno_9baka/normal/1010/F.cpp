#include<bits/stdc++.h>
using namespace std;
const int M=998244353,P=998244353,G=3,Gi=332748118;
int n,mi[100005],head[100005],Next[200005],adj[200005],u,v,k;
int siz[100005],son[100005],top[100005],pts[100005],m,r[500005];
long long s,i,fans,inv[100005];
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
inline void NTT(long long *A,int type,int limit)
{
	for(int i=0;i<limit;++i)
		r[i]=(r[i>>1]>>1)|(i&1?limit>>1:0);
    for(int i=0;i<limit;++i)
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < limit; mid <<= 1) {  
        long long Wn = qpow( type == 1 ? G : Gi , (P - 1) / (mid << 1));
        for(int j = 0; j < limit; j += (mid << 1)) {
            long long w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 long long x = A[j + k], y = w * A[j + k + mid];
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y) % P;
            }
        }
    }
    if(type==-1)
    {
    	long long inv=qpow(limit,M-2);
    	for(int i=0;i<limit;++i)
			A[i]=A[i]*inv%M;
	}
}
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
long long ans[500005],f[500005],tmp[500005];
vector<long long> p[500005];
void dfs(int i,int fa)
{
	int j;
	siz[i]=1;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
			if(siz[adj[j]]>siz[son[i]])
				son[i]=adj[j];
		}
	top[son[i]]=1;
}
int getsiz(int i,int l,int r)
{
	if(l==r)
		return siz[i]=p[pts[l]].size();
	int mid=l+r>>1;
	return siz[i]=getsiz(i<<1,l,mid)+getsiz(i<<1|1,mid+1,r);;
}
int getsiz2(int i,int l,int r)
{
	if(l==r)
		return siz[i]=p[pts[l]].size()-1;
	int mid=l+r>>1;
	return siz[i]=getsiz2(i<<1,l,mid)+getsiz2(i<<1|1,mid+1,r);
}
int Merge(int i,int l,int r)
{
	int j;
	if(l==r)
	{
		ans[0]=0;
		for(j=0;j<p[pts[l]].size();++j)
		{
			ans[j+1]=p[pts[l]][j];
			tmp[j+1]=0;
		}
		tmp[0]=1;
		return 0;
	}
	int mid=l+r>>1;
	int lim;
	for(lim=1;lim<=siz[i];lim<<=1);
	long long a[lim],b[lim],c[lim],d[lim];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	int lb=Merge(i<<1,l,mid);
	for(j=0;j<=siz[i<<1];++j)
		a[j]=ans[j];
	for(j=0;j<=lb;++j)
		c[j]=tmp[j];
	int rb=Merge(i<<1|1,mid+1,r);
	for(j=0;j<=siz[i<<1|1];++j)
		b[j]=ans[j];
	for(j=0;j<=rb;++j)
		d[j]=tmp[j];
	if(siz[i]<=256)
	{
		for(j=0;j<=siz[i];++j)
			tmp[j]=ans[j]=0;
		for(j=0;j<=siz[i<<1];++j)
		{
			int k;
			for(k=0;k+3<=siz[i<<1|1];k+=4)
			{
				ans[j+k]=(ans[j+k]+a[j]*b[k])%M;
				ans[j+k+1]=(ans[j+k+1]+a[j]*b[k+1])%M;
				ans[j+k+2]=(ans[j+k+2]+a[j]*b[k+2])%M;
				ans[j+k+3]=(ans[j+k+3]+a[j]*b[k+3])%M;
			}
			for(;k<=siz[i<<1|1];++k)
				ans[j+k]=(ans[j+k]+a[j]*b[k])%M;
		}
		for(j=0;j<=siz[i<<1];++j)
		{
			int k;
			for(k=0;k+3<=rb;k+=4)
			{
				tmp[j+k]=(tmp[j+k]+a[j]*d[k])%M;
				tmp[j+k+1]=(tmp[j+k+1]+a[j]*d[k+1])%M;
				tmp[j+k+2]=(tmp[j+k+2]+a[j]*d[k+2])%M;
				tmp[j+k+3]=(tmp[j+k+3]+a[j]*d[k+3])%M;
			}
			for(;k<=rb;++k)
				tmp[j+k]=(tmp[j+k]+a[j]*d[k])%M;
		}
		for(j=0;j<=lb;++j)
			tmp[j]=(tmp[j]+c[j])%M;
		return siz[i<<1]+rb;
	}
	/*cout<<l<<' '<<r<<endl;
	for(j=0;j<lim;++j)
		cout<<b[j]<<' ';
	cout<<endl;
	for(j=0;j<lim;++j)
		cout<<a[j]<<' ';
	cout<<endl;
	for(j=0;j<lim;++j)
		cout<<c[j]<<' ';
	cout<<endl;*/
	NTT(a,1,lim);
	NTT(b,1,lim);
	for(j=0;j<lim;++j)
		b[j]=a[j]*b[j]%M;
	NTT(b,-1,lim);
	NTT(d,1,lim);
	for(j=0;j<lim;++j)
		d[j]=d[j]*a[j]%M;
	NTT(d,-1,lim);
	for(j=0;j<lim;++j)
	{
		tmp[j]=(d[j]+c[j])%M;
		//cout<<tmp[j]<<' ';
	}
	//cout<<endl;
	for(j=0;j<lim;++j)
	{
		ans[j]=b[j];
		//cout<<b[j]<<' ';
	}
	//cout<<endl;
	return siz[i<<1]+rb;
}
void dfs3(int i,int l,int r)
{
	int j;
	if(l==r)
	{
		for(j=0;j<p[pts[l]].size();++j)
			ans[j]=p[pts[l]][j];
		return;
	}
	int mid=l+r>>1;
	int lim;
	for(lim=1;lim<=siz[i];lim<<=1);
	long long a[lim],b[lim];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	dfs3(i<<1,l,mid);
	for(j=0;j<=siz[i<<1];++j)
		a[j]=ans[j];
	dfs3(i<<1|1,mid+1,r);
	for(j=0;j<=siz[i<<1|1];++j)
		b[j]=ans[j];
	NTT(a,1,lim);
	NTT(b,1,lim);
	for(j=0;j<lim;++j)
		a[j]=a[j]*b[j]%M;
	NTT(a,-1,lim);
	for(j=0;j<=siz[i];++j)
		ans[j]=a[j];
}
void dfs2(int i,int fa)
{
	int s=0,j,k;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=son[i]&&adj[j]!=fa)
			dfs2(adj[j],i);
	ans[0]=1;
	m=0;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=son[i]&&adj[j]!=fa)
			pts[++m]=adj[j];
	if(m!=0)
	{
		getsiz2(1,1,m);
		dfs3(1,1,m);
	//cout<<i<<' ';
		for(k=0;k<=siz[1];++k)
		{
			//cout<<ans[k]<<' ';
			p[i].push_back(ans[k]);
		}
	}
	else
		p[i].push_back(1);
	//cout<<endl;
	if(son[i])
		dfs2(son[i],i);
	if(!top[i])
	{
		m=0;
		for(j=i;j!=0;j=son[j])
			pts[++m]=j;
		getsiz(1,1,m);
		//cout<<i<<endl;
		Merge(1,1,m);
		p[i].clear();
		for(j=0;j<=siz[1];++j)
		{
			p[i].push_back((tmp[j]+ans[j])%M);
			//cout<<p[i][j]<<' ';
		}
		//cout<<endl;
	}
}
int main()
{
	scanf("%d %lld",&n,&s);
	inv[0]=inv[1]=1;
	for(i=2;i<=n;++i)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=n;++i)
		inv[i]=inv[i]*inv[i-1]%M;
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	mi[0]=1;
	for(i=s;i<=s+n;++i)
		mi[i-s+1]=mi[i-s]*((i+1)%M)%M;
	dfs(1,0);
	dfs2(1,0);
	for(i=1;i<p[1].size();++i)
		fans=(fans+p[1][i]*mi[i-1]%M*inv[i-1])%M;
	cout<<(fans%M+M)%M;
}