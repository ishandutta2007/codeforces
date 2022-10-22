#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=100100,Inf=0x3f3f3f3f;
int N;
char A[MX],B[MX];

int mian()
{
	scanf("%d%s%s",&N,A+1,B+1);
	int ca=0,cb=0;
	Fr(i,1,N)
	{
		A[i]-='0',B[i]-='0';
		ca+=A[i],cb+=B[i];
	}
	int ans=Inf;
	if(ca==cb)
	{
		int s=0;
		Fr(i,1,N)s+=(A[i]!=B[i]);
		ans=min(ans,s);
	}
	if(N+1-ca==cb)
	{
		int s=0;
		Fr(i,1,N)s+=(A[i]==B[i]);
		ans=min(ans,s);
	}
	if(ans==Inf)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
	}
	return 0;
}