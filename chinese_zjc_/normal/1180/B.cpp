// This code Write By chtholly_micromaker(MicroMaker)
#include <cstdio>
#include <cctype>
#include <algorithm>
#define reg register
using namespace std;
const int MaxN=100005;
struct Node
{
	int val,idx;
}a[MaxN];
template <class t> inline void rd(t &s)
{
	s=0;
	reg int f=1;
	reg char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();	
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
inline bool cmp(const Node &A,const Node &B)
{
	return A.val<B.val;
}
inline bool cmp2(const Node &A,const Node &B)
{
	return A.idx<B.idx;
}
signed main(void)
{
	int n;rd(n); 
	reg int cnt=0;
	for(int i=1;i<=n;++i)
	{
		rd(a[i].val),a[i].idx=i;
		if(a[i].val>=0)
			a[i].val*=-1,a[i].val--;
	}
	sort(a+1,a+n+1,cmp);
	if(n&1)
		a[1].val*=-1,a[1].val--;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i].val);
	return 0;
}