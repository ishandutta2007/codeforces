#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<deque>

using namespace std;

typedef long long ll;

#define Company pair<pair<ll, ll>, ll>
#define left first.first
#define right first.second
#define cost second

const ll max_n = 300 + 30;
const ll max_m = 1e5 + 20;
const ll INF = 1e18;

ll n, m, k;
Company vec[max_m];
ll mini[max_n][max_n];
ll d[max_n][max_n];
deque<pair<ll, ll>>	saf;

bool cmp(Company a, Company b){
	if (a.right != b.right)
		return	a.right < b.right;
	return	a.left < b.left;
}

int main(){
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	for (ll i = 0; i < m; i++){
		scanf("%I64d%I64d%I64d", &vec[i].left, &vec[i].right, &vec[i].cost);
		vec[i].left--;
	}
	sort(vec, vec + m, cmp);

	for (ll i = 0; i < max_n; i++)
		for (ll j = 0; j < max_n; j++)
			mini[i][j] = INF;

	for (ll i = 0; i < n; i++){
		saf.clear();
		for (ll j = 0; j < m; j++)
			if (vec[j].left <= i){
				while (saf.size() && saf.back().first >= vec[j].cost)	saf.pop_back();
				saf.push_back({vec[j].cost, vec[j].right});
			}

		for (ll j = i; j < n; j++){
			while (saf.size() && j + 1 > saf.front().second)	saf.pop_front();
			ll temp;
			if (saf.empty())	temp = INF;
			else	temp = saf.front().first;
			mini[i][j + 1] = min(mini[i][j + 1], temp);
		}
	}	

	for (ll i = 2; i <= n; i++)
		for (ll j = 0; j + i <= n; j++)
			for (ll w = 1; w < i; w++)
				mini[j][j + i] = min(mini[j][j + i], mini[j][j + w] + mini[j + w][j + i]);

	for (ll i = 1; i <= k; i++)
		for (ll j = 0; j <= n; j++){
			d[i][j] = INF;
			if (j < i)	continue;
			if (j)	d[i][j] = min(d[i][j], d[i][j - 1]);
			d[i][j] = min(d[i][j], mini[0][j]);
			for (ll w = 1; w < j; w++)
				d[i][j] = min(d[i][j], mini[w][j] + d[max(ll(0), i - (j - w))][w - 1]);
			
		}

	ll ans = INF;
	for (ll i =0; i <= n; i++)
		ans = min(ans, d[k][i]);
	if (ans == INF)	ans = -1;
	printf("%I64d\n", ans);
	return 0;
}