#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e3 + 10;

int n, w[MAXN], d[MAXN][MAXN];
bool vis[MAXN][MAXN];

int solve(int cur, int ind){
	if (vis[cur][ind])	return	d[cur][ind];
	vis[cur][ind] = 1;
	if (cur == n)
		return	d[cur][ind] = w[ind];

	if (cur == n - 1)
		return d[cur][ind] = max(w[ind], w[cur]);

	return d[cur][ind] = min({max(w[ind], w[cur]) + solve(cur + 2, cur + 1), max(w[ind], w[cur + 1]) + solve(cur + 2, cur), max(w[cur + 1],w[cur]) + solve(cur + 2, ind)});
}

void show(int cur, int ind){
	if (cur == n){
		cout << ind + 1 << "\n";
		return;
	}	
	if (cur == n - 1){
		cout << ind + 1 << " " << cur + 1 << "\n";
		return;
	}
	
	if (d[cur][ind] == max(w[ind], w[cur]) + d[cur + 2][cur + 1])	cout << ind + 1 << " " << cur + 1 << "\n", show(cur + 2, cur + 1);
	else if (d[cur][ind] == max(w[ind], w[cur + 1]) + solve(cur + 2, cur))	cout << ind + 1 << " " << cur + 2 << "\n", show(cur + 2, cur);
	else if (d[cur][ind] == max(w[cur + 1], w[cur]) + d[cur + 2][ind])	cout << cur + 1 << " " << cur + 2 << "\n", show(cur + 2, ind);
}

int main(){
	cin >> n;	for (int i = 0; i < n; i++)	cin >> w[i];
	cout << solve(1, 0) << "\n";
	show(1, 0);
	return	0;
}