#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 5e4 + 5, pod = (1 << 19), inf = 1e9 + 5;

char s[505][505];
int ile = 0;
int n, m;

bool in(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

int fun(int x, int y) {
	int res = 0;
	res += s[x - 1][y] == '*';
	res += s[x + 1][y] == '*';
	res += s[x][y + 1] == '*';
	res += s[x][y - 1] == '*';
	return res;
}

int tr(int a, int b) {
	int res = 0;
	if(a == 1 || b == 1 || a == n || b == m)
		return -1;
	int x = a - 1;
	int y = b;
	int g = 0;
	while(in(x, y) && s[x][y] == '*')
	{
		x--;
		++g;
	}
	if(!g)
		return -1;
	res += g;
	x = a + 1;
	y = b;
	g = 0;
	while(in(x, y) && s[x][y] == '*')
	{
		x++;
		++g;
	}
	if(!g)
		return -1;
	res += g;
	
	x = a;
	y = b - 1;
	g = 0;
	while(in(x, y) && s[x][y] == '*')
	{
		y--;
		++g;
	}
	if(!g)
		return -1;
	res += g;
	
	x = a;
	y = b + 1;
	g = 0;
	while(in(x, y) && s[x][y] == '*')
	{
		y++;
		++g;
	}
	if(!g)
		return -1;
	res += g;
	return res;
}
	
	

int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i) {
		scanf ("%s", s[i] + 1);
		for(int j = 1; j <= m; ++j)
			ile += (s[i][j] == '*');
	}
	
	for(int i = 1; n >= i; ++i) {
		for(int j = 1; m >= j; ++j) {
			if(s[i][j] == '*' && ile > 1 && tr(i, j) == ile - 1){
				cout << "YES";
				return 0;
			}
			if(i > 1 && i < n && j > 1 && j < m && s[i][j] == '*' && fun(i, j) == 3) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "NO";
				
	
	
	
	
	
	
		
	
		
	
    return 0;
}