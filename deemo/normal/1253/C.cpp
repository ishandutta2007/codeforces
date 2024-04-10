#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, m, a[MAXN];
ll smMod[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	ll sm = 0, ans = 0;
	for (int i = 0; i < n; i++){
		smMod[i%m] += a[i];
		ans += smMod[i%m];
		cout << ans << " ";
	}
	cout << "\n";
	return 0;
}