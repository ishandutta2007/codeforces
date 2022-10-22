//There's just too much that time cannot erase..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, gr[MAXN], q[MAXN], xx[MAXN];
bool mark[MAXN];
vector<pair<int, int>>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		int sum = i;
		for (int j = i + 1; j <= n; j++){
			sum += j;
			if (sum > n)	break;
			vec[sum].push_back({i, j});
		}
	}
	
	for (int i = 1; i <= n; i++){
		int h = 0, t = 0;
		for (pair<int, int>	v:vec[i])
			q[t++] = xx[v.second] ^ xx[v.first - 1], mark[q[t - 1]] = 1;
		int j = 0;
		while (mark[j])	j++;
		gr[i] = j;
		for (j = 0; j < t; j++)	mark[q[j]] = 0;
	
		xx[i] = xx[i - 1] ^ gr[i];
	}

	if (gr[n] == 0)
		cout << -1 << "\n";
	else{
		int mini = 1e9;
		for (pair<int, int>	v:vec[n])
			if ((xx[v.second] ^ xx[v.first - 1]) == 0)
				mini = min(mini, v.second - v.first + 1);
		cout << mini << "\n";
	}
	return	0;
}