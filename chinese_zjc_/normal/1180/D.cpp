// This code Write By chtholly_micromaker(MicroMaker)
#include <cstdio>
#include <cctype>
#define reg register
using namespace std;
template <class t> inline void rd(t &s)
{
	s=0;
	reg char c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return;
}
signed main(void)
{
	int n,m;rd(n);rd(m);
	for(int i=1;i<=(n>>1);++i)
		for(int j=1;j<=m;++j)
			printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
	if(n&1)
	{
		n=(n+1)>>1;
		for(int i=1;i<=(m>>1);++i)
			printf("%d %d\n%d %d\n",n,i,n,m-i+1);
		if(m&1)
			printf("%d %d\n",n,(m+1)>>1);
	}
	return 0;
}