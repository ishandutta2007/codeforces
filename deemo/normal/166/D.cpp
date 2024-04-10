#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<cassert>

using namespace std;

typedef long long ll;

#define F first
#define S second

const ll MAXN = 1e5 + 10;

ll sum;
ll n, m, cc[MAXN], vec[MAXN], sz;
pair<ll, ll>	sec[MAXN];
map<ll, vector<ll>>	mp;
map<ll, ll>	pc, pos;
set<int>	st;
vector<pair<ll, ll>>	ans;

void deal_with(ll x){
	for (auto u:mp[x]){
		if (sec[u].F < pc[x])	continue;
		if (cc[u] == 1)
			st.erase(u);
		cc[u]--;
		if (cc[u] == 1)
			st.insert(u);
	}
	for (auto u:mp[x - 1]){
		if (sec[u].F < pc[x])	continue;
		if (cc[u] == 1)
			st.erase(u);
		cc[u]--;
		if (cc[u] == 1)
			st.insert(u);
	}
	pc.erase(x);
	pos.erase(x);
}

bool cmp(ll u, ll v){return sec[u].S < sec[v].S;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		ll a, b;	cin >> a >> b;
		pos[b] = i;
		pc[b] = a;
	}
	cin >> m;
	for (ll i = 0; i < m; i++){
		cin >> sec[i].F >> sec[i].S;
		mp[sec[i].S].push_back(i);
		if (pc.count(sec[i].S) && pc[sec[i].S] <= sec[i].F)	cc[i]++;
		if (pc.count(sec[i].S + 1) && pc[sec[i].S + 1] <= sec[i].F)	cc[i]++;
		if (cc[i] == 1)
			st.insert(i);
	}

	while (st.size()){
		auto it = *st.begin();
		st.erase(st.begin());

		ll a = sec[it].F, b = sec[it].S;
		if (pc.count(b) && pc[b] <= a){
			ans.push_back({it, pos[b]});
			sum += pc[b];
			deal_with(b);
		}
		else{
			ans.push_back({it, pos[b + 1]});
			sum += pc[b + 1];
			deal_with(b + 1);
		}
	}

	for (ll i = 0; i < m; i++)
		if (cc[i] == 2)
			vec[sz++] = i;
	
	sort(vec, vec + sz, cmp);
	for (ll i = 0; i < sz; ){
		ll j = i + 1;
		bool fl = 0;
		while (j < sz && sec[vec[j]].S - sec[vec[j - 1]].S <= 1)	fl |= sec[vec[j]].S == sec[vec[j - 1]].S, j++;

		ll mn = 1e9;
		for (ll w = sec[vec[i]].S; w <= sec[vec[j - 1]].S + 1; w++)
			sum += pc[w], mn = min(mn, (ll)pc[w]);

		if (!fl)	sum -= mn;
		bool pic = 0;
		for (ll w = sec[vec[i]].S; w <= sec[vec[j - 1]].S + 1; w++){
			if (!fl && !pic && pc[w] == mn){
				pic = 1;
				continue;
			}

			while (w != sec[vec[i]].S && w - 1 != sec[vec[i]].S)	i++;
			ans.push_back({vec[i], pos[w]});
			i++;
			assert(i <= j);
		}
		i = j;
	}

	cout << sum << "\n";
	cout << ans.size() << "\n";
	for (auto v:ans)
		cout << v.first + 1 << " " << v.second + 1 << "\n";
	return	0;
}