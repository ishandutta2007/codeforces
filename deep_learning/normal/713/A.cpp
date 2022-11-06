#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
typedef long long ll; 
int son[2000005][2], cnt[2000005], tot = 1; 
char str[25]; 
inline void modify(ll x, int num)
{
	int p = 0; 
	for (int i = 0; i < 18; i++)
	{
		int &v = son[p][x & 1]; 
		if (v == -1)
			v = tot++; 
		p = v; 
		x /= 10; 
	}
	cnt[p] += num; 
}
inline int query(char *str)
{
	int p = 0; 
	for (int i = 17; i >= 0; i--)
	{
		int v = son[p][str[i] - '0']; 
		if (v == -1)
			return 0; 
		p = v; 
	}
	return cnt[p]; 
}
int main()
{
	// freopen("A.in", "r", stdin); 
	memset(son, -1, sizeof(son)); 
	int t; 
	scanf("%d", &t); 
	while (t--)
	{
		char tp; 
		scanf("\n%c", &tp); 
		if (tp == '?')
		{
			scanf("%s", str); 
			int len = strlen(str); 
			for (int i = len - 1; i >= 0; i--)
				str[i + 18 - len] = str[i]; 
			for (int i = 0; i < 18 - len; i++)
				str[i] = '0'; 
			printf("%d\n", query(str));
		}
		else
		{
			ll x; 
			scanf("%lld", &x); 
			modify(x, (tp == '+' ? 1 : -1)); 
		}
	}
	return 0; 
}