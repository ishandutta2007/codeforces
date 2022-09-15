#include <iostream>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int n, q;
int a[200001];
bool s[200001];
int cnt[500001];
vector<int> d[500001];

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(s, 0); ms(cnt, 0);
	cin>>n>>q;
	FOR(i, n) {
		cin>>a[i];
		int temp = a[i];
		for (int j = 2; j * j <= temp; j++) {
			if (temp % j == 0) {
				while (temp % j == 0) temp /= j;
				d[i].push_back(j);
			}
		}
		if (temp > 1)
			d[i].push_back(temp);
	}
	ll ans = 0;
	while (q--){
		int x; cin>>x; x--;
		FOR (i, 1 << d[x].size()) {
			int y = 1, num = 0;
			FOR(j, d[x].size()) if (i & (1 << j)) {y *= d[x][j]; num++;}
			if (s[x]) ans -= (num % 2 == 0 ? 1 : -1) * (--cnt[y]);
			else ans += (num % 2 == 0 ? 1 : -1) * (cnt[y]++);
		}
		s[x] = !s[x];
		cout<<ans<<"\n";
	}
}

int main(){
	solve();
	return 0;
}