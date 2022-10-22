#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;

int n, m, h;
int mm[105], nn[105];
int hh[105][105];
int res[105][105];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> h;
	for(int i = 1; m >= i; ++i)
		cin >> mm[i];
	for(int i = 1; n >= i; ++i)
		cin >> nn[i];
	for(int i = 1; n >= i; ++i)
		for(int j = 1; m >= j; ++j)
			cin >> hh[i][j];
	
	for(int i = 1; n >= i; ++i)
		for(int j = 1; m >= j; ++j)
		{
			if(hh[i][j] == 0)
				res[i][j] = 0;
			else
				res[i][j] = min(nn[i], mm[j]);
		}
	for(int i = 1; n >= i; ++i)
	{
		for(int j = 1; m >= j; ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	
	
	
	
	
	
	
	// fflush(stdout)
	return 0;
}