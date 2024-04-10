#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
const int nax = 50005;
int a, b, c, d;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> a >> b >> c >> d;
	int sum = 2 * a - 2 * d;
	if(sum)
	{
		cout << 0;
		return 0;
	}
	if(c > 0 and a == 0)
	{
		cout << 0;
		return 0;
	}
	cout << 1;
	
			
	
	return 0;
}