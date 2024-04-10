#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100,Inf=0x3f3f3f3f;
int N,M,A[MX],G[MX];
int D[MX],dc,dp[MX],las[MX],pre[MX],B[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	scanf("%d",&M);
	Fr(i,1,M)scanf("%d",&G[i]);
	sort(G+1,G+M+1);
	
	Fr(i,1,N)
	{
		if(A[i]!=-1)
		{
			int p=lower_bound(D+1,D+dc+1,A[i])-D;
			D[p]=A[i],dc=max(dc,p);
			dp[i]=p,pre[i]=las[p],las[p]=i;
		}
		else
		{
			if(G[M]>D[dc])D[++dc]=Inf;
			for(int k=dc,j=M;k>0;--k)
			{
				while(j>1&&G[j-1]>D[k-1])--j;
				D[k]=min(D[k],G[j]);
			}
		}
	}
	
	int n=N+1,l=dc+1,x=Inf;
	while(l>1)
	{
		int a=las[l-1];
		if(a&&A[a]<x)
		{
			while(n>a)--n,las[dp[n]]=pre[n];
			--l,x=A[a];
		}
		else
		{
			while(1)
			{
				--n,las[dp[n]]=pre[n];
				if(A[n]==-1)break;
			}
			int i=lower_bound(G+1,G+M+1,x)-G-1;
			--l,B[i]=1,A[n]=x=G[i];
		}
	}
	
	for(int i=1,j=1;i<=N;++i)if(A[i]==-1)
	{
		while(B[j])++j;
		A[i]=G[j],B[j]=1;
	}
	Fr(i,1,N)printf("%d ",A[i]);putchar('\n');
	
	return 0;
}