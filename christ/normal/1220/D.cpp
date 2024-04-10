#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
int main () { 
	int n;
	scanf ("%d",&n);
	vector<vector<ll>> bruh(100);
	for (int i = 1; i <= n; i++) {
		ll a;
		scanf ("%lld",&a); ll oga = a;
		int cnt = 0;
		while (a%2==0) {
			++cnt;
			a/=2;
		}
		bruh[cnt].push_back(oga);
	}
	int wot = -1;
	for (int i = 0; i < 100; ++i) {
		if (wot == -1 || bruh[i].size() > bruh[wot].size()) wot = i;
	}
	printf ("%d\n",n - (int)bruh[wot].size());
	for (int i = 0; i < 100; i++) if (i != wot) {
		for (ll j : bruh[i]) printf ("%lld ",j);
	}
	printf ("\n");
	return 0;
}