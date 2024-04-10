#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;
const int MAXM = 2e4 + 10;

int n, m;
vector<pair<int, string>>	vec[MAXM];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (n--){
		string a;	int t, p;	cin >> a >> t >> p;
		vec[t].push_back({p, a});
	}
	for (int i = 1; i <= m; i++){
		sort(vec[i].begin(), vec[i].end());
		int sz = vec[i].size();
		if (vec[i].size() == 2 || vec[i][sz - 2].first != vec[i][sz - 3].first)
			cout << vec[i][sz - 1].second << " " << vec[i][sz - 2].second << "\n";
		else
			cout << "?\n";
	}
	return	0;
}