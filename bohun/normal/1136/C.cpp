#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n, k, m;
int t[505][505], d[505][505];
vector < int > a[10005], b[10005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; n >= i; ++i)
	for(int j = 1; m >= j; ++j)
		cin >> t[i][j], a[i + j].pb(t[i][j]);
	for(int i = 1; n >=i; ++i)
	for(int j = 1; m >= j; ++j)
		cin >> d[i][j], b[i + j].pb(d[i][j]);
	for(int i = 2;n + m >= i; ++i)
	{
		sort(a[i].begin(),a[i].end());
		sort(b[i].begin(),b[i].end());
		if(a[i] != b[i])
			{
				cout << "NO";
				return 0;
			}
	}
	cout << "YES";
	return 0;
}