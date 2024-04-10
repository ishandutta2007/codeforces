#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#ifdef ONLINE_JUDGE
#define inpll(x) scanf("%I64d", &x); 
#define putll(x) printf("%I64d\n", x);
#define putlls(x) printf("%I64d ", x);
#else
#define inpll(x) scanf("%lld", &x); 
#define putll(x) printf("%lld\n", x);
#define putlls(x) printf("%lld ", x);
#endif
using namespace std; 
int cnt[26]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("715B.in", "r", stdin); 
#endif
	string str; 
	cin >> str;
	for (int i = 25; i < str.size(); i++)
	{
		memset(cnt, 0, sizeof(cnt)); 
		for (int j = i - 25; j <= i; j++)
		{
			if (str[j] != '?')
				cnt[str[j] - 'A']++; 
		}
		bool f = true;
		for (int j = 0; j < 26; j++)
		{
			if (cnt[j] > 1)
			{
				f = false; 
				break; 
			}
		}
		if (f)
		{
			int x = 0; 
			for (int j = i - 25; j <= i; j++)
			{
				while (cnt[x])
					x++; 
				if (str[j] == '?')
				{
					str[j] = x + 'A'; 
					cnt[x]++; 
				}
			}
			for (int j = 0; j < str.size(); j++)
			{
				if (str[j] == '?')
					str[j] = 'A'; 
			}
			cout << str << endl; 
			return 0; 
		}
	}
	cout << -1 << endl; 
	return 0; 
}