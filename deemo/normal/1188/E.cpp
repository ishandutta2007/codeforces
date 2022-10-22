#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MOD = 998244353;
const int MAXN = 1e6 + 2e5;
const int MAXK = 1e5 + 10;

int k, c[MAXK];
int ss[MAXN], tt[MAXN];

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

int choose(int a, int b){
	if (a < b) return 0;
	return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

int cc[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ss[0] = 1;
	for (int i = 1; i < MAXN; i++) ss[i] = 1ll*ss[i-1]*i%MOD;
	tt[0] = 1;
	for (int i = 1; i < MAXN; i++) tt[i] = 1ll*tt[i-1]*pw(i, MOD-2)%MOD;

	cin >> k;
	for (int i = 0; i < k; i++) cin >> c[i];
	sort(c, c + k);

	int ans = 0;
	for (int i = 0; i < k; i++){
		if (c[i] < i) break;
		int cur = i+1, rem = 0;
		for (int j = i; j <= c[i]; j++){
			while (cur <= j && rem){
				if (cc[cur]==0)
					cur++;
				else {
					rem--;
					cc[cur]--;
					if (cur + k <= c[i])
						cc[cur+k]++;
				}
			}
			
			if (cur == j+1){
				ans += choose(rem+(k-2), k-2);
				if (ans >= MOD) ans -= MOD;
			}
			rem++;
		}
		if (i <= c[i]) {
			for (int j = 0; j <= c[i]; j++)
				cc[j] = 0;
			for (int j = 0; j < i; j++)
				if (c[j]+2 <= c[i])
					cc[c[j]+2]++;
		}

		c[i] += k-1;
		cc[c[i]+2]++;
	}
	cout << ans << "\n";
	return 0;
}