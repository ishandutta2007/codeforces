#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;

string s;
int n;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> s;
	int bil = 0;
	int a = 0, b = 0;
	for(int i = 0; n > i; ++i)
	{
		if(s[i] == '(')
			++a, ++bil;
		else if(s[i] == ')')
			++b, --bil;
	}
	int need = n /2 - a;
	if(n % 2 == 1)
	{
		cout << ":(";
		return 0;
	}
	bil = 0;
	for(int i = 0; n > i; ++i)
	{
		if(s[i] == '(')
			++bil;
		if(s[i] == ')')
			--bil;
		if(s[i] == '?' && need)
			s[i] = '(', --need, ++bil;
		else if(s[i] == '?')
			s[i] = ')', --bil;
				if(bil <= 0 && i < n - 1)
		{
			cout << ":(";
			return 0;
		}
	}
	if(bil != 0)
	{
		cout << ":(";
		return 0;
	}
	for(int i = 0; n > i; ++i)
		cout << s[i];
	
			
	
	
	
	
	
	
	
	// fflush(stdout)
	return 0;
}