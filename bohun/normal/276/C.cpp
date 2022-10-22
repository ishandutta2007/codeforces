#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 200005, mod = 1e9 + 7;
const int inf = 1e9;

int d[nax], t[nax];
int n, l, r, q;
vector <int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i];
	}
	sort(t + 1, t + n + 1);
	for(int i = 1; q >= i; ++i)
	{
		cin >> l >> r;
		d[l]++;
		d[r + 1]--;
	}
	for(int i = 1; n >= i; ++i)
		d[i] += d[i - 1], v.pb(d[i]);
	sort(v.begin(), v.end());
	ll sum = 0;
	for(int i = n; i >= 1; --i)
	{
		sum += (ll) t[i] * v[i - 1];
	}
	
	cout << sum;
	
	
	
	
	return 0;
}