#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;

int n, m, k;
int ans[MAXN], ss[MAXN];
vector<int>	vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			int x;	cin >> x;
			if (x)	vec[i].push_back(j), sec[j].push_back(i);
		}

	while (k--){
		int x, y;	cin >> x >> y;	x--, y--;
		ans[x]--;
		ss[y]++;
	}
	for (int i = 0; i < n; i++){
		for (int u:vec[i])
			ans[i] += ss[u];
		cout << ans[i] << " ";
	}
	cout << "\n";
	return	0;
}