#include<iostream>
#include<set>
#include<string>
using namespace std;
bool pri(int k)
{
	if (k == 1) return false;
	for (int i = 2; i * i <= k; i++)
	{

		if (k % i == 0) return false;
	}
	return true;
}
long gcd(long a, long b)
{
	if (b == 0)
	{
		return a;
	}

	else
	{
		return gcd(b, a % b);
	}
}

int main()
{
	bool ans = 0;
	long long n, m;
	cin >> n >> m;
	set <string> a, b, c;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		 a.insert(s);
		//else b.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		b.insert(s);
	}
	for (auto &x : a)
	{
		if (b.count(x) == 1) c.insert(x);
	}
	for (auto &x : c)
	{
		a.erase(x);
		b.erase(x);
	}
	long long sa = a.size();
	long long sb = b.size();
	long long sc = c.size();
	if (! (sc % 2 == 0))
	{
		if (sb > sa)
		{
			ans = 0;
			if( ! ans) cout << "NO";
			return 0;
		}
		else
		{
			ans = 1;
			if( ans ) cout << "YES";
			return 0;
		}
	}
	else
	{
		if (sa > sb)
		{
			ans = 1;
			if(ans) cout << "YES";
			return 0;
		}
		else
		{
			ans = 0;
			if( !ans ) cout << "NO";
			return 0;
		}
	}
	return 0;
}