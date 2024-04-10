#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define sz(a) ((int)(a).size())
typedef long long ll;
typedef double dbl;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = 1.01e9;
const dbl eps = 1e-9;


const int N = 2e5 + 10;

vi v[N];
set<int> s[N];
int dead[N];
int deg[N];


int main()
{

	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x = x - 1; 
		y = y - 1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < n; i++) deg[i] = sz(v[i]);

	set<pair<pi, int>> S;

	for (int i = 0; i < n; i++) S.insert({ { deg[i], sz(s[i]) }, i });

	int res = -1;

	for (int it = 0; it < n; it++)
	{
		int x = S.begin()->second;
		S.erase(S.begin());
		if (it == n - 1)
		{
			vi z;
			for (int y : s[x]) z.push_back(y);
			if (sz(z) == 1) res = z[0];
			else if (sz(z) == 2) res = z[0] + z[1];
			break;
		}
		dead[x] = 1;
		
		int len = 0;
		if (sz(s[x]) > 1) break;
		if (sz(s[x]) == 1) len = *s[x].begin();

		int y = -1;
		for (int z : v[x]) if (!dead[z]) y = z;

		S.erase({ { deg[y], sz(s[y]) }, y });
		deg[y]--;
		s[y].insert(len + 1);
		S.insert({ { deg[y], sz(s[y]) }, y });
	}

	if (res >= 0)
	{
		while (res % 2 == 0) res /= 2;
		cout << res << endl;
	}
	else puts("-1");




	return 0;
}