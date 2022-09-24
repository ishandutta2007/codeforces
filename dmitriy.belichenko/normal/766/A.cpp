#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ull unsigned long long
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;
bool cmp(pair<long long, long long > &a, pair<long long, long long >  &b){ return b < a;}
 int main()
{	
	string a, b;
	cin >> a >> b;
	if (a != b)
	{
		if (a.length() > b.length())
			cout << a.length();
		else
			cout << b.length();
	}
	else
		cout << -1;
	return 0;
}