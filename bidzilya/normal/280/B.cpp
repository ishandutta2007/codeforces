#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-9;
const double PI = acos(-1.0);

stack<int> s;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	int ans=0;
	for (;n;n--)
	{
		int a;
		cin >> a;
		while (!s.empty() && s.top()<a)
		{
			ans=max(ans,a^s.top());
			s.pop();
		}
		if (!s.empty())ans=max(ans,a^s.top());
		s.push(a);
	}
	cout << ans << endl;
	return 0;
}