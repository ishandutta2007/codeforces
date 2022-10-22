#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=2020,Mod=1000000007;
int N,K;
char S[2][MX],T[MX];

int lcp[2][MX][MX],rcp[2][MX][MX];
int L[2][MX][MX],R[2][MX][MX],ans;

void Solve()
{
	Fr(i,0,1)Fl(j,N,1)Fl(k,K,1)
	{
		lcp[i][j][k]=(S[i][j]==T[k]?lcp[i][j+1][k-1]+1:0);
		rcp[i][j][k]=(S[i][j]==T[k]?rcp[i][j+1][k+1]+1:0);
//		rcp[i][j][k]=(S[i][j]==T[K-k+1]?rcp[i][j+1][k+1]+1:0);
//		printf("lcp[%d][%d][%d]=%d\nrcp[%d][%d][%d]=%d\n",i,j,k,lcp[i][j][k],i,j,k,rcp[i][j][k]);
	}
	
	Fr(i,0,1)
	{
		Fr(j,0,N)for(int k=0;k<=j&&2*k<=K;++k)if(k!=1)
			L[i][j][k*2]=(lcp[i^1][j-k+1][k]>=k&&rcp[i][j-k+1][k+1]>=k);
		Fr(j,1,N+1)for(int k=0;k<=N-j+1&&2*k<=K;++k)if(k!=1)
			R[i][j][k*2]=(lcp[i^1][j][K]>=k&&rcp[i][j][K-k*2+1]>=k);
//		Fr(j,0,N)Fr(k,0,K)if(L[i][j][k])printf("L[%d][%d][%d]\n",i,j,k);
//		Fr(j,1,N+1)Fr(k,0,K)if(R[i][j][k])printf("R[%d][%d][%d]\n",i,j,k);
	}
	
	Fr(j,0,N-1)Fr(i,0,1)Fr(k,0,K-1)
	{
		if(S[i][j+1]==T[k+1])(L[i][j+1][k+1]+=L[i][j][k])%=Mod;
		if(S[i][j+1]==T[k+1]&&S[i^1][j+1]==T[k+2])(L[i^1][j+1][k+2]+=L[i][j][k])%=Mod;
	}
//	Fr(i,0,1)Fr(j,0,N)Fr(k,0,K)printf("dp[%d][%d][%d]=%d\n",i,j,k,L[i][j][k]);
	
	Fr(i,0,1)Fr(j,0,N)Fr(k,1,K)(ans+=L[i][j][k]*R[i][j+1][K-k])%=Mod;
}

int main()
{
	scanf("%s%s%s",S[0]+1,S[1]+1,T+1);
	N=strlen(S[0]+1),K=strlen(T+1);
	
	if(K==1)
	{
		Fr(i,0,1)Fr(j,1,N)ans+=S[i][j]==T[1];
	}
	else if(K==2)
	{
		Fr(i,0,1)Fr(j,1,N)if(S[i][j]==T[1])
			ans+=(S[i][j+1]==T[2])+(S[i][j-1]==T[2])+(S[i^1][j]==T[2]);
	}
	else
	{
		Solve();
		Fr(i,0,1)reverse(S[i]+1,S[i]+N+1);
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		Solve();
	}
	printf("%d\n",ans);
	
	return 0;
}