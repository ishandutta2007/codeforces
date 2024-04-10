#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define tm asdflj

const ll MAXN = 1e5 + 10;
const ll MAXK = 100 + 4;
const ll INF = 1e9;

ll n, m, k, p[MAXN], tm[MAXN], q[MAXN], best[MAXN];
ll d[MAXK][MAXN], pt[MAXN], bs[MAXN], sl[MAXN];

ll meet(ll a, ll b){
	return ((bs[b] - bs[a]) + (sl[a] - sl[b] - 1))/ (sl[a] - sl[b]);
}

bool cmp(ll val, ll v){return val < best[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 1; i < n; i++)	cin >> p[i], p[i] += p[i - 1];
	for (ll i = 0; i < m; i++){
		ll a, b;	cin >> a >> b, a--;
		tm[i] = b - p[a];
	}
	sort(tm, tm + m);
	for (ll i = 0; i < m; i++)
		pt[i + 1] = pt[i] + tm[i];

	memset(d, 63, sizeof(d));
	d[0][0] = 0;
	for (ll w = 1; w <= k; w++){
		ll h = 0, t = 0;
		for (ll i = 0; i <= m; i++){
			bs[i] = d[w - 1][i] + pt[i], sl[i] = -i;
			while (t-h>1 && meet(q[t - 2], i) <= meet(q[t - 2], q[t - 1])) t--;
			if (t - h)
				best[i] = meet(q[t - 1], i);
			else
				best[i] = -INF;
			q[t++] = i;
			
			if (!i)
				d[w][i] = 0;
			else{
				ll pos = upper_bound(q, q + t, tm[i - 1], cmp) - q - 1;
				d[w][i] = bs[q[pos]] + 1ll * sl[q[pos]] * tm[i - 1] - pt[i] + 1ll * i * tm[i - 1];
			}
		}
	}
	cout << d[k][m] << "\n";
	return 0;
}