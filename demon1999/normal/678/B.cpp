#include <bits/stdc++.h> 

using namespace std; 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
#define gi get_int()
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll cnn = 800, md = 1000000007, sz_g = 200000, pq = 100000000, inf = 1000000000LL,
 mod2 = 5000000, ma = 128 * 1024, ma1 = 8;

void my_assert() {
	while(true);
}
ll get_int() {
	int n;
	scanf("%d", &n);
	re n;
}

ll n, kk = 0, p = 0;

ll fc(int n) {
	if (n % 400 == 0 || (n % 4 == 0 && n % 100)) re 1;
	re 0;
}
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("sum.in", "r", stdin);
    //freopen("unitopsort.out", "w", stdout);
   	cin >> n;
   	if (n % 400 == 0 || (n % 4 == 0 && n % 100)) {
   		kk = 1;
   	}
   	for (int j = n; ; j++) {
   		p += 365;
   		if (fc(j) == 1)
   			p++;
   		p %= 7;
   		if (p == 0 && ((kk == 0 && fc(j + 1) == 0) || (kk && fc(j + 1)))) {
   			cout << j+ 1;
   			re 0;
   		}
   	}
    return 0;
}