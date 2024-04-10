#include<cstdio>
#include<algorithm>
#include<assert.h>
using namespace std;
typedef long long ll;

ll w[4];
int main()
{
	scanf("%lld%lld%lld",w+1,w+2,w+3);
	puts("First"); fflush(stdout);
	puts("10000000000"); fflush(stdout);
	int t; scanf("%d",&t); if (!t) return 0;
	w[t]+=1e10; ll k=w[t]*3-w[1]-w[2]-w[3];
	printf("%lld\n",k); fflush(stdout);
	int s; scanf("%d",&s); if (!s) return 0;
	w[s]+=k; assert(w[s]>w[t]&&w[t]>w[1]+w[2]+w[3]-w[s]-w[t]&&w[s]-w[t]==w[t]-(w[1]+w[2]+w[3]-w[s]-w[t]));
	printf("%lld\n",w[s]-w[t]); fflush(stdout);
	int a; scanf("%d",&a); assert(a==0); return 0;
}