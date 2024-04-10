#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<numeric>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 20;
const ll INF = 1e18 + 2;

ll n, m, x[MAXN], t[MAXN], cn[MAXN], sec[MAXN];
ll weed[4 * MAXN];
multiset<pair<ll, ll>>	st;
bool fl;

void plant(ll v, ll b, ll e){
	if (e - b == 1){
		weed[v] = x[sec[b]] + t[sec[b]];
		return;
	}

	ll mid = (b + e)/ 2;
	plant(v<<1, b, mid);
	plant(v<<1^1, mid, e);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

void get(ll v, ll b, ll e, ll pos, ll sz){
	if (e - b == 1){
		if (x[sec[b]] > pos || x[sec[b]] + t[sec[b]] < pos){
			fl = 1;
			return;
		}
		weed[v] += sz;
		t[sec[b]] += sz;
		cn[sec[b]]++;

		bool flag = 1;
		while (flag){
			flag = 0;
			auto it = st.upper_bound({weed[v], INF});
			if (it != st.begin()){
				it--;
				if (it->first >= x[sec[b]]){
					flag = 1;
					cn[sec[b]]++;
					weed[v] += it->second;
					t[sec[b]] += it->second;
					st.erase(it);
				}
			}
		}
		return;
	}	

	ll mid = (b + e)/ 2;
	if (weed[v<<1] >= pos)	
		get(v<<1, b, mid, pos, sz);
	else
		get(v<<1^1, mid, e, pos, sz);
	weed[v] = max(weed[v<<1], weed[v<<1^1]);
}

bool cmp(ll a, ll b){return	x[a] < x[b];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++)	cin >> x[i] >> t[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	plant(1, 0, n);
	while (m--){
		ll pos, sz;	cin >> pos >> sz;
		fl = 0;
		get(1, 0, n, pos, sz);
		if (fl)
			st.insert({pos, sz});
	}
	for (ll i = 0; i < n; i++)
		cout << cn[i] << " " << t[i] << "\n";
	return	0;
}