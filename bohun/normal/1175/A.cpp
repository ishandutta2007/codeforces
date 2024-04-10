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

int n;
int a, b;
int t[nax];
vector <int> v[nax];


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	while(n--) {
		ll ile = 0;
		ll x, y;
		cin >> x >> y;
		while(x) {
			if(x % y == 0) {
				++ile;
				x /= y;
			}
			ll r = x % y;
			ile += r;
			x -= r;
		}
		cout << ile << endl;
	}
	
	
	
	
		
	
    return 0;
}