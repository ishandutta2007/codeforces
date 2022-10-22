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

const int MX=1000100,Mod=1000000007;
int N,dp[MX];
char S[MX],S_[MX];

int C[MX][26],F[MX],J[MX],len[MX],D[MX],W[MX],pc,las;
void Init(){pc=2,las=1,len[1]=-1,F[2]=1;}
void Extend(int i)
{
	int k=S[i]-'a',x=las;
	while(S[i]!=S[i-len[x]-1])x=F[x];
	if(!C[x][k])
	{
		int y=++pc,z=F[x];
		C[x][k]=y,len[y]=len[x]+2;
		while(z&&S[i]!=S[i-len[z]-1])z=F[z];
		F[y]=z?C[z][k]:2;
		D[y]=len[y]-len[F[y]];
		J[y]=D[y]==D[F[y]]?J[F[y]]:F[y];
	}
	las=C[x][k];
}

int main()
{
	scanf("%s",S_+1);
	N=strlen(S_+1);
	Fr(i,1,N)S[i]=(i&1)?S_[(i>>1)+1]:S_[N-(i>>1)+1];
	
	Init();
	dp[0]=1;
	Fr(i,1,N)
	{
		Extend(i);
		for(int x=las;x>2;x=J[x])
		{
			W[x]=dp[i-len[J[x]]-D[x]];
			if(F[x]!=J[x])W[x]=(W[x]+W[F[x]])%Mod;
			if(!(i&1))dp[i]=(dp[i]+W[x])%Mod;
		}
	}
	printf("%d\n",dp[N]);
	return 0;
}