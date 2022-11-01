#include <bits/stdc++.h>
 
using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const ll mod = int(1e9) + 7, pq = 2, szz = 65536, ma = szz, szz1 = 8;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}
 
ll a, b, c, x, y;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
	ll ans = 0;
    cin >> y >> x;
    a = b = c = x;
   	while (a < y) {
   		swap(b, a);
   		swap(c, b);
   		c = b + a - 1LL;
   		ans++; 
   	}
    cout << ans;
	re 0;
}