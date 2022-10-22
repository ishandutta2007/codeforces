#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k, a, b;
const int nax = 50005;
vector <int> v[nax]; // ssiedzi wierzchoka 
bool alive[nax]; // czy jest jeszcze w naszym  grafie
ll ans = 0; // wynik
int dp[nax]; // liczba wierzchokw w jego poddrzewie 
int nn = 0;
int h[nax]; // liczba wierzchokw na danej gbokoci 
vector <int> A, B; // 
void licz(int node, int par) // liczby wielkoci poddrzew
{
	nn++;
	dp[node] = 1;
	for(int i = 0; ss(v[node]) > i; ++i)
	{
		int to = v[node][i];
		if(alive[to] == 1 and to != par)
			{
				licz(to, node);
				dp[node] += dp[to];
			}
	}
}
int daj(int node, int par) // zwraca centroid
{
	for(int i = 0; ss(v[node]) > i; ++i)
	{
		int to = v[node][i];
		if(alive[to] == 1 and to != par and dp[to] > nn / 2)
			return daj(to, node);
	}
	return node;
}
int w = 0;
void add(int node, int par, int depth)
{
	A.pb(depth);
	B.pb(depth);
	for(int i = 0; ss(v[node]) > i; ++i)
	{
		int to = v[node][i];
		if(node == w)
		{
			for(auto it: B)
				h[it]++;
			B.clear();
		}
		if(alive[to] == 1 and to != par)
		{
			add(to, node, depth + 1);
		}
	}
	if(node != w and k - depth >= 0)
		ans += h[k - depth];
}
	
	
void Decomp(int node)
{
	nn = 0;
	licz(node, -1);
	int c = daj(node, -1);
	w = c;
	alive[c] = 0;
	A.clear();
	B.clear();
	add(c, -1, 0);
	for(auto it: A)
		h[it] = 0;
	for(int i = 0; ss(v[c]) > i; ++i)
	{
		int to = v[c][i];
		if(alive[to] == 1)
			Decomp(to);
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; n - 1 > i; ++i)
	{
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	for(int i = 1; n >= i; ++i)
		alive[i] = 1;
	Decomp(1);
	cout << ans;
	return 0;
}