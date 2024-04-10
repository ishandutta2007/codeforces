#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 10;
const int MAX = 1e5;
const int C = 3e4;

int n, f, l;
bool d[MAXN][MAX];
int par[MAXN][MAX];

void dfs(int cur, int x){
	if (cur == n)	return;
	d[cur][x + C] = 1;
	
	for (int i = 1; i <= l; i++){
		int z = i - x;
		if (!d[cur + 1][z + C]){
			par[cur + 1][z + C] = x;
			dfs(cur + 1, z);
		}
	}
}

void show(int cur, int x, int sum = 0){
	if (cur == -1)	return;
	show(cur - 1, par[cur][x + C], x);
	cout << x + sum << " ";
}

int main(){
	cin >> n >> f >> l;
	dfs(0, f);
	
	bool found = 0;
	for (int i = 1; !found && i <= l; i++)
		if (d[n - 1][i + C]){
			found = 1;
			show(n - 1, i);
		}	
	if (!found)
		cout << -1 << endl;
	else
		cout << endl;
	return 0;
}