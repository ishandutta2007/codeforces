#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 20;

int n, t, a[MAXN], b[MAXN], sec[MAXN];

bool cmp(int u, int v){return b[u] > b[v];}

int main(){
	cin >> n >> t;
	for (int i = 0; i < t; i++)	cin >> a[i] >> b[i];
	ll ans = 0;
	iota(sec, sec + t, 0);
	sort(sec, sec + t, cmp);
	for (int i = 0; i < t; i++){
		int g = min(n, a[sec[i]]);
		n -= g;
		a[sec[i]] -= g;
		ans += 1ll * g * b[sec[i]];
	}
	cout << ans << endl;
	return 0;
}