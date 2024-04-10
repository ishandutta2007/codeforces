#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=1010;

int N,A[MX];
pair<int,int> stk[MX];
int tp;

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	ll ans=0;
	Fr(i,1,N)
	{
		if(i&1)stk[++tp]=make_pair(A[i],0);
		else
		{
			int a=A[i];
			while(tp&&a)
			{
				if(stk[tp].first<=a)
				{
					ans+=stk[tp].first;
					a-=stk[tp--].first;
					ans+=stk[tp].second;
					++stk[tp].second;
				}
				else
				{
					ans+=a;
					stk[tp].first-=a;
					a=0;
					stk[tp].second=1;
				}
			}
			if(a)stk[0].second=0;
		}
	}
	printf("%lld\n",ans);
	return 0;
}