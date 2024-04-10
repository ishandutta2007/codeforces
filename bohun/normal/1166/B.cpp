#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int inf = 1e9, nax = 500005;

int n, t[nax];
int a, b, c;
string s;

string A = "aouie";

void rob(int X)
{
	for(int i = 1; X >= i; ++i)
	{
		for(int j = 1; n / X >= j; ++j)
		{
			cout << A[(j - 1 + i - 1) % 5];
		}
	}
	exit(0);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for(int i = 2; i * i <= n; ++i)
	{
		if(n % i == 0 && i >= 5 && n / i >= 5)
			rob(i);
	}
	cout << -1;
	
	
	
	
	
		
		
		
	
    return 0;
}