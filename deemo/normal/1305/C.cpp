#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second


int m;
int pw(int a, ll b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%m;
		b >>= 1;
		a = 1ll*a*a%m;
	}
	return ret;
}

const int MAXN = 2e5 + 10;
const int MAXM = 1e3 + 10;

int n, a[MAXN];
ll cnt[MAXM];
ll cAns[MAXM];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		int temp = a[i]%m;
		for (int j = 0; j < m; j++)
			cAns[temp>=j? temp-j: temp-j+m] += cnt[j];

		cnt[temp]++;
	}

	int ans = 1;
	for (int i = 0; i < m && ans; i++)
		ans = 1ll*ans*pw(i, cAns[i]) % m;
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}