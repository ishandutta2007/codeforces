#include <bits/stdc++.h>
#define m_k make_pair
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+100;
int n,q,vi[3][N];
set <int> s;
bool check(int x)
{
	if (vi[1][x+1] && vi[2][x]) return 1;
	if (vi[1][x] && vi[2][x+1]) return 1;
	if (vi[1][x] && vi[2][x]) return 1;
	if (vi[1][x+1] && vi[2][x+1]) return 1;
	return 0;
}
void del(int x)
{
	set <int> :: iterator it;
	it=s.lower_bound(x);
	s.erase(it);
}
signed main()
{
	scanf("%d%d",&n,&q);
	for (int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if (vi[x][y])
		{
			if (y==1)
			{
				int a=check(y),b;
				vi[x][y]=0;
				b=check(y);
				if (a && !b) del(y);
				if (s.empty()) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			int a=check(y),b=check(y-1),c,d;
			vi[x][y]=0;
			c=check(y);d=check(y-1);
			if (a && !c) del(y);
			if (b && !d) del(y-1);
		}
		else
		{
			if (y==1)
			{
				int a=check(y),b;
				vi[x][y]=1;
				b=check(y);
				if (!a && b) s.insert(y);
				if (s.empty()) printf("Yes\n");
				else printf("No\n");
				continue;
			}
			int a=check(y),b=check(y-1),c,d;
			vi[x][y]=1;
			c=check(y);d=check(y-1);
			if (!a && c) s.insert(y);
			if (!b && d) s.insert(y-1);
		}
		if (s.empty()) printf("Yes\n");
		else printf("No\n");
	}
}