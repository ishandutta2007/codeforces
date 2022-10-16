#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) (v).begin(), (v).end()
#define ALL(v) (v).begin(), (v).end()
#define popcorn __builtin_popcount

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 18;

bool a[N][N];
int n;
V<ll> aux[N + 1];
vi stk;
map<vi, ll> mp;
ll conv[1 << N];

void dfs(int lst, int sum) {
	stk.PB(lst);
	sum += lst;
	ll tmp[1 << N];
	memcpy(tmp, conv, sizeof tmp);
	
	for(int i = 0; i < (1 << n); i++)
		conv[i] *= aux[lst][i];
	
	if(sum == n) {
		ll ans = 0;
		for(int i = 0; i < (1 << n); i++)
			if(popcorn(i) % 2 == n % 2)
				ans += conv[i];
			else
				ans -= conv[i];
		mp[stk] += ans;
		stk.pop_back();
		
		memcpy(conv, tmp, sizeof tmp);
		return;	
	}
	for(int i = 1; i <= lst; i++) if(sum + i <= n)
		dfs(i, sum);
	stk.pop_back();
	memcpy(conv, tmp, sizeof tmp);
}

ll dp[1 << N][N];

signed main()
{
	IO_OP;
	stk.reserve(18);
	
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	for(int i = 1; i <= n; i++) aux[i].resize(1 << n);
	for(int i = 0; i < n; i++) dp[1 << i][i] = 1;
	for(int i = 1; i < (1 << n); i++) {	
		for(int j = 0; j < n; j++) if((i >> j & 1) && dp[i][j]) {
			aux[popcorn(i)][i] += dp[i][j];
			for(int k = 0; k < n; k++) if((i >> k & 1) == 0 && a[j][k]) {
				dp[i | (1 << k)][k] += dp[i][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < (1 << n); k++) if(k >> j & 1) {
				aux[i][k] += aux[i][k - (1 << j)];
			}
		}
	}
	for(int i = 0; i < (1 << n); i++) conv[i] = 1;
	for(int i = 1; i <= n; i++)
		dfs(i, 0);

	V<ll> ans(1 << (n - 1));
	for(int i = 0; i < (1 << (n - 1)); i++) {
		vi stk;
		int cur = 1;
		for(int j = 0; j < n - 1; j++)
			if(i >> j & 1)
				cur++;
			else stk.PB(cur), cur = 1;		
		stk.PB(cur);
		sort(ALL(stk), greater<>());
		ans[i] = mp[stk];
	}
	for(int j = 0; j < n - 1; j++)
		for(int i = 0; i < (1 << (n - 1)); i++)
			if(i >> j & 1)
				ans[i - (1 << j)] -= ans[i];	
	for(int i = 0; i < (1 << (n - 1)); i++)
		cout << ans[i] << " ";
}