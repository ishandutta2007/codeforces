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

const int MX=2010;
int N,L[MX],R[MX];
char S[MX];


int main()
{
	scanf("%s",S+1),N=strlen(S+1);
	Fr(i,1,N)for(int l=i,r=i;1<=l&&r<=N&&S[l]==S[r];--l,++r)++L[l],++R[r];
	Fr(i,2,N)for(int l=i-1,r=i;1<=l&&r<=N&&S[l]==S[r];--l,++r)++L[l],++R[r];
	ll ans=0;
	Fr(i,1,N)R[i]+=R[i-1],ans+=(ll)R[i]*L[i+1];
	printf("%lld\n",ans);
	return 0;
}