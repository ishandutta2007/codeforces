#include <bits/stdc++.h>

template <class T>
inline void tense(T &x, const T &y)
{
	if (x > y)
		x = y; 
}

typedef long long s64; 

const int MaxM = 22; 
const int MaxN = 1e5 + 5; 
const int MaxS = 1 << 20; 

int n, m; 
int f[MaxS]; 
char s[MaxN]; 

int pow2_pos[MaxS]; 
int totpos[MaxN], cnt[MaxM][MaxM]; 
int cnt_pre[MaxS][MaxM]; 

inline int pop_count(int s)
{
	int res = 0; 
	while (s)
		s ^= s & -s, ++res; 
	return res; 
}

int main()
{
	scanf("%d%d", &n, &m); 
	scanf("%s", s + 1); 

	for (int i = 2; i <= n; ++i)
	{
		int a = s[i - 1] - 'a', b = s[i] - 'a'; 
		++cnt[a][b]; 
		++cnt[b][a]; 
	}

	memset(f, 0x3f, sizeof(f)); 
	
	int all = (1 << m) - 1; 
	f[0] = 0;
	for (int i = 0; i < m; ++i)
		pow2_pos[1 << i] = i;  

	for (int s = 1; s < all; ++s)
	{
		int pos = pow2_pos[s & -s]; 
		for (int i = 0; i < m; ++i)
			if (~s >> i & 1)
				cnt_pre[s][i] = cnt_pre[s ^ (1 << pos)][i] + cnt[i][pos]; 
	}

	for (int s = 0; s < all; ++s)
	{
		int has = pop_count(s); 
		for (int i = 0; i < m; ++i)
			if (~s >> i & 1)
			{
				int tmp = cnt_pre[s][i] - cnt_pre[all ^ s ^ (1 << i)][i]; 
				tense(f[s | (1 << i)], 
					  f[s] + tmp * (has + 1)); 
			}
	}

	std::cout << f[all] << std::endl; 

	return 0; 
}