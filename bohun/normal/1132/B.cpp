#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n ;
int a[300005];
int q;
ll pref[300005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	
	sort(a + 1, a + n + 1);
	cin >> q;
	for(int i = 1; q >= i; ++i)
	{
		int b;
		cin >> b;
		int z = max(1, n - b + 1);
		cout << pref[n] - a[z] << endl;
	}
		

	return 0;
}