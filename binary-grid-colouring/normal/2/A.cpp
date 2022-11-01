#include <bits/stdc++.h>
using namespace std;
string s[1010];
int num[1010];
map<string, int> p, t;
int main()
{
	int maxx = 0, n;
	cin >> n;
	for (int i=0 ;i < n; i++)
	{
		cin >> s[i] >> num[i];
		p[s[i]] += num[i];
	}
	for (int i = 0; i < n; i++)
	{
		if ( p[s[i]] > maxx)
			maxx = p[s[i]];
	}
		
	int i = -1;
	while (p[ s[++i] ] < maxx || ( t[ s[i] ] += num[i]) < maxx);
	cout << s[i]<<endl;
	return 0;
}