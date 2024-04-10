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

const int nax = 2e5 + 5, pod = (1 << 17), inf = 1e9 + 5;

int n, k;
int a, b;
int t[nax];
vector <int> v[nax], val;
int w;

bool f(ll x) {
	for(int i = 1; n >= i; ++i) {
		ll up = t[i] + 2 * x;
		int pos = upper_bound(val.begin(), val.end(), up) - val.begin();
		pos--;
		if(pos - i >= k)
		{
			//cout << x <<  " " << pos << " " << i << endl;
			w = t[i] + x;
			return 1;
		}
		ll down = t[i] - 2 * x;
		pos = lower_bound(val.begin(), val.end(), down) - val.begin();
		if(i - pos >= k) {
		//	cout << x << " BB " << i << " " << pos << " " << k << " " << down << endl;
			w = t[i] - x;
			return 1;
		}
	}
	return 0;
}
			

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> k;
		++k;
		val.clear();
		for(int i = 1; n >= i; ++i)
			cin >> t[i], val.pb(t[i]);
		int lewo = 0;
		int prawo = inf;
		while(prawo > lewo) {
			int mid = (lewo + prawo) / 2;
			if(f(mid))
				prawo = mid;
			else
				lewo = mid + 1;
		}
		cout << w << endl;
		
			
		
	}
	
		
			
	
	
	
	
	
		
	
    return 0;
}