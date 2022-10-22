#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=200;
char S[MX];
int N,K;
int mian()
{
	scanf("%d%d",&N,&K);
	scanf("%s",S+1);
	if(N<=2*K)return 0;
	Fr(i,1,K)
	{
		int l=i,r=N-i+1;
	//	printf("%d %d\n",l,r);
		if(S[l]!=S[r])return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r=mian();
		if(r)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}