#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000100;
int N;
char S[MX];
int F[MX];

int main()
{
	scanf("%s",S+1);
	N=strlen(S+1);
	F[0]=-1;
	Fr(i,1,N)
	{
		int j=F[i-1];
		while(j!=-1&&S[j+1]!=S[i])j=F[j];
		F[i]=j+1;
	}
	int mx=0;
	Fr(i,2,N-1)mx=max(mx,F[i]);
	for(int i=N;i;i=F[i])if(i<=mx)
	{
		Fr(j,1,i)putchar(S[j]);
		putchar('\n');
		return 0;
	}
	printf("Just a legend\n");
	return 0;
}