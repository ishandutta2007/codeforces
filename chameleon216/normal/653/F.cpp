#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=1000100;
int N;
char S[MX];

int C[MX][2],F[MX],len[MX],sc=1,las=1;
int num[MX],L[MX],id[MX],cnt[MX],V[MX];
void Extend(char c)
{
	int k=(c==')'),x=las,y=++sc;
	len[y]=len[x]+1,las=y;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			memcpy(C[w],C[z],sizeof(C[0]));
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
}


#define li (i<<1)
#define ri (i<<1|1)
struct Segment{int s,h,c;}T[MX*4];
void Build(int i,int l,int r)
{
	Segment &o=T[i],&p=T[li],&q=T[ri];
	if(l==r){o.s=o.h=(S[l]=='('?1:-1),o.c=1;return;}
	int m=(l+r)>>1;
	Build(li,l,m);
	Build(ri,m+1,r);
	o.s=p.s+q.s,o.c=0;
	o.h=min(p.h,p.s+q.h);
	if(o.h==p.h)o.c+=p.c;
	if(o.h==p.s+q.h)o.c+=q.c;
}
bool Search(int i,int l,int r,int a,int b,int &s,ll &c)
{
	if(b<l||r<a)return 0;
	if(a<=l&&r<=b)
	{
		if(s+T[i].h>=0)
		{
			if(s+T[i].h==0)c+=T[i].c;
			s+=T[i].s;
			return 0;
		}
		if(l==r){s=-1;return 1;}
	}
	int m=(l+r)>>1;
	return Search(li,l,m,a,b,s,c)||Search(ri,m+1,r,a,b,s,c);
}


int main()
{
	scanf("%d%s",&N,S+1);
	Fl(i,N,1)Extend(S[i]),++num[las],L[las]=i;
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	
	Fl(i,sc,2)
	{
		int x=id[i];
		num[F[x]]+=num[x];
		L[F[x]]=L[x];
	}
	
	Build(1,1,N);
	ll ans=0;
	Fr(i,2,sc)
	{
		int x=id[i];
		if(V[F[x]]==-1){V[x]=-1;continue;}
		V[x]=V[F[x]];
		Search(1,1,N,L[x]+len[F[x]],L[x]+len[x]-1,V[x],ans);
	}
	printf("%lld\n",ans);
	return 0;
}