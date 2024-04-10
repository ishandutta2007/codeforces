#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, m, s, f;
int t[1 << 17], L[1 << 17], R[1 << 17];

int main()
{
	scanf("%d%d%d%d", &n, &m, &s, &f);
	for(int i = 0; i < m; ++i)
		scanf("%d%d%d", &t[i], &L[i], &R[i]);
	int cur = 0;
	string res = "";
	for(int T = 1; ; ++T)
	{
		if (s == f)
			break;
		int to = s < f ? s + 1 : s - 1;
		if (t[cur] == T)
		{
			if (L[cur] <= s && s <= R[cur] || L[cur] <= to && to <= R[cur])
				res += 'X';
			else
			{
				res += (s < f ? 'R' : 'L');
				s = to;
			}
			cur++;
		}
		else
		{
			res += (s < f ? 'R' : 'L');
			s = to;
		}
	}
	printf("%s\n", res.c_str());
	return 0;
}