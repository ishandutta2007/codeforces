#include<bits/stdc++.h>

using namespace std;

const int MAXK = 100 + 5;

int n, m, k, x[MAXK], d[MAXK];

int get(int v){
	int ret = 0;
	int mx = n/v * v;
	while (mx <= n)	mx += v;
	
	for (int i = 0; i < k; i++)
		if (x[i] <= mx && x[i] % v == 0)	ret++;

	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)	cin >> d[i];
	for (int i = 0; i < k; i++)	cin >> x[i];

	int mn = 1e9;
	for (int i = 0; i < m; i++)	mn = min(mn, get(d[i]));
	vector<int>	ans;
	for (int i = 0; i < m; i++)	if (get(d[i]) == mn)	ans.push_back(i + 1);
	cout << ans.size() << "\n";
	for (int v:ans)
		cout << v << " ";
	cout << "\n";
	return 0;
}