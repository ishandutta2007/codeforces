#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=220000;
int N,M;
char S[MX],T[MX];
int L[MX],R[MX];

int main()
{
	scanf("%d%d%s%s",&N,&M,S+1,T+1);
	Fr(i,1,M)
	{
		L[i]=L[i-1]+1;
		char c=T[i];
		while(S[L[i]]!=c)++L[i];
	}
	R[M+1]=N+1;
	Fl(i,M,1)
	{
		R[i]=R[i+1]-1;
		char c=T[i];
		while(S[R[i]]!=c)--R[i];
	}
	//Fr(i,1,M)printf("%d ",L[i]);putchar('\n');
	//Fr(i,1,M)printf("%d ",R[i]);putchar('\n');
	int mx=0;
	Fo(i,1,M)mx=max(mx,R[i+1]-L[i]);
	printf("%d\n",mx);
	return 0;
}