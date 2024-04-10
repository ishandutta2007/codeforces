#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

typedef long long ll;

const ll MAXN = 300 + 20;
const ll MAX = 1e5 + 20;
const ll MOD = 1e9 + 7;

ll n, m, tot;
ll vec[MAXN];
vector<ll>	adj[MAXN];
short mark[MAXN];
vector<ll>	st;
bool fail;
ll gec[MAXN], ans[MAX], sz;
vector<ll>	sec;

void dfs(ll v){
	if (mark[v] == 1)	fail = 1;
	if (mark[v])	return;
	mark[v] = 1;

	for (ll u:adj[v])
		dfs(u);

	mark[v] = 2;
	st.push_back(v);
}

void get(ll v){
	mark[v] = 1;
	for (ll u:adj[v])
		get(u);
	sec.push_back(v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> tot;
	for (ll i = 0; i < n; i++)	cin >> vec[i];
	while (m--){
		ll a, b;	cin >> a >> b;	a--, b--;
		adj[b].push_back(a);
	}
	for (ll i = 0; i < n; i++)
		if (mark[i] == 0)	dfs(i);
	if (fail){
		cout << 0 << endl;
		return 0;
	}		

	memset(mark, 0, sizeof(mark));
	reverse(st.begin(), st.end());
	for (ll v:st)
		if (mark[v] == 0){
			get(v);

			ll sum = 0, temp = 0;
			for (ll i = 0; i < sec.size(); i++){
				temp += sum;
				sum += vec[sec[i]];
				gec[sz++] = sum;
			}
			tot -= temp;

			sec.clear();
		}
	if (tot < 0){
		cout << 0 << endl;
		return 0;
	}

	ans[0] = 1;
	for (ll i = 0; i < sz; i++)
		for (ll j = 0; j < MAX; j++)
			if (j >= gec[i])
				ans[j] = (ans[j] + ans[j - gec[i]]) % MOD;
	cout << ans[tot] << endl;
	return 0;
}