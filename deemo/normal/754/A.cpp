#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100 + 5;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int mx = -1e9, mn = 1e9;
	for (int i = 0; i < n ;i++){
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	if (mx == mn && mx == 0){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	vector<pair<int, int>>	ans;
	for (int i = 0; i < n;){
		int j = i+1;
		while (j < n && a[j] == 0)	j++;
		if (a[i] == 0){
			j++;
			while (j < n && a[j] == 0)	j++;
			ans.push_back({i, j-1}), i=j;
		}
		else
			ans.push_back({i, j-1}), i=j;
	}

	cout << ans.size() << endl;
	for (auto x:ans)
		cout << x.first+1 << " " << x.second+1 << endl;
	return 0;
}