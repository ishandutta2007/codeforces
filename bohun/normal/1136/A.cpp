#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
int t[105][2];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> t[i][0] >> t[i][1];
	int k;
	cin >> k;
	int res = 0;
	for(int i = 1; n >= i; ++i)
	{
		if(t[i][0] <= k and k <= t[i][1])
		{
			cout << n- res;
			return 0;
		}
		res++;
	}
	return 0;
}