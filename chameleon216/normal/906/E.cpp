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

const int MX=1000100,Inf=0x3f3f3f3f;
int N,dp[MX];
char S[MX],S1[MX],S2[MX];

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
		J[y]=(D[y]==D[F[y]]?J[F[y]]:F[y]);
	}
	las=C[x][k];
}

void Print()
{
	int p=N,x=1;
	Fl(i,N,1)
	{
		int k=S[i]-'a';
		while(S[i]!=S[i+len[x]+1])x=F[x];
		x=C[x][k];
//		printf("i=%d p=%d dp=%d x=%d len=%d\n",i,p,dp[p],x,len[x]);
		
		if(len[x]==p-i+1&&dp[i-1]==dp[p]-(len[x]>2))
		{
			if(len[x]>2)printf("%d %d\n",(i+1)/2,p/2);
			p=i-1,x=1,S[i]=0;
		}
	}
}

int main()
{
	scanf("%s%s",S1+1,S2+1);
	int n=strlen(S1+1);
	Fr(i,1,n)S[++N]=S1[i],S[++N]=S2[i];
//	scanf("%s",S+1),N=strlen(S+1);
	
//	printf("%d\n",N),puts(S+1);
	
	Init();
	Fr(i,1,N)
	{
		Extend(i),dp[i]=Inf;
		for(int x=las;x>2;x=J[x])
		{
			W[x]=dp[i-len[J[x]]-D[x]];
			if(F[x]!=J[x])W[x]=min(W[x],W[F[x]]);
			dp[i]=min(dp[i],W[x]+1);
		}
		if(i&1)dp[i]=Inf;
		else if(S[i]==S[i-1])dp[i]=min(dp[i],dp[i-2]);
	}
	
	if(dp[N]==Inf){printf("-1\n");return 0;}
	
	printf("%d\n",dp[N]);
	Print();
	
//	Fr(i,1,N)printf("%d ",dp[i]);putchar('\n');
	
	/*int s=0;
	Fr(i,1,pc)s+=F[i]+len[i]+accumulate(C[i],C[i]+26,0);
	printf("%d\n",s);*/
	
	return 0;
}