#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;
const int MOD = 1e9 + 7;

int n, x[MAXN], ss[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> x[i];
	sort(x, x + n);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++)
		ss[i] = (ss[i-1]<<1) % MOD;

	ll ans = 0, sm = 0, temp = 0;
	for (int i = 0; i + 1 < n; i++) sm += x[i+1] - x[i];
	sm %= MOD;
	temp = sm;
	for (int i = 0; i <= n-2; i++){
		ans = (ans + 1ll*ss[i]*sm) % MOD;
		
		temp -= (x[i+1] - x[i]);
		temp = (temp + MOD) % MOD;
		sm += temp;
		sm -= (x[n-1] - x[n-2-i]);
		sm = (sm + MOD) % MOD;
	}
	cout << ans << endl;
	return 0;
}