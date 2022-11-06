#include <cstdio>
namespace fast_IO
{
	typedef long long ll; 
	char buf[10000005]; 
	int cur_p = -1, len; 
	inline int getch()
	{
		if (++cur_p >= len)
		{
			len = fread(buf, 1, 10000005, stdin); 
			cur_p = 0; 
		}
		return buf[cur_p]; 
	}
	inline ll getll()
	{
		ll res = 0; 
		int c = getch(), f = 1; 
		if (c == '-')
		{
			f = -1; 
			c = getch(); 
		}
		for (; c < 48 || c > 57; c = getch()); 
		for (; c >= 48 && c <= 57; c = getch())
			res = (res << 3) + (res << 1) + c - 48; 
		return f == 1 ? res : -res; 
	}
	inline int getint()
	{
		int res = 0, c = getch(), f = 1; 
		if (c == '-')
		{
			f = -1; 
			c = getch(); 
		}
		for (; c < 48 || c > 57; c = getch()); 
		for (; c >= 48 && c <= 57; c = getch())
			res = (res << 3) + (res << 1) + c - 48; 
		return f == 1 ? res : -res; 
	}
}
using fast_IO::getint; 
using fast_IO::getll; 
using fast_IO::getch; 
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define pb push_back
#define mp make_pair
using namespace std; 
typedef long long ll; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("871A.in", "r", stdin); 
#endif
	int q; 
	scanf("%d", &q);
	while (q--)
	{
		int n; 
		scanf("%d", &n); 
		if ((n & 3) == 1)
			printf("%d\n", (n >> 2) < 2 ? -1 : (n >> 2) - 1);
		else if ((n & 3) == 2)
			printf("%d\n", !(n >> 2) ? -1 : (n >> 2));
		else if ((n & 3) == 3)
			printf("%d\n", (n >> 2) < 3 ? -1 : (n >> 2) - 1);
		else
			printf("%d\n", n >> 2);
	}
	return 0; 
}