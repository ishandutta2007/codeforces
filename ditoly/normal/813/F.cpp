#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MQ 100000
#define L (k<<1)
#define R (k<<1|1)
struct query{int x,y,t;}p[MQ+5];
bool cmp(const query&a,const query&b)
{
	if(a.x!=b.x)return a.x<b.x;
	if(a.y!=b.y)return a.y<b.y;
	return a.t<b.t; 
}
vector< pair<int,int> > v[MQ*4+5],vv[MQ*4+5];
int ans[MQ+5],f[MQ+5],tf[MQ+5],s[MQ+5];
void ins(int k,int l,int r,int ql,int qr,int x,int y)
{
	if(l==ql&&r==qr){v[k].push_back(make_pair(x,y));return;}
	int mid=l+r>>1;
	if(qr<=mid)ins(L,l,mid,ql,qr,x,y);
	else if(ql>mid)ins(R,mid+1,r,ql,qr,x,y);
	else ins(L,l,mid,ql,mid,x,y),ins(R,mid+1,r,mid+1,qr,x,y);
}
int gf(int k){return f[k]?gf(f[k]):k;}
int color(int k){return f[k]?color(f[k])^tf[k]:0;}
void dfs(int k,int l,int r,int u)
{
	int i,mid=l+r>>1;
	for(i=0;i<v[k].size();++i)
		if(gf(v[k][i].first)==gf(v[k][i].second))
			u&=(color(v[k][i].first)!=color(v[k][i].second));
		else
		{
			if(s[gf(v[k][i].first)]>s[gf(v[k][i].second)])
				swap(v[k][i].first,v[k][i].second);
			int x=gf(v[k][i].first),y=gf(v[k][i].second);
			vv[k].push_back(make_pair(x,y));
			tf[x]=color(v[k][i].first)^color(v[k][i].second)^1;
			s[y]+=s[x];f[x]=y;
		}
	if(l==r)ans[l]=u;
	else dfs(L,l,mid,u),dfs(R,mid+1,r,u);
	for(i=vv[k].size();i--;)
	{
		s[vv[k][i].second]-=s[vv[k][i].first];
		f[vv[k][i].first]=0;
	}
}
int main()
{
	int n,q,i,j,k;
	n=read();q=read();
	for(i=1;i<=q;++i)p[i].x=read(),p[i].y=read(),p[i].t=i;
	sort(p+1,p+q+1,cmp);
	for(i=1;i<=q;i=j)for(j=i;j<=q&&p[i].x==p[j].x&&p[i].y==p[j].y;)
		if(p[j].x==p[j+1].x&&p[j].y==p[j+1].y)
			ins(1,1,q,p[j].t,p[j+1].t-1,p[j].x,p[j].y),j+=2;
		else ins(1,1,q,p[j].t,q,p[j].x,p[j].y),++j;
	for(i=1;i<=n;++i)s[i]=1;
	dfs(1,1,q,1);
	for(i=1;i<=q;++i)puts(ans[i]?"YES":"NO");
}