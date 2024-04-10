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
int N,K,F[MX],G[MX];
char S[MX];


int main()
{
	scanf("%d%d%s",&N,&K,S+1);
	F[0]=G[0]=-1;
	Fr(i,1,N)
	{
		int f=F[i-1],g=G[i-1];
		while(f!=-1&&S[f+1]!=S[i])f=F[f];
		while(g!=-1&&!(S[g+1]==S[i]&&(ll)(K+1)*(g+1)<=(ll)K*i))g=F[g];
		F[i]=f+1,G[i]=g+1;
		putchar('0'+((ll)K*G[i]>=(ll)(K-1)*i));
	}
	return 0;
}