#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e5 + 50;
const ll MOD = 1e9 + 9;

ll n;
pair<ll, ll>	vec[MAXN];
map<pair<ll, ll>, bool>	mp;
map<pair<ll, ll>, ll>	ps, cnt;
vector<ll>	ans;
set<ll>	st;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++){
		cin >> vec[i].first >> vec[i].second;
		mp[vec[i]] = 1;
		ps[vec[i]] = i;
	}
	for (ll i = 0; i < n; i++){
		if (vec[i].second == 0)	continue;
		ll c = 0;
		if (mp.count({vec[i].first - 1, vec[i].second - 1}))	c++;
		if (mp.count({vec[i].first, vec[i].second - 1}))	c++;
		if (mp.count({vec[i].first + 1, vec[i].second - 1}))	c++;
		cnt[vec[i]] = c;
	}
	for (ll i = 0; i < n; i++){
		bool fl = 1;
		if (mp.count({vec[i].first - 1, vec[i].second + 1}))
			if (cnt[{vec[i].first - 1, vec[i].second + 1}] == 1)	fl = 0;
		if (mp.count({vec[i].first, vec[i].second + 1}))
			if (cnt[{vec[i].first, vec[i].second + 1}] == 1)	fl = 0;
		if (mp.count({vec[i].first + 1, vec[i].second + 1}))
			if (cnt[{vec[i].first + 1, vec[i].second + 1}] == 1)	fl = 0;

		if (fl)
			st.insert(i);
	}
	
	vector<pair<ll, ll>>	sec;
	for (ll i = 0; st.size(); i++){
		sec.clear();
		if (i % 2 == 0){
			set<ll>::iterator it = st.end();
			it--;
			ll z = *it;
			ans.push_back(z);
			st.erase(it);
			mp.erase(vec[z]);

			if (mp.count({vec[z].first - 1, vec[z].second + 1}))
				cnt[{vec[z].first - 1, vec[z].second + 1}]--;
			if (mp.count({vec[z].first, vec[z].second + 1}))
				cnt[{vec[z].first, vec[z].second + 1}]--;
			if (mp.count({vec[z].first + 1, vec[z].second + 1}))
				cnt[{vec[z].first + 1, vec[z].second + 1}]--;
			
			if (mp.count({vec[z].first - 1, vec[z].second - 1}))	
				sec.push_back({vec[z].first - 1, vec[z].second - 1});

			if (mp.count({vec[z].first, vec[z].second - 1}))	
				sec.push_back({vec[z].first, vec[z].second - 1});

			if (mp.count({vec[z].first + 1, vec[z].second - 1}))	
				sec.push_back({vec[z].first + 1, vec[z].second - 1});

			if (mp.count({vec[z].first - 1, vec[z].second}))
				sec.push_back({vec[z].first - 1, vec[z].second});
			if (mp.count({vec[z].first + 1, vec[z].second}))
				sec.push_back({vec[z].first + 1, vec[z].second});

			if (mp.count({vec[z].first - 2, vec[z].second}))
				sec.push_back({vec[z].first - 2, vec[z].second});
			if (mp.count({vec[z].first + 2, vec[z].second}))
				sec.push_back({vec[z].first + 2, vec[z].second});
		}
		else{
			set<ll>::iterator it = st.begin();
			ll z = *it;
			ans.push_back(z);
			st.erase(it);
			mp.erase(vec[z]);
			if (mp.count({vec[z].first - 1, vec[z].second + 1}))
				cnt[{vec[z].first - 1, vec[z].second + 1}]--;
			if (mp.count({vec[z].first, vec[z].second + 1}))
				cnt[{vec[z].first, vec[z].second + 1}]--;
			if (mp.count({vec[z].first + 1, vec[z].second + 1}))
				cnt[{vec[z].first + 1, vec[z].second + 1}]--;

			if (mp.count({vec[z].first - 1, vec[z].second - 1}))	
				sec.push_back({vec[z].first - 1, vec[z].second - 1});

			if (mp.count({vec[z].first, vec[z].second - 1}))	
				sec.push_back({vec[z].first, vec[z].second - 1});

			if (mp.count({vec[z].first + 1, vec[z].second - 1}))	
				sec.push_back({vec[z].first + 1, vec[z].second - 1});
			if (mp.count({vec[z].first - 1, vec[z].second}))
				sec.push_back({vec[z].first - 1, vec[z].second});
			if (mp.count({vec[z].first + 1, vec[z].second}))
				sec.push_back({vec[z].first + 1, vec[z].second});
			if (mp.count({vec[z].first - 2, vec[z].second}))
				sec.push_back({vec[z].first - 2, vec[z].second});
			if (mp.count({vec[z].first + 2, vec[z].second}))
				sec.push_back({vec[z].first + 2, vec[z].second});//This is not how I usually code!
		}

		for (pair<ll, ll>	temp:sec){
			bool fl = 1;
			if (mp.count({temp.first - 1, temp.second + 1}))
				if (cnt[{temp.first - 1, temp.second + 1}] == 1)	fl = 0;
			if (mp.count({temp.first, temp.second + 1}))
				if (cnt[{temp.first, temp.second + 1}] == 1)	fl = 0;
			if (mp.count({temp.first + 1, temp.second + 1}))
				if (cnt[{temp.first + 1, temp.second + 1}] == 1)	fl = 0;
			if (fl)
				st.insert(ps[temp]);
			else
				st.erase(ps[temp]);
		}
	}
	ll ret = 0, tt = 1;
	reverse(ans.begin(), ans.end());
	for (ll u:ans){
		ret = (ret + tt * u) % MOD;
		tt = (tt * n) % MOD;
	}
	cout << ret << endl;
	return 0;	
}