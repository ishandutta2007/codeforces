#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>
#include<functional>

using namespace std;

typedef long double ld;

const int MAXN = 1e3 + 10;

#define F first.first
#define S first.second
#define ID second

int n, ht, gn;
pair<pair<int, int>, int>	vec[MAXN];
set<pair<int, int>>	st;
vector<pair<int, int>>	ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> ht >> gn;
	int mx = ht;
	for (int i = 0; i < n; i++)	cin >> vec[i].F >> vec[i].S, vec[i].ID = i;
	sort(vec, vec + n, greater<pair<pair<int, int>, int>>());

	int rm = 0, tm = 0, cur = 0;
	for (; ; tm++){
		while (cur < n && vec[cur].F * mx >= 100 * ht){
			st.insert({vec[cur].S, vec[cur].ID});
			cur++;
		}

		if (st.size()){
			auto it = st.end();	it--;
			rm += it->first;
			ans.push_back({tm, it->second + 1});
			st.erase(it);
		}

		ht -= rm;
		ht += gn;
		ht = min(ht, mx);
		if (ht <= 0)	break;
		if (tm > 1e6)	break;
	}
	tm++;

	if (tm > 1e6){
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	cout << tm << " " << ans.size() << "\n";
	for (auto v:ans)
		cout << v.first << " " << v.second << "\n";
	return	0;
}