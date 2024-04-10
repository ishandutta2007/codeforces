#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

const int MAXN = 50 + 2;

int n, t[MAXN], c[MAXN][MAXN];
pair<int, int> pos[MAXN * MAXN];
vector<pair<pair<int, int>, pair<int, int>>>	ans;

int main(){
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; i++)	cin >> t[i], cur += t[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < t[i]; j++)	cin >> c[i][j], pos[c[i][j]] = {i, j};
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = t[i] - 1; j >= 0; j--){
			if (c[i][j] == cur){
				cur--;
				continue;
			}

			ans.push_back({pos[cur], {i, j}});
			int a = cur, b = c[i][j];
			swap(c[i][j], c[pos[cur].first][pos[cur].second]);
			swap(pos[a], pos[b]);
			cur--;
		}		

	cout << ans.size() << "\n";
	for (auto v:ans)
		cout << v.first.first + 1 << " " << v.first.second + 1 << " " << v.second.first + 1 << " " << v.second.second + 1 << "\n";
	return	0;
}