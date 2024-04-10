#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100;
char S[MX],T[MX],stk[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%s%s",S+1,T+1);
		int ls=strlen(S+1),lt=strlen(T+1),tp=0;
		Fr(i,1+((ls^lt)&1),ls)
		{
			if(stk[tp]==T[tp])stk[++tp]=S[i];
			else --tp;
		}
		printf((tp==lt&&stk[tp]==T[tp])?"YES\n":"NO\n");
	}
	return 0;
}