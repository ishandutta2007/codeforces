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
 
int main() {	
	boost;
	int T;
	cin >> T;
	while (T--) {
		int a;
		cin >> a;
		int res = 0;
		while (a >= 10) {
			int b = a / 10;
			res += b * 10;
			a -= b * 10;
			a += b;
		}
		res += a;
		cout << res << endl;
	}
			
	
	
	return 0;
}