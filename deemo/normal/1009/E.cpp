#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;
const int MOD = 998244353;

int n, a[MAXN], sv[MAXN], d[MAXN];

void fix(int &x){
	if (x >= MOD) x -= MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sv[0] = 1;
	for (int i = 1; i < MAXN; i++){
		sv[i] = sv[i-1]<<1;
		fix(sv[i]);
	}
	int temp = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		if (i > 1)
			temp = (temp + 1ll*sv[n-i]*a[i-2])%MOD;

		ans += temp;
		fix(ans);
		ans = (ans + 1ll*sv[n-i]*a[i-1])%MOD;
	}
	cout << ans << "\n";
	return 0;
}