#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=1200;
int N;
char S[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%s",&N,S+1);
		S[N+1]='R';
		int p=N+1;
		Fr(i,1,N+1)if(S[i]!='?'){p=i;break;}
		Fl(i,p-1,1)if(S[i]=='?')
			S[i]=(S[i+1]=='R'?'B':'R');
		Fr(i,p+1,N)if(S[i]=='?')
			S[i]=(S[i-1]=='R'?'B':'R');
		S[N+1]=0;
		printf("%s\n",S+1);
	}
	return 0;
}