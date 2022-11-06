#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef ONLINE_JUDGE
#define put_ll(x) printf("%I64d\n", x);
#define inp_ll(x) scanf("%I64d", &x); 
#define put_ll_space(x) printf("%I64d ", x);
#else
#define put_ll(x) printf("%lld\n", x);
#define inp_ll(x) scanf("%lld", &x); 
#define put_ll_space(x) printf("%lld ", x);
#endif
using namespace std; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("722A.in", "r", stdin); 
#endif
	int n; 
	scanf("%d", &n); 
	string str; 
	cin >> str; 
	if (n == 12)
	{
		int ans = 100, pos; 
		for (int i = 1; i <= 12; i++)
		{
			int cnt = (str[0] - '0' != i / 10) + (str[1] - '0' != i % 10); 
			if (cnt < ans)
			{
				ans = cnt; 
				pos = i; 
			}
		}
		str[0] = pos / 10 + '0'; 
		str[1] = pos % 10 + '0'; 
	}
	else
	{
		int ans = 100, pos; 
		for (int i = 0; i <= 23; i++)
		{
			int cnt = (str[0] - '0' != i / 10) + (str[1] - '0' != i % 10); 
			if (cnt < ans)
			{
				ans = cnt; 
				pos = i; 
			}
		}
		str[0] = pos / 10 + '0'; 
		str[1] = pos % 10 + '0'; 
	}
	int ans = 100, pos; 
	for (int i = 0; i <= 59; i++)
	{
		int cnt = (str[3] - '0' != i / 10) + (str[4] - '0' != i % 10); 
		if (cnt < ans)
		{
			ans = cnt; 
			pos = i; 
		}
	}
	str[3] = pos / 10 + '0'; 
	str[4] = pos % 10 + '0'; 
	cout << str << endl;
	return 0; 
}