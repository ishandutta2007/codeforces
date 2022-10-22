#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, s, d;
vector<pair<int, int>>	vec, sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		vec.push_back({x, x + 1});
	}
	sort(vec.begin(), vec.end());
	if (vec[0].first <= s){
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 0; i < vec.size(); i++){
		if (sec.empty() || vec[i].first - sec.back().second > s)
			sec.push_back(vec[i]);
		else
			sec.back().second = vec[i].second;
	}

	for (auto v:sec)
		if (v.second - v.first >= d){
			cout << "IMPOSSIBLE\n";
			return	0;
		}

	int cur = 0;
	for (auto v:sec){
		if (cur + 1 < v.first)
			cout << "RUN " << v.first - cur - 1 << "\n";
		cout << "JUMP " << v.second - v.first + 1 << "\n";
		cur = v.second;
	}
	if (cur < m)
		cout << "RUN " << m - cur << "\n";
	return	0;
}