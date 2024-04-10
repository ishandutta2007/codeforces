// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 2e5 + 11;
const int mod = 1e9 + 7;

int n;
int a[nax];
ll ans = 0;
int b[nax];

int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", a + i), b[a[i]] = i;
	for(int i = 1; i < n; ++i) {
		ans += abs(b[i + 1] - b[i]);
	}
	printf("%lld", ans);
			
	
	
	
	
	return 0;
}