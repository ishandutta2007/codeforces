#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 2e3 + 20;

int n, m, a[MAXN], b[MAXN];
ll s1, s2;
set<pair<ll, pair<int, int>>>	st2;
vector<pair<int, int>>	ans;

int main(){
	cin >> n;	for (int i = 0; i < n; i++)	cin >> a[i], s1 += a[i];
	cin >> m;	for (int i = 0; i < m; i++)	cin >> b[i], s2 += b[i];
	ll mini = abs(s1 - s2);

	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
			st2.insert({b[i] + b[j], {i, j}});

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ll ts1 = s1, ts2 = s2;
			ts1 -= a[i];	ts2 -= b[j];
			ts1 += b[j];	ts2 += a[i];

			if (abs(ts1 - ts2) < mini){
				mini = abs(ts1 - ts2);
				ans.clear();
				ans.push_back({i, j});
			}
		}
		
		for (int j = i + 1; j < n; j++){
			ll ts1 = s1, ts2 = s2;
			
			ll z = abs(s1 - s2);
			z /= 2;

			auto it = st2.begin();
			if (s1 < s2)
				it = st2.upper_bound({a[i] + a[j] + z, {-1, -1}});
			else
				it = st2.upper_bound({a[i] + a[j] - z, {-1, -1}});
			auto it2 = it;

			if (it != st2.end()){
				ll temp = abs((ts1 - a[i] - a[j] + it->first) - (ts2 + a[i] + a[j] - it->first));
				if (temp < mini){
					mini = temp;
					ans.clear();
					ans.push_back({i, it->second.first});
					ans.push_back({j, it->second.second});
				}
			}

			if (it != st2.begin()){
				it--;
				ll temp;
				if ((temp = abs((ts1 - a[i] - a[j] + it->first) - (ts2 + a[i] + a[j] - it->first))) < mini){
					mini = temp;
					ans.clear();
					ans.push_back({i, it->second.first});
					ans.push_back({j, it->second.second});
				}
			}
		}
	}
	
	cout << mini << endl;
	cout << ans.size() << endl;
	for (pair<int, int>	v:ans)
		cout << v.first + 1 << " " << v.second + 1 << endl;
	return	0;
}