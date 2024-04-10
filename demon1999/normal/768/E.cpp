#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int MAXN = 5 * 100 * 1000,/* ma = 128 * 1024,*/ mod = 1000 * 1000 * 1000 + 7;
int n, s;
vector<ll> dp;
/*
map<ll, int> pq[61]; 
ll get_dp(ll i, ll a) {
	// for (ll ik = i + 1; ik <= 60; ik++)
	// 	if (a & (1LL << ik))
	// 		a ^= (1LL << ik);
	if (i == 0) re 0;
	if (pq[i].find(a) != pq[i].end())
		re pq[i][a];
	vector<ll> pos;
	ll na = a;
	for (ll j = 1; j <= i; j++) {
		if (a & (1LL << j)) continue;
		/*if (na & (1LL << (i - j + 1LL)))
			na ^= (1LL << (i - j + 1LL));*/
		//pos.push_back(get_dp(i - j, (a | (1LL << j))));
		/*if (j <= i - j)
			pos.push_back(get_dp(i - j, (na ^ (1LL << j))));
		else
			pos.push_back(get_dp(i - j, na));
	}
	sort(pos.begin(), pos.end());
	//cout << i << " " << a << " ";
	if (sz(pos) == 0) {
	//	cout << 0 << "\n";
		pq[i][a] = 0;
		re 0;
	}
	if (pos[0] > 0) {
	//	cout << 0 << "\n";
		pq[i][a] = 0;
		re 0;
	}
	forn (i, sz(pos)) {
		if (i + 1 == sz(pos) || (pos[i] + 1LL != pos[i + 1] && pos[i] != pos[i + 1])) {
	//		cout << pos[i] + 1LL << "\n";
			pq[i][a] = pos[i] + 1LL;
			re pos[i] + 1LL;
		}
	}
}*/

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
	//get_dp(5, 0);
	
	// for (int i = 1; i < 40; i++) {
	// 	dp[i] = get_dp(i, 0);
	// 	cout << dp[i] << ", ";
	// }
	dp.push_back(0);
	for (int i = 1; i <= 10; i++)
		forn (j, i + 1)
			dp.push_back(i);
	/*forn (i, 61)
		cout << dp[i] << " ";
	cout << '\n';*/
	cin >> n;
	int ans = 0;
	forn (i, n) {
		int a;
		cin >> a;
		ans ^= dp[a];
	}	
	if (ans)
		cout << "NO\n";
	else
		cout << "YES\n";
}