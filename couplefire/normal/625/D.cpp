#include <bits/stdc++.h>
using namespace std;
 
inline int in() { int x; scanf("%d", &x); return x; }
const int N = 200002;
 
char s[N];
int num[N], tmp[N], ans[N], n;
 
bool solve(int l, int r)
{
	if(l > r)
		return 0;
	if(l == r)
	{
		if(num[l] % 2)
			return 1;
		ans[l] = num[l]/2;
		return 0;
	}
	if(num[l] == num[r] + 1)
	{
		num[l]--;
		num[l + 1] += 10;
	}
	if((num[l] >= 10 && num[r] < 10) || num[r] < 0)
	{
		num[r] += 10;
		num[r - 1]--;
	}
	if(num[l] == num[r] + 1)
	{
		num[l]--;
		num[l + 1] += 10;
	}
	if(num[l] != num[r])
		return 1;
	ans[l] = min(9, num[l] - 1);
	ans[r] = num[l] - ans[l];
	if(ans[r] > ans[l])
		swap(ans[l], ans[r]);
	if(!num[l])
		ans[l] = ans[r] = 0;
	if(ans[l] > 9)
		return 1;
	return solve(l + 1, r - 1);
}
 
int main()
{
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++)
		num[i] = tmp[i] = s[i] - '0';
	bool bad = solve(0, n - 1);
	bad |= !ans[0];
	if(bad)
	{
		for(int i = 0; i < n; i++)
			num[i] = tmp[i];
		num[1] += 10;
		bad = (num[0] != 1);
		bad |= solve(1, n - 1);
		bad |= !ans[1];
		if(!bad)
		{
			for(int i = 0; i < n - 1; i++)
				ans[i] = ans[i + 1];
			n--;
		}
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;
}