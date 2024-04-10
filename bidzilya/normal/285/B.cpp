#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n,s,t;
vector<int> p,used;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#endif
	cin >> n >> s >> t;
	p.resize(n+1);
	used.resize(n+1);
	for (int i=1; i<=n; i++)
		cin >> p[i];
	int ans=0;
	while (1)
	{
		if (s==t)
		{
			cout << ans << endl;
			return 0;
		}
		used[s]=1;
		ans++;
		s=p[s];
		if (used[s])
			break;
	}
	cout << -1 << endl;
	return 0;
}