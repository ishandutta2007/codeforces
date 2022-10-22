#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);
#define ull unsigned long long
 
using namespace std;
 
const int nax = 2e5 + 111;

int n, a, b, k;
int h;

int res;

multiset <int> secik;
 
int main() {	
	scanf ("%d%d%d%d", &n, &a, &b, &k);
	FOR(i, 1, n) {
		scanf ("%d", &h);
		int c = a + b;
		h %= c;
		if (h == 0) h += c;
		
		if (h - a <= 0) {
			res++;
			continue;
		}
		else {
			h -= a;
			secik.insert((h + a - 1) / a);
		}
	}
	
	while (true) {
		if (ss(secik) == 0) break;
		auto it = secik.begin();
		if (*it <= k) {
			res++;
			k -= *it;
			secik.erase(it);
		}
		else break;
	}
	printf ("%d", res);		
	
	
	return 0;
}