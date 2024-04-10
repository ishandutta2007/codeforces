#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXK = 5e3 + 10;
const int MOD = 1e9 + 7;

int n, k, ch[MAXK], sv[MAXK], ss[MAXK];
int ch2[MAXK][MAXK], pw2[MAXK];

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a % MOD;
		b >>= 1;
		a = 1ll*a*a % MOD;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ch2[0][0] = 1;
	for (int i = 1; i < MAXK; i++){
		ch2[i][i] = ch2[i][0] = 1;
		for (int j = 1; j < i; j++){
			ch2[i][j] = ch2[i-1][j] + ch2[i-1][j-1];
			if (ch2[i][j] >= MOD)
				ch2[i][j] -= MOD;
		}
	}
	cin >> n >> k;
	for (int i = 0; i <= k; i++)
		pw2[i] = pw(i, k);
	sv[0] = 1;
	for (int i = 1; i < MAXK; i++)
		sv[i] = pw(i, MOD - 2);
	for (int i = 1; i <= k; i++){
		if (i > n)
			ch[i] = 0;
		else {
			ch[i] = 1;
			for (int j = n; j > n-i; j--)
				ch[i] = 1ll*ch[i]*j % MOD;
			for (int j = 2; j <= i; j++)
				ch[i] = 1ll*ch[i]*sv[j] % MOD;
		}
	}
	ll ans = 0;
	for (int j = 1; j <= min(n, k); j++){
		for (int i = j; i; i--){
			int dif = j-i;
			if (!(dif&1)){
				ss[j] += 1ll*ch2[j][i]*pw2[i]%MOD;
				if (ss[j] >= MOD)
					ss[j] -= MOD;
			}
			else{
				ss[j] -=  1ll*ch2[j][i]*pw2[i]%MOD;
				if (ss[j] < 0)
					ss[j] += MOD;
			}
		}
		ans += 1ll*ch[j]*ss[j]%MOD*pw(2, n-j)%MOD;
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << "\n";
	return 0;
}