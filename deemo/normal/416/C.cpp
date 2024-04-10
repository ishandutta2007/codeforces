#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 1e3 + 20;

int n, k, sum;
set<pair<int, int>>	st;
pair<pair<int, int>, int>	vec[MAXN];
vector<pair<int, int>>	ans;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	if (a.first.first != b.first.first)
		return	a.first.first > b.first.first;
	if (a.first.second != b.first.second)
		return	a.first.second < b.first.second;
	return	a.second < b.second;
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b;
		vec[i] = {{b, a}, i};
	}
	sort(vec, vec + n, cmp);
	cin >> k;
	for (int i = 0; i < k; i++){
		int temp;	cin >> temp;
		st.insert({temp, i});
	}

	for (int i = 0; i < n; i++){
		int w = vec[i].first.first, sz = vec[i].first.second;
		set<pair<int, int>>::iterator it = st.upper_bound({sz, -1});
		if (it == st.end())	continue;

		sum += w;
		ans.push_back({vec[i].second + 1, it->second + 1});
		st.erase(it);
	}	
	cout << (int)ans.size() << " " << sum << "\n";
	for (pair<int, int>	temp:ans)
		cout << temp.first << " " << temp.second << "\n";
	return 0;
}