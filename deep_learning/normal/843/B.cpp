#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cstdio>
#include <cctype>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
int n, st, x, cnt, val, nxt, mx, res, a[100005], b[100005]; 
inline void query(int pos, bool f)
{
#ifdef ONLINE_JUDGE
	printf("? %d\n", pos);
	fflush(stdout); 
	scanf("%d %d", &val, &nxt); 
#else
	val = a[pos]; 
	nxt = b[pos]; 
#endif
	if (f && val < x && val > mx)
	{
		mx = val; 
		res = pos; 
	}
}
inline void output(int num)
{
	printf("! %d\n", num);
	fflush(stdout); 
	exit(0); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("843B.in", "r", stdin); 
#endif
	srand((unsigned long long)new char); 
	scanf("%d%d%d", &n, &st, &x); 
#ifndef ONLINE_JUDGE
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i); 
#endif
	res = st; 
	query(st, true); 
	if (val >= x)
		output(val); 
	for (int i = 0; i < 1000; i++)
		query((rand() * 100 + rand()) % n + 1, true); 
	for (int i = 0; i < 990; i++)
	{
		query(res, false);
		if (nxt != -1 && val < x)
			res = nxt; 
		else if (val >= x)
			output(val); 
	}
	output(-1); 
	return 0; 
}