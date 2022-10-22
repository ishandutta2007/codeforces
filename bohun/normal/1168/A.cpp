#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 300005, mod = 1e9 + 7, pod = (1 << 20);

int n, a, b, c, m;
vector <int> v[nax];
int t[nax];

bool f(int x) {
	int last = -1;
	for(int i = 1; n >= i; ++i)
	{
		int xx = t[i];
		int y = (t[i] + x) % m;
		if(t[i] + x >= m)
		{
			y = t[i] + x - m;
			if(y >= last || last >= t[i])
			{
				y = last;
				continue;
			}
			last = t[i];
		}
		int a = min(xx, y);
		int b = max(xx, y);
		if(last > a && last > b)
			return 0;
		last = max(last, min(a, b));
	}
	return 1;
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
	}
	int l = 0;
	int r = 1e9 + 5;
	while(r > l) {
		int mid = (l + r) / 2;
		if(f(mid))
			r = mid;
		else
			l = mid + 1;
	}
	assert(f(l));
	if(l > 0)
		assert(!f(l - 1));
	cout << l;
	
	
	
		
	
    return 0;
}