//asdf
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1024 + 10;
const int INF = 2e9;

int n, k, ans[MAXN], temp[MAXN];

void solve(int z = 9){
	if (z < 0)	return;
	solve(z-1);
	{
		int t = 0;
		for (int i = 0; i < k; i++)
			if (!(i>>z&1))	t++;
		if (t){
			cout << t << endl;
			for (int i = 0; i < k; i++)
				if (!(i>>z&1))
					cout << i+1 << " ";
			cout << endl;
			for (int i = 0; i < k; i++){
				cin >> temp[i];
				if (i>>z&1)
					ans[i] = min(ans[i], temp[i]);
			}
		}
	}

	{
		int t = 0;
		for (int i = 0; i < k; i++)
			if (i>>z&1)	t++;
		if (t){
			cout << t << endl;
			for (int i = 0; i < k; i++)
				if (i>>z&1)
					cout << i+1 << " ";
			cout << endl;
			for (int i = 0; i < k; i++){
				cin >> temp[i];
				if (!(i>>z&1))
					ans[i] = min(ans[i], temp[i]);
			}
		}	
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(ans, ans + MAXN, INF);
	cin >> k;	n = 1024;
	solve();
	
	cout << "-1" << endl;
	for (int i = 0; i < k; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}