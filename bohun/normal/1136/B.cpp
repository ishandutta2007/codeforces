#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n, k;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int malo = min(k - 1, n - k);
	int duzo = max(k - 1, n - k);
	cout << n + n + 1 + 2 * malo + duzo;
	return 0;
}