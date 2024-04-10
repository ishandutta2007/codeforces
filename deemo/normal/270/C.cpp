#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec.begin(), vec.end());
	vec.push_back({vec.back().first + 1, 0});

	int ans = 0, cur = vec[0].second;
	for (int i = 1; i < n; i++){
		int last = vec[i - 1].first, c = vec[i].first;
		if (c - last > 33)	cur = 1;
		else for (int w = 0; w < c - last; w++){
			int temp = cur/4;
			if (cur % 4)	temp++;
			cur = temp;
		}

		cur = max(cur, vec[i].second);
	}
	ans = vec.back().first;
	while (cur > 4){
		ans++;
		int temp = cur/4;
		if (cur % 4)	temp++;
		cur = temp;
	}
	cout << ans << endl;
	return 0;
}