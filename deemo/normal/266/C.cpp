#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e3 + 10;

int r[MAXN], c[MAXN];
bool t[MAXN][MAXN];
vector<pair<pair<int, int>, int>>	ans;

void solve(int n, int add){
	for (int i = add; i < n; i++)
		if (r[i] == 0){
			if (i == add)	break;
			ans.push_back({{1, i + 1}, add + 1});
			for (int j = 0; j < n; j++)
				swap(t[i][j], t[add][j]);
			break;
		}
	int h = -1;
	for (int i = add; i < n; i++)
		if (c[i] != 0){
			h = i;
			if (i == add)	break;
			ans.push_back({{2, i + 1}, add + 1});
			for (int j = 0; j < n; j++)
				swap(t[j][i], t[j][add]);
			break;
		}
	if (h == -1)	return;
	add++;
	for (int i = add; i < n; i++){
		r[i] = 0;
		for (int j = add; j < n; j++)
			r[i] += t[i][j];
	}
	for (int j = add; j < n; j++){
		c[j] = 0;
		for (int i = add; i < n; i++)
			c[j] += t[i][j];
	}		

	if (n - add >= 2)
		solve(n, add);
}

int main(){
	int n;	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--,	b--;
		r[a]++;
		c[b]++;
		t[a][b] = 1;
	}
	solve(n, 0);
	cout << ans.size() << "\n";
	for (pair<pair<int, int>, int>	v:ans)
		cout << v.first.first << " " << v.first.second << " " << v.second << "\n";
	return 0;
}