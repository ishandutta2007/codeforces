#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
map < char , int > m;
int main()
{
	m['a'] = m['e'] = m['i'] = m['y'] = m['u'] = m['o'] = 1;
	int n;
	string s;
	cin >> n;
	cin >> s;
	while(true)
	{
		string mm;
		int i = 0;
		for(i = 0; (int)s.size() - 1 > i; ++i)
		{
			if((int)m[s[i]] == 1 and m[s[i+1]] == 1)
				break;
		}
		if(i == (int)s.size() - 1)
		{
			cout << s;
			return 0;
		}
		for(int j = 0; i >= j; ++j)
			mm.push_back(s[j]);
		for(int j = i + 2; (int)s.size() > j ; ++j)
			mm.push_back(s[j]);
		s = mm;
	}
}