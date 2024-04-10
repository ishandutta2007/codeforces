#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=100100;
int N,A[MX];
map<int,ll> mp;


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		ll sum=0;
		Fr(i,1,N)sum+=mp[A[i]]*(N-i+1),mp[A[i]]+=i;
		printf("%lld\n",sum);
		mp.clear();
	}
	return 0;
}