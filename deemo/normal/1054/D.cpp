#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, k, a[MAXN], pt[MAXN];
map<int, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i], pt[i+1] = pt[i]^a[i];
	for (int i = 0; i <= n; i++) cnt[pt[i]]++;

	int tt = 1<<k;
	tt--;
	ll ans = 1ll*n*(n+1)/ 2;
	for (auto p:cnt){
		int x = p.F;
		int y = x^tt;
		if (y < x && cnt.count(y)) continue;

		int c1 = p.S;
		int c2 = cnt[y];
		int c = c1+c2;
		c1 = c>>1;
		c2 = c+1>>1;
		ans -= 1ll*c1*(c1-1)/ 2;
		ans -= 1ll*c2*(c2-1)/ 2;
	}
	cout << ans << "\n";
	return 0;
}