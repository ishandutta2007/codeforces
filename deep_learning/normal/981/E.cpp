#include <cstdio>
#include <bitset>
#include <vector>
#define pb push_back
std::vector<int> vec[40005]; 
std::bitset<10005> ans; 
void modify(int u, int l, int r, int L, int R, int x)
{
	if (L <= l && r <= R)
	{
		vec[u].pb(x); 
		return; 
	}
	int m = l + r >> 1;
	if (L <= m)
		modify(u << 1, l, m, L, R, x); 
	if (m < R)
		modify(u << 1 | 1, m + 1, r, L, R, x); 
}
void query(int u, int l, int r, std::bitset<10005> mask)
{
	for (int x : vec[u])
		mask |= mask << x; 
	ans |= mask;
	if (l == r)
		return; 
	int m = l + r >> 1;
	query(u << 1, l, m, mask); 
	query(u << 1 | 1, m + 1, r, mask); 
}
int main()
{
	// freopen("981E.in", "r", stdin); 
	int n, q, cnt = 0; 
	scanf("%d%d", &n, &q); 
	for (int i = 0; i < q; i++)
	{
		int l, r, x; 
		scanf("%d%d%d", &l, &r, &x); 
		modify(1, 0, n - 1, --l, --r, x); 
	}
	query(1, 0, n - 1, std::bitset<10005>(1)); 
	for (int i = 1; i <= n; i++)
		cnt += ans[i]; 
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i++)
	{
		if (ans[i])
			printf("%d%c", i, " \n"[!--cnt]);
	}
	return 0; 
}