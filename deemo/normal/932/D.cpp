#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 5e5 + 10;
const ll LOG = 20;
const ll INF = 1e17;

ll n = 1, w[MAXN], par[MAXN][LOG], sm[MAXN][LOG];

ll getFirstPar(ll v, ll p){
	if (w[p] >= w[v])
		return p;

	for (ll ww = LOG-1; ~ww; ww--)
		if (~par[p][ww] && w[v] > w[par[p][ww]])
			p = par[p][ww];
	return par[p][0];
}

ll getAns(ll v, ll lim){
	if (w[v] > lim)
		return 0;
	ll ans = 1;
	lim -= w[v];
	for (ll w = LOG - 1; ~w; w--)
		if (~par[v][w] && lim >= sm[v][w])
			lim -= sm[v][w], v = par[v][w], ans += 1<<w;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof(par));
	ll q;	cin >> q;
	ll last = 0;
	while (q--){
		ll t; cin >> t;
		if (t == 1){
			ll R, W; cin >> R >> W;
			R ^= last;
			W ^= last;
			w[n] = W;
			par[n][0] = getFirstPar(n, R-1);
			if (~par[n][0])
				sm[n][0] = w[par[n][0]];
			for (ll w = 1; w < LOG; w++)
				if (~par[n][w-1])
					par[n][w] = par[par[n][w-1]][w-1], sm[n][w] = min(INF, sm[n][w-1] + sm[par[n][w-1]][w-1]);
				else
					par[n][w] = par[n][w-1], sm[n][w] = sm[n-1][w];
			n++;
		}
		else{
			ll R, X; cin >> R >> X;
			R ^= last;
			X ^= last;
			cout << (last = getAns(R-1, X)) << "\n";
		}
	}
	return 0;
}