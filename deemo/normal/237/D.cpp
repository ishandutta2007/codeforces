#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, sz;
vector<int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << n - 1 << "\n";
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		vec[a].push_back(sz);
		vec[b].push_back(sz++);
		cout << 2 << " " << a + 1 << " " << b + 1 << "\n";
	}
	for (int i = 0; i < n; i++)
		for (int j = 1; j < vec[i].size(); j++)
			cout << vec[i][j - 1] + 1 << " " << vec[i][j] + 1 << "\n";
	return	0;
}