//Call my Name and Save me from the Dark..

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 2e3 + 5;
const ll INF = 1e9;

ll n, k, lc[MAXN], d[2 * MAXN][MAXN], tm, mn[MAXN][MAXN], ss[MAXN][MAXN];
string s[MAXN];

ll lcp(string a, string b){ll ret = 0;	while (ret < min((ll)a.size(), (ll)b.size()) && a[ret] == b[ret])	ret++;	return	ret;}

ll dfs(ll l, ll r){
	ll id = tm++;
	if (r - l <= 1)	return	id;

	ll mid = ss[l][r - 1];
	ll a = dfs(l, mid + 1),	b = dfs(mid + 1, r);

	for (ll i = 0; i <= mid - l + 1; i++)
		for (ll j = 0; j <= r - mid - 1; j++)
			d[id][i + j] = max(d[id][i + j], d[a][i] + d[b][j] + i * j * lc[mid]);
	return	id;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;	for (ll i = 0; i < n; i++)	cin >> s[i];
	sort(s, s + n);
	for (ll i = 0; i < n - 1; i++)
		lc[i] = lcp(s[i], s[i + 1]);

	for (ll i = 0; i < n - 1; i++){
		mn[i][i] = INF;
		for (ll j = i; j < n - 1; j++){
			if (mn[i][j] <= lc[j])	
				ss[i][j + 1] = ss[i][j];
			else
				ss[i][j + 1] = j;
			mn[i][j + 1] = min(mn[i][j], lc[j]);
		}
	}
	dfs(0, n);
	cout << d[0][k] << "\n";
	return	0;
}