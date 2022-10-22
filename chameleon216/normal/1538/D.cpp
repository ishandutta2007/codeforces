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

int Factor(int x)
{
	int c=0;
	for(int i=2;i*i<=x;++i)
		while(x%i==0)++c,x/=i;
	if(x>1)++c;
	return c;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);
		int ca=Factor(a),cb=Factor(b);
		if(2<=k&&k<=ca+cb)printf("YES\n");
		else if(k==1&&((a%b==0)^(b%a==0)))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}