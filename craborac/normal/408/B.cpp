#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int ss[30], tt[30];
int main()
{
	string s, t;
	cin >> s;
	cin >> t;
	int n = s.size();
	int m = t.size();
	for(int i = 0; i < 30; i++)
	{
		ss[i] = 0;
		tt[i] = 0;
	}
	for(int i = 0; i < n; i++)
		ss[s[i] - 'a']++;
	for(int j = 0; j < m; j++)
		tt[t[j] - 'a']++;
	int ans = 0;
	for(int i = 0; i < 30; i++)
	{
		if((ss[i] == 0) && (tt[i] != 0))
		{
			ans = -1;
			break;
		}
		if(ss[i] >= tt[i])
			ans += tt[i];
		else
			ans += ss[i];
	}	
	printf("%d", ans);
	return 0;
}