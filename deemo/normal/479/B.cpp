#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 100 + 3;

int n, k;
pair<int, int>	vec[MAXN];
vector<pair<int, int>>	ans;

int main(){
	cin >> n >> k;
	int mini = 1e9, maxi = -1;
	for (int i = 0; i < n; i++){
		cin >> vec[i].first;
		vec[i].second = i;
		maxi = max(maxi, vec[i].first);
		mini = min(mini, vec[i].first);
	}
	int ret = maxi - mini;

	for (int i = 0; i < k; i++){
		sort(vec, vec + n);
		if (vec[0].first == vec[n - 1].first)	break;
		ans.push_back({vec[n - 1].second, vec[0].second});
		vec[0].first++;
		vec[n-1].first--;
		sort(vec, vec + n);
		ret = min(ret, vec[n - 1].first - vec[0].first);
	}
		
	
	cout << ret << " " << ans.size() << "\n";
	for (pair<int, int>	v:ans)
		cout << v.first + 1 << " " << v.second + 1 << "\n";
	return	0;
}