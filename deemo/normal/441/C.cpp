#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 300 + 5;

int n, m, k;
vector<pair<int, int>>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		if (i % 2 == 1)
			for (int j = 1; j <= m; j++)
				vec.push_back({i, j});
		else
			for (int j = m; j >= 1; j--)
				vec.push_back({i, j});
	}

	int i;
	for (i = 0; i < k - 1; i++)
		cout << 2 << " " << vec[2 * i].first << " " << vec[2 * i].second << " " << vec[2 * i + 1].first << " " << vec[2 * i + 1].second << "\n";
	i *= 2;

	cout << n * m - i << " ";
	for (; i < n * m; i++)
		cout << vec[i].first << " " << vec[i].second << " ";
	cout << endl;
	return	0;
}