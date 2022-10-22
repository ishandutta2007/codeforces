#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

typedef set<int>::iterator Iter;
set<int> se;
void Calc(int a,int b,int x,int y)
{
	int u=min(a,y),d=max(0,y-b);
	Fr(i,d,u)se.insert(i+x-(a-i));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		se.clear();
		int x,y,s;
		scanf("%d%d",&x,&y),s=x+y;
		if(s&1)Calc(s/2,s/2+1,x,y),Calc(s/2+1,s/2,x,y);
		else Calc(s/2,s/2,x,y);
		printf("%d\n",(int)se.size());
		for(Iter it=se.begin();it!=se.end();++it)
			printf("%d ",*it);
		putchar('\n');
	}
	return 0;
}