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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

int n;
vvi g;
double ans=0.0;

void dfs(int v,int len=1,int pr=-1)
{
	ans += (1.0/len);
	for (int i=0; i<g[v].size(); i++)
		if (g[v][i]!=pr)
			dfs(g[v][i],len+1,v);
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n;
	g.resize(n+1);
	for (int i=0; i<n-1; i++)
	{
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1);
	cout << fixed << setprecision(15) << ans << endl;

	return 0;
}