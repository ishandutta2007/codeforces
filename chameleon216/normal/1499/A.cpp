#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;

int mian()
{
	int N,A1,A2,a,b;
	scanf("%d%d%d%d%d",&N,&A1,&A2,&a,&b);
	int ac=A1+A2,bc=N+N-ac;
	return a*2<=ac&&b*2<=bc;
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