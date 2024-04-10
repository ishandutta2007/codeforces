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
		int n = 0;
		int a = 0;
		int s = 0;
		int p = 0;
		int pp = 0;
		cin >> n;
		FOR(i, 1, n) {
			cin >> a;
			s += a;
			if (a % 2) p = 1;
			else pp = 1;
		}
		
		if (s % 2 == 1 || (p && pp))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
			
	
	
	return 0;
}