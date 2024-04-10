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

const int MX=5100;
int N,sum[MX];
char S[MX];

int C[MX][26],F[MX],G[MX],len[MX],num[MX],dp[MX],pc,las;
void Init(){pc=2,las=1,len[1]=-1,F[2]=G[2]=1;}
void Extend(int i)
{
	int k=S[i]-'a',x=las;
	while(S[i]!=S[i-len[x]-1])x=F[x];
	if(!C[x][k])
	{
		int y=++pc,f=F[x],g=G[x];
		C[x][k]=y,len[y]=len[x]+2;
		while(f&&S[i]!=S[i-len[f]-1])f=F[f];
		while(g&&!(S[i]==S[i-len[g]-1]&&(len[g]+2)*2<=len[y]))g=F[g];
		F[y]=f?C[f][k]:2,G[y]=g?C[g][k]:2;
	}
	las=C[x][k];
}


int main()
{
	scanf("%s",S+1);
	N=strlen(S+1),Init();
	Fr(i,1,N)Extend(i),++num[las];
	Fl(i,pc,2)num[F[i]]+=num[i];
	
	Fr(x,3,pc)
	{
		dp[x]=len[G[x]]==len[x]/2?dp[G[x]]+1:1;
		sum[dp[x]]+=num[x];
	}
	Fl(i,N,1)sum[i]+=sum[i+1];
	Fr(i,1,N)printf("%d ",sum[i]);
	putchar('\n');
	
//	Fr(i,1,pc)printf("%d %d\n",F[i],G[i]);putchar('\n');
	
	return 0;
}