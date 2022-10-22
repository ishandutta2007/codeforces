#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 5e5 + 20;
const int LOG = 21;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll n, m, h, w, ans;
string s;
ll lleft[MAXN], rright[MAXN], down[MAXN], up[MAXN];
ll pl[MAXN], pr[MAXN], pd[MAXN], pu[MAXN];

void move(ll &x, ll &y, char ch){
	if (ch == 'L')	y--;
	if (ch == 'R')	y++;
	if (ch == 'U')	x--;
	if (ch == 'D')	x++;
}

void init(){
	fill(up, up + MAXN, INF);
	fill(down, down + MAXN, INF);
	fill(lleft, lleft + MAXN, INF);
	fill(rright, rright + MAXN, INF);

	up[0] = down[0] = rright[0] = lleft[0] = 0;
	ll ml = 0, mr = 0, md = 0, mu = 0;
	ll x = 0, y = 0;
	for (ll i = 0; i < n; i++){
		move(x, y, s[i]);
		if (lleft[max((ll)0, -y)] == INF)	lleft[max((ll)0, -y)] = i + 1;
		if (rright[max((ll)0, y)] == INF)	rright[max((ll)0, y)] = i + 1;
		if (up[max((ll)0, -x)] == INF)	up[max((ll)0, -x)] = i + 1;
		if (down[max((ll)0, x)] == INF)	down[max((ll)0, x)] = i + 1;

		ml = max(ml, -y);
		mr = max(mr, y);
		mu = max(mu, -x);
		md = max(md, x);
	}	

	for (ll i = 1; i < MAXN; i++){
		if (lleft[i] == INF && y < 0){
			ll z = (i - ml)/ (-y) + bool((i - ml) % (-y) != 0);
			lleft[i] = z * n + lleft[i - z * (-y)];
		}
		if (lleft[i] != INF)
			pl[i] = pl[i - 1] + lleft[i];
	}
	for (ll i = 1; i < MAXN; i++){
		if (rright[i] == INF && y > 0){
			ll z = (i - mr)/ (y) + bool((i - mr) % (y) != 0);
			rright[i] = z * n + rright[i - z * (y)];
		}
		if (rright[i] != INF)
			pr[i] = pr[i - 1] + rright[i];
	}

	for (ll i = 1; i < MAXN; i++){
		if (up[i] == INF && x < 0){
			ll z = (i - mu)/ (-x) + bool((i - mu) % (-x) != 0);
			up[i] = z * n + up[i - z * (-x)];
		}
		if (up[i] != INF)
			pu[i] = pu[i - 1] + up[i];
	}
	for (ll i = 1; i < MAXN; i++){
		if (down[i] == INF && x > 0){
			ll z = (i - md)/ (x) + bool((i - md) % (x) != 0);
			down[i] = z * n + down[i - z * (x)];
		}
		if (down[i] != INF)
			pd[i] = pd[i - 1] + down[i];
	}
}

bool f(ll x){
	ll p1 = 0;
	for (ll i = LOG - 1; i >= 0; i--){
		if (p1 + (1 << i) > m)	continue;
		ll z = p1 + (1 << i);
		z--;
		
		if (up[x + 1] > lleft[z + 1] && down[n - x] > lleft[z + 1] && lleft[z + 1] < rright[m - z])
			p1 = z + 1;
	}

	ll p2 = m;
	for (ll i = LOG - 1; i >= 0; i--){
		if (p2 - (1 << i) < 0)	continue;
		ll z = p2 - (1 << i);

		if (up[x + 1] > rright[m - z] && down[n - x] > rright[m - z] && lleft[z + 1] > rright[m - z])
			p2 = z;
	}

	ans = (ans + pl[p1]) % MOD;
	ans = (ans + pr[m - p2]) % MOD;

	if (p1 + (m - p2) != m && up[x + 1] == INF && down[n - x] == INF)	return	true;
	ans = (ans + (m - (p1 + (m - p2))) * min(up[x + 1], down[n - x])) % MOD;
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> h >> w;
	cin >> s;
	init();
	n = h, m = w;

	for (ll i = 0; i < n; i++)
		if (f(i)){
			cout << -1 << endl;
			return 0;
		}
	cout << ans << endl;
	return 0;
}