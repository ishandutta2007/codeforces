#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <functional>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

priority_queue<int,vector<int>,greater<int> > Q;
int N;

int main()
{
	scanf("%d",&N);
	ll ans=0;
	Fr(i,1,N)
	{
		int a;
		scanf("%d",&a);
		if(!Q.empty()&&Q.top()<a)
		{
			ans+=a-Q.top(),Q.pop();
			Q.push(a),Q.push(a);
		}
		else Q.push(a);
	}
	printf("%lld\n",ans);
	return 0;
}