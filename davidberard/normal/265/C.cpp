#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	map<int, int> order;
	int bot = 0;
	int top = s.length()+3;
	for(int i=0;i<s.length();++i)
	{
		if(s.at(i) == 'l')
		{
			top--;
			order[top] = i+1;
		}
		else
		{
			bot++;
			order[bot] = i+1;
		}
	}
	map<int, int>::iterator mit;
	for(mit=order.begin();mit!=order.end();++mit)
		cout << mit->second << "\n";
	cout << endl;
	

	return 0;
}