#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=1000100,Mod=1000000007;
int N,C[MX],nx[MX],F[MX];
char S[MX];


int main()
{
	scanf("%s",S+1),N=strlen(S+1);
	int l=1,r=N;
	while(S[l]!='1'&&l<=N)++l;
	if(l>N){printf("%d\n",N);return 0;}
	while(S[r]!='1')--r;
	Fr(i,l,r)if(S[i]=='0')C[i]=C[i-1]+1;
	Fl(i,r,l)F[i]=((S[i]=='1')+F[nx[0]]+F[nx[C[i]+1]])%Mod,nx[C[i]]=i;
	printf("%lld\n",(ll)F[l]*(l)%Mod*(N-r+1)%Mod);
	return 0;
}