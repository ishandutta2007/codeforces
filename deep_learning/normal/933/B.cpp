#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
int cnt, seq[100005]; 
void work(ll p, int k)
{
	if (!p)
		return; 
	ll r = p % k; 
	if (r < 0)
		r += k; 
	seq[cnt++] = r; 
	work(-(p - r) / k, k); 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("933B.in", "r", stdin); 
#endif
	ll p; 
	int k; 
	scanf("%lld%d", &p, &k); 
	work(p, k); 
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d%c", seq[i], " \n"[i + 1 == cnt]);
	return 0; 
}