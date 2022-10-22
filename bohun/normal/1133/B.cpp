#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
map < int, int > m;
int t[200005],a[200005];
int pref[200005];
int n, k;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
		m[t[i] % k]++;
	}
	int ans = 0;
	for(int i = 0; k/2 >= i; ++i)
		{
			int A = m[i];
			int B = m[(k - i) % k];
			if(i % k == (k - i) % k)
				{
					ans += (A / 2) * 2;
					m[i] -= (A / 2) * 2;
					continue;
				}
			int C = min(A, B);
			ans += C * 2;

		}
	cout << ans;
	
	return 0;
}