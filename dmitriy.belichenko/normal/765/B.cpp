#include <iostream>
#include<algorithm>
#include<vector>
#include <set>
#include<string>
#include<vector>
using namespace std;
long long n;
int main()
{
	//freopen("ladder.in", "r", stdin);
	//freopen("ladder.out", "w", stdout);
	string s;
	cin >> s;
	set<char> st;
	int mn = 900;
	int cnt = 0;
	int mx = 'a';
	
	bool flag = 0;
	if (s[0] != 'a') flag = 1;
	char prev = 'a';
	for (int i = 0; i < s.size(); i++)
	{
		
		if (s[i] - mx > 1) flag = 1;
		if (st.count(s[i]) == 0)
		{
			st.insert(s[i]);
			mn = min(mn, (int)s[i]);
			mx = max(mx, (int)s[i]);
		}
		//prev = s[i];
	}
	cnt = s.size();
	//cout << mn << " " << mx << " " << st.size() <<" " << flag << endl;
	if (flag)
	{
		cout << "NO";
		return 0;
	}
	if (((mx - mn + 1) % st.size() == 0 && (mx - mn + 1) == st.size()) || mx == mn)
	{
		cout << "YES";
	}
	else cout << "NO";

}