#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
  
using namespace std;						

const int nax = 5e6 + 11;
const int mod = 1e9 + 7;

bool sito[nax];
int p, q;
vector <int> c, d;

bool palin(int x) {
	c.clear();
	while(x) {
		c.pb(x % 10);
		x /= 10;
	}
	d = c;
	reverse(d.begin(), d.end());
	return c == d;
}

int main() {
	sito[1] = 1;
	FOR(i, 2, nax - 1) {
		if(!sito[i]) {
			for(int j = i + i; j < nax; j += i)
				sito[j] = 1;
		}
	}
	scanf("%d %d", &p, &q);
	int i = 1;
	int primes = 0;
	int pal = 0;
	int ans = 1;
	while(i < nax) {
		primes += !sito[i];
		pal += palin(i);
		if((ll) q * primes <= (ll) p * pal)
			ans = i;
		i += 1;
	}
	cout << ans << endl;
	
		
	return 0;
}