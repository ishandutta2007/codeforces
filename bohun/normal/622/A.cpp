#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;

int main()
{
	ll n;
	int ile = 1;
	cin >> n;
	while(n > ile)
	{
		ile++;
		n -= ile - 1;
	}
	cout << n;
		
	return 0;
}