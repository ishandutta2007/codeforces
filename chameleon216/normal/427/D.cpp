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

const int MX=20100,Inf=0x3f3f3f3f;
char S[MX];

int C[MX][26],F[MX],len[MX],sc=1;
int num[MX][2],cnt[MX],id[MX];
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
	Fr(i,0,1)
	{
		scanf("%s",S+1);
		int n=strlen(S+1),x=1;
		Fr(j,1,n)x=Extend(x,S[j]),++num[x][i];
	}
	
	Fr(i,1,sc)++cnt[len[i]];
	Fr(i,1,sc)cnt[i]+=cnt[i-1];
	Fl(i,sc,1)id[cnt[len[i]]--]=i;
	int ans=Inf;
	Fl(i,sc,2)
	{
		int x=id[i];
		num[F[x]][0]+=num[x][0];
		num[F[x]][1]+=num[x][1];
		if(num[x][0]==1&&num[x][1]==1)
			ans=min(ans,len[F[x]]+1);
	}
	printf("%d\n",ans==Inf?-1:ans);
	return 0;
}