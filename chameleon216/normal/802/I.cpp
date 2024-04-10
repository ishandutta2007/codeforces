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

const int MX=200100;
int N;
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1;
int num[MX],id[MX],cnt[MX];
int Extend(int x,char c)
{
	int k=c-'a',y=++sc;
	len[y]=len[x]+1;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[z]));
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
	return y;
}

void Work()
{
	scanf("%s",S+1);
	N=strlen(S+1);
	int p=1;
	Fr(i,1,N)p=Extend(p,S[i]),++num[p];
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	Fl(i,sc,2)num[F[id[i]]]+=num[id[i]];
	ll s=0;
	Fr(x,1,sc)s+=(ll)(len[x]-len[F[x]])*num[x]*num[x];
	printf("%lld\n",s);
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		Work();
		memset(C,0,sizeof(C));
		memset(F,0,sizeof(F));
		memset(len,0,sizeof(len));
		memset(num,0,sizeof(num));
		memset(cnt,0,sizeof(cnt));
		sc=1;
	}
	return 0;
}