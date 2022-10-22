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

const int MX=2000100;
int N,M;
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1,las=1;
int num[MX],id[MX],cnt[MX],B[MX],bc;
void Extend(char c)
{
	int k=c-'a',x=las,y=++sc;
	len[y]=len[x]+1,++num[y],las=y;
	while(x&&!C[x][k])C[x][k]=y,x=F[x];
	if(!x)F[y]=1;
	else
	{
		int z=C[x][k];
		if(len[z]==len[x]+1)F[y]=z;
		else
		{
			int w=++sc;
			memcpy(C[w],C[z],sizeof(C[0]));
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
}

ll Calc()
{
	int n=strlen(S+1),x=1,l=0;
	ll ans=0;
	++bc;
	Fr(i,1,n-1)S[n+i]=S[i];
	Fr(i,1,2*n-1)
	{
		int k=S[i]-'a';
		while(x&&!C[x][k])x=F[x],l=len[x];
		if(x)x=C[x][k],++l;
		else x=1,l=0;
		while(len[F[x]]>=n)x=F[x],l=len[x];
		l=min(l,n);
		if(l==n&&B[x]!=bc)
			ans+=num[x],B[x]=bc;
	}
	return ans;
}

int main()
{
	scanf("%s%d",S+1,&M),N=strlen(S+1);
	Fr(i,1,N)Extend(S[i]);
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	Fl(i,sc,2)num[F[id[i]]]+=num[id[i]];
	
	Fr(i,1,M)
	{
		scanf("%s",S+1);
		printf("%lld\n",Calc());
	}
	
	return 0;
}