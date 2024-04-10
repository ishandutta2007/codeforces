#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 5e3 + 10;
const ll INF = 2e18 + 3;

ll n, x;
ll d[3][2 * MAXN], sec[2 * MAXN], pos[2 * MAXN];
pair<ll, ll>	vec[MAXN];

ll get(ll ind){
	if (ind == 0)	
		return	x;
	ind--;
	if (ind & 1)
		return	vec[ind/2].second;
	return	vec[ind/2].first;
}

bool cmp(ll u, ll v){return	get(u) < get(v);}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	for (ll i = 0; i < n; i++)	
		cin >> vec[i].first >> vec[i].second;
	iota(sec, sec + 2 * n + 1, 0);
	sort(sec, sec + 2 * n + 1, cmp);
	for (int i = 0; i <= 2 * n; i++)	pos[i] = get(sec[i]);

	bool a = 0, b = 1;
	for (ll i = n - 1; i >= 0; i--){
		ll mini = INF;
		ll prv = pos[0];
		for (ll j = 0; j <= 2 * n; j++){
			mini += pos[j] - prv;
			if (pos[j] <= vec[i].second)
				mini = min(mini, d[b][sec[j]] + max(0LL, vec[i].first - pos[j]));
			else
				mini = min(mini, d[b][sec[j]] + max(0LL, pos[j] - vec[i].second));
			d[a][sec[j]] = mini;
			prv = pos[j];
		}

		mini = INF;
		for (ll j = 2 * n; j >= 0; j--){
			mini += prv - pos[j];
			if (pos[j] <= vec[i].second)
				mini = min(mini, d[b][sec[j]] + max(0LL, vec[i].first - pos[j]));
			else
				mini = min(mini, d[b][sec[j]] + max(0LL, pos[j] - vec[i].second));
			d[a][sec[j]] = min(d[a][sec[j]], mini);
			prv = pos[j];
		}
		a = !a;
		b = !b;
	}

	cout << d[b][0] << endl;
	return	0;
}