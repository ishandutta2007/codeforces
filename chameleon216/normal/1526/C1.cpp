#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

int N;
priority_queue<int> Q;

int main()
{
	scanf("%d",&N);
	ll h=0;
	Fr(i,1,N)
	{
		int x;
		scanf("%d",&x);
		if(h+x>=0)h+=x,Q.push(-x);
		else if(!Q.empty())
		{
			int y=-Q.top();
			if(y<x)h-=y,h+=x,Q.pop(),Q.push(-x);
		}
	}
	printf("%d\n",(int)Q.size());
	return 0;
}