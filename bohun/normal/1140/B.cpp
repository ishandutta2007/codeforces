#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
int t[100005];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		string s;
		cin >> s;
		if(n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		else
		{
			int s1 = 0;
			int i = 0;
			while(i < n && s[i] == '<')
				i++, s1++;
			i = n - 1;
			int s2 = 0;
			while(i >= 0 && s[i] == '>')
				i--, s2++;
			cout << min(s1, s2) << endl;
		}
	}
	
	return 0;
}