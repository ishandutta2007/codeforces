/*
Hanit Banga
Problem: Arpas overnight party and Mehrdads silent entering
*/

#include <iostream>
#include <vector>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int a[N], b[N], color[2*N] = {0};
vector <int> g[2*N];

void addEdge(int i, int j);
void colorGraph(int cur, int col);

int main()
{
	fast_cin();
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];

	for (int i = 1; i <= n; ++i)
	{
		addEdge(a[i], b[i]);
		addEdge(2*i - 1, 2*i);
	}

	for (int i = 1; i <= 2*n; ++i)
		if (!color[i])
			colorGraph(i, 1);

	for (int i = 1; i <= n; ++i)
		cout << color[a[i]] << ' ' << color[b[i]] << endl;
}

inline void addEdge(int i, int j)
{
	g[i].pb(j);
	g[j].pb(i);
}

void colorGraph(int cur, int col)
{
	color[cur] = col;

	for (auto i : g[cur])
	{
		if (!color[i])
			colorGraph(i, 3-col);
	}
}