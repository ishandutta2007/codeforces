#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MAXN = 1e5 + 10;

ll ax, ay, bx, by, cx, cy, n;
ll x[MAXN], y[MAXN];
ld ss[MAXN], gg[MAXN], ff[MAXN], sm;

ld dis(ll a, ll b, ll c, ll d){return sqrt((a - c) * (a - c) + (b - d) * (b - d));}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> x[i] >> y[i], ss[i] = dis(x[i], y[i], cx, cy)
			,gg[i] = ss[i] + dis(x[i], y[i], ax, ay)
			,ff[i] = ss[i] + dis(x[i], y[i], bx, by)
			,ss[i] *= 2.0, sm += ss[i];
	
	ld ans = 1e18;
	{
		pair<ld, ll>	mx(1e18, -1);
		for (ll i = 0; i < n; i++)
			mx = min(mx, {ff[i] - ss[i], i});
		ld temp = sm + mx.first;
		ans = min(ans, temp);

		ll ind = mx.second;
		ld mini = 0;
		for (ll i = 0; i < n; i++)
			if (i != ind)	mini = min(mini, gg[i] - ss[i]);
		ans = min(ans, mini + temp);
	}
	for (ll i = 0; i < n; i++)	swap(ff[i], gg[i]);

	{
		pair<ld, ll>	mx(1e18, -1);
		for (ll i = 0; i < n; i++)
			mx = min(mx, {ff[i] - ss[i], i});
		ld temp = sm + mx.first;
		ans = min(ans, temp);

		ll ind = mx.second;
		ld mini = 0;
		for (ll i = 0; i < n; i++)
			if (i != ind)	mini = min(mini, gg[i] - ss[i]);
		ans = min(ans, mini + temp);
	}


	cout << fixed << setprecision(12);
	cout << ans << "\n";
	return 0;
}