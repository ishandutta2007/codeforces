#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

#define Person	pair<ll, pair<ll, ll>>
#define tm	first
#define S	second.first
#define F	second.second

const ll MAXN = 1e5 + 200;

ll n, m;
Person	vec[MAXN], sec[MAXN];
vector<ll>	pos[MAXN];
vector<ll>	w[MAXN];
set<ll>	st;
ll wws[MAXN];
ll fen[3][MAXN];

ll get(ll v, ll tp){
	ll ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[tp][v];
	return	ret;
}

void add(ll v, ll val, ll tp){
	for (v++; v < MAXN; v += v & (-v))
		fen[tp][v] += val;
}

bool cmp(Person a, Person b){
	if (a.tm != b.tm)
		return	a.tm < b.tm;
	if (a.S != b.S)
		return	a.S < b.S;
	return	a.F < b.F;
}		

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++)
		cin >> vec[i].tm >> vec[i].S >> vec[i].F;
	copy(vec, vec + n, sec);
	sort(vec, vec + n, cmp);

	ll cur = 1, t = 1;
	vec[n].tm = 1e15 + 5;
	for (ll b = 0; b < n || st.size();){
		while (b < n && t == vec[b].tm){
			w[vec[b].S].push_back(vec[b].F);
			st.insert(vec[b].S);
			add(vec[b++].S, 1, 0);//started waiting
		}

		pos[cur].push_back(t);
		add(cur, -wws[cur], 1);//getting out
		wws[cur] = 0;
		st.erase(cur);

		for (ll u:w[cur]){//getting in
			add(u, 1, 1);
			wws[u]++;
			st.insert(u);
		}
		add(cur, -(ll)w[cur].size(), 0);
		w[cur].clear();
		
		ll x = get(cur, 0) + get(cur, 1), y = get(MAXN - 1, 0) - get(cur, 0) + get(MAXN - 1, 1)
			- get(cur, 1);

		if (y == x && y == 0){
			t = vec[b].tm;
			continue;
		}
		if (b == n && st.empty())	continue;

		if (y >= x){
			set<ll>::iterator it = st.lower_bound(cur);
			ll temp = *it;
			ll mv = min(temp - cur, vec[b].tm - t);
			cur += mv;
			t += mv;
		}
		else{
			set<ll>::iterator it = st.lower_bound(cur);
			it--;
			ll temp = *it;
			ll mv = min(cur - temp, vec[b].tm - t);
			cur -= mv;
			t += mv;
		}
	}	

	for (ll i = 0; i < n; i++){
		ll s = sec[i].S, f = sec[i].F, tt = sec[i].tm;
		ll temp = *(lower_bound(pos[s].begin(), pos[s].end(), tt));
		cout << *(lower_bound(pos[f].begin(), pos[f].end(), temp)) << "\n";
	}		
	return 0;
}