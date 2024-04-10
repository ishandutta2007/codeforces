#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
int n, d, h;
vector <pair <int, int>> ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d >> h;
	if(2 * h < d || (d == 1 && n > 2))
	{
		cout << -1;
		return 0;
	}
	int j = 2;
	for(int i = 1; h >= i; ++i)
	{
		ans.pb({j - 1, j});
		++j;
	}
	if(d != h)
	{
		ans.pb({1, j});
		++j;
	}
	int node = 1;
	if(d == h)
		node = 2;
	for(int i = 1; d - h - 1 >= i; ++i)
	{
		ans.pb({j - 1, j});
		++j;
	}
	for(int i = d + 2; n >= i; ++i)
	{
		ans.pb({i, node});
	}
	for(auto it: ans)
		cout << it.fi << " " << it.se << endl;
	
		
		
	return 0;
}