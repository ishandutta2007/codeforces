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

const int MX=600100,Mod=1000000007;
int N,sum[MX];
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1;
int num[MX][3],id[MX],cnt[MX];
int Extend(int las,char c)
{
	int k=c-'a',x=las,y=C[x][k]?MX-1:++sc;
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
			memcpy(C[w],C[z],sizeof(C[0]));
			len[w]=len[x]+1,F[w]=F[z],F[y]=F[z]=w;
			while(C[x][k]==z)C[x][k]=w,x=F[x];
		}
	}
	return C[las][k];
}

int main()
{
	N=MX;
	Fr(i,0,2)
	{
		scanf("%s",S+1);
		int n=strlen(S+1),x=1;
		Fr(j,1,n)x=Extend(x,S[j]),++num[x][i];
		N=min(N,n);
	}
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	Fl(i,sc,2)
	{
		int x=id[i];
		Fr(j,0,2)num[F[x]][j]+=num[x][j];
		int p=(ll)num[x][0]*num[x][1]*num[x][2]%Mod;
		sum[len[F[x]]+1]=(sum[len[F[x]]+1]+p)%Mod;
		sum[len[x]+1]=(sum[len[x]+1]-p+Mod)%Mod;
	}
	Fr(i,1,N)sum[i]=(sum[i]+sum[i-1])%Mod,printf("%d ",sum[i]);
	putchar('\n');
	return 0;
}