#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
#define MQ 300000
#define N 131072
int a[MN+5],p[MN+5],c[MN+5],cn,ans[MQ+5];
int t1[N*2+5],t2[N*2+5];
vector<pair<int,int> > v[MN+5];
void renew(int l,int r,int x)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)t1[l+1]=min(t1[l+1],x);
		if( r&1)t1[r-1]=min(t1[r-1],x);
	}
}
int query(int k)
{
	int r=t1[k+=N];
	while(k>>=1)r=min(r,t1[k]);
	return r;
}
void renew(int k,int x){for(k+=N;k;k>>=1)t2[k]=max(t2[k],x);}
int query(int l,int r)
{
	int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=max(res,t2[l+1]);
		if( r&1)res=max(res,t2[r-1]);
	}
	return res;
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n=read(),q,i,j,k;
	for(i=1;i<=n;++i)a[i]=c[i]=read();
	sort(c+1,c+n+1);
	for(i=2,cn=1;i<=n;++i)if(c[i]!=c[cn])c[++cn]=c[i];
	for(i=1;i<=n;++i)p[i]=lower_bound(c+1,c+cn+1,a[i])-c;
	for(q=read(),i=0;i<q;++i)j=read(),v[read()].push_back(make_pair(i,j));
	memset(ans,127,sizeof(ans));memset(t1,127,sizeof(t1));
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=p[i]&&(k=query(j,p[i]));)
			renew(1,k,a[i]-a[k]),j=upper_bound(c+1,c+cn+1,(a[i]+a[k])>>1)-c;
		for(j=0;j<v[i].size();++j)
			ans[v[i][j].first]=min(ans[v[i][j].first],query(v[i][j].second));
		renew(p[i],i);
	}
	memset(t1,127,sizeof(t1));memset(t2,0,sizeof(t2));
	for(i=1;i<=n;++i)
	{
		for(j=cn;j>=p[i]&&(k=query(p[i],j));)
			renew(1,k,a[k]-a[i]),j=lower_bound(c+1,c+cn+1,(a[i]+a[k]+1)>>1)-c-1;
		for(j=0;j<v[i].size();++j)
			ans[v[i][j].first]=min(ans[v[i][j].first],query(v[i][j].second));
		renew(p[i],i);
	}
	for(i=0;i<q;++i)printf("%d\n",ans[i]);
}