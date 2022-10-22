#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, a[MAXN], p[MAXN], par[MAXN];
ll sm[MAXN], ans[MAXN];
bool del[MAXN];

int get_par(int v){return par[v] == v?v:par[v]=get_par(par[v]);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	int sz = 1;
	fill(del, del + n, 1);
	iota(par, par + n, 0);
	ll x = 0;
	for (int i = n - 1; i; i--){
		int v = p[i];
		sm[v] = a[v];
		del[v] = 0;

		if (v && !del[v - 1]){
			int pp = get_par(v - 1);
			par[pp] = v;
			sm[v] += sm[pp];
		}

		if (v + 1 < n && !del[v + 1]){
			int pp = get_par(v + 1);
			par[pp] = v;
			sm[v] += sm[pp];
		}

		x = max(x, sm[v]);
		ans[sz++] = x;
	}

	for (int i = n - 1; ~i; i--)
		cout << ans[i] << "\n";
	return 0;
}