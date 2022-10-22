#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<pair<int, int>>	ans;

int main(){
	int x, y, a, b;	cin >> x >> y >> a >> b;
	for (int i = a; i <= x; i++)
		for (int j = b; j <= y; j++)
			if (i > j)
				ans.push_back({i, j});
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (pair<int, int>	t:ans)
		cout << t.first << " " << t.second << endl;
	return 0;
}