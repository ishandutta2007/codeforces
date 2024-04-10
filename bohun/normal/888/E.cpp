#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n, m;
int a;
set < int > x;
set < int > daj(vector < int > &A)
{
	x.clear();
	for(int i = 0; (1 << (int)A.size()) > i; ++i)
	{
		ll sum = 0;
		for(int j = 0; (int)A.size() > j; ++j)
		{
			if((1 << j) & i)
				sum += A[j];
		}
		sum %= m;
		x.insert(sum);
	}
	return x;
}
int main()
{
	vector < int > A, B;
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a;
		if(i * 2 <= n)
			A.push_back(a);
		else
			B.push_back(a);
	}
	set < int > c = daj(A), d = daj(B);
	int ans = 0;
	for(auto it: c)
	{
		int val = *--d.upper_bound(m - 1 - it);
		ans = max(ans, val + it);
	}
	cout << ans;
	
	return 0;
}