#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define L (k<<1)
#define R (k<<1|1)
int n,m,ans,w[MN+5],g[MN+5],z[MN+5],zn,q[MN+5],qn;
ll s1[MN+5],s2[MN+5];
vector<int> v[MN+5];
struct node{ll a,b,c,mk;}t[MN*4+5];
void mark(int k,ll x){t[k].a+=x;t[k].c+=x;t[k].mk+=x;}
void down(int k){if(t[k].mk)mark(L,t[k].mk),mark(R,t[k].mk),t[k].mk=0;}
ll cal(int k,int l,int r,ll x)
{
	if(l==r)return x-t[k].b;
	down(k);int mid=l+r>>1;
	if(x>t[L].a)return min(x-t[L].b,cal(R,mid+1,r,x));
	return min(cal(L,l,mid,x),t[k].c);
}
#define up(k) t[k].a=max(t[L].a,t[R].a),t[k].c=cal(R,mid+1,r,t[L].a)
void build(int k,int l,int r)
{
	if(l==r){t[k].a=t[k].b=s2[l];return;}
	int mid=l+r>>1;
	build(L,l,mid);build(R,mid+1,r);
	up(k);t[k].b=max(t[L].b,t[R].b);
}
void add(int k,int l,int r,int ql,int qr,ll x)
{
	if(l==ql&&r==qr){mark(k,x);return;}
	int mid=l+r>>1;down(k);
	if(qr<=mid)add(L,l,mid,ql,qr,x);
	else if(ql>mid)add(R,mid+1,r,ql,qr,x);
	else add(L,l,mid,ql,mid,x),add(R,mid+1,r,mid+1,qr,x);
	up(k);
}
int solve(int k,int l,int r,ll x)
{
	if(l==r)return x-t[k].b>m?0:l;
	down(k);int mid=l+r>>1;
	if(x-t[R].b<=m)return solve(R,mid+1,r,x);
	return solve(L,l,mid,x);
}
int query(int k,int l,int r,ll x)
{
	if(l==r)return x-t[k].b>m?0:l;
	down(k);int mid=l+r>>1,res=0;
	if(x>t[L].a)res=solve(L,l,mid,x);
	else if(t[k].c>m)return query(L,l,mid,x);
	return max(res,query(R,mid+1,r,max(x,t[L].a)));
}
void solve(int x)
{
	q[++qn]=x;
	if(x>1)add(1,1,n,1,x-1,-1e18);
	int l=1,r=qn,mid,res=n;
	while(l<=r)if(s1[x]-s1[q[mid=l+r>>1]]>m)res=q[mid]-1,l=mid+1;else r=mid-1;
	add(1,1,n,res,n,1e18);
	ans=max(ans,query(1,1,n,-1e18)-x);
	add(1,1,n,res,n,-1e18);
	if(x>1)add(1,1,n,1,x-1,1e18);
	for(int i=0;i<v[x].size();++i)
	{
		if(x>1)add(1,1,n,x-1,n,s1[v[x][i]]-s1[x]);
		solve(v[x][i]);
		if(x>1)add(1,1,n,x-1,n,s1[x]-s1[v[x][i]]);
	}
	--qn;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<n;++i)w[i]=read();
	for(int i=1;i<=n;++i)g[i]=read();
	for(int i=1;i<n;++i)s1[i+1]=s1[i]+g[i]-w[i],s2[i+1]=s2[i]+g[i+1]-w[i];
	build(1,1,n);
	for(int i=1;i<=n;z[++zn]=i++)while(zn&&s1[i]<s1[z[zn]])v[i].push_back(z[zn--]);
	for(int i=1;i<=zn;++i)solve(z[i]);
	printf("%d",ans+1);
}