#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define ll long long
char B[1<<26],*S=B,C;int X;
inline int read()
{
	while((C=*S++)<'0'||C>'9');
	for(X=C-'0';(C=*S++)>='0'&&C<='9';)X=(X<<3)+(X<<1)+C-'0';
	return X;
}
#define MN 100000
#define N 131072
#define MV 524288
#define ME 5000000
#define d(x,y) make_pair(x,y)
struct edge{int nx,t,w;}e[ME+5];
int h[MV+5],en;ll ds[MV+5];
typedef pair<ll,int> data;
priority_queue<data,vector<data>,greater<data> >pq;
inline void ins(int x,int y,int w){e[++en]=(edge){h[x],y,w};h[x]=en;}
void ins1(int l,int r,int f,int w)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)ins(f+N,l+1,w);
		if( r&1)ins(f+N,r-1,w);
	}
}
void ins2(int l,int r,int t,int w)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)ins(l+1+(N<<1),t+N,w);
		if( r&1)ins(r-1+(N<<1),t+N,w);
	}
}
int main()
{
	fread(B,1,1<<26,stdin);
	int n,m,i,s,a,b,c,d;ll x;
	n=read();m=read();s=read();
	for(i=1;i<N;++i)
	{
		ins(i,i<<1,0);ins(i,i<<1|1,0);
		ins(i+N<<1,i+(N<<1),0);ins(i+N<<1|1,i+(N<<1),0);
		ins(i+N,i+N*3,0);ins(i+N*3,i+N,0);
	}
	while(m--)
	{
		a=read();b=read();c=read();d=read();
		if(a==1)ins(b+N,c+N,d);
		if(a==2)ins1(c,d,b,read());
		if(a==3)ins2(c,d,b,read());
	}
	memset(ds,127,sizeof(ds));ds[s+N]=1;pq.push(d(0,s+N));
	while(pq.size())
	{
		a=pq.top().second;x=pq.top().first;pq.pop();
		for(i=h[a];i;i=e[i].nx)if(x+e[i].w<ds[e[i].t])
		{
			ds[e[i].t]=x+e[i].w;
			pq.push(d(ds[e[i].t],e[i].t));
		}
		while(pq.size()&&pq.top().first>ds[pq.top().second])pq.pop();
	}
	for(i=1;i<=n;++i)printf("%I64d ",ds[i+N]<ds[0]?ds[i+N]:-1);
}