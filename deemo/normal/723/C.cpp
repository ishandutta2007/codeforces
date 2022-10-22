#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;

int n, m, a[MAXN], cnt[MAXN], b[MAXN];
vector<int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		a[i] = min(a[i], MAXN - 1);
		cnt[a[i]]++;
		vec[a[i]].push_back(i);
	}

	int mx = n/m, sm = 0;
	for (int i = 1; i <= m; i++){
		sm += max(0, mx - cnt[i]);
		for (int j = 1; cnt[i] < mx && j < MAXN; j++){
			int rem = max(0, cnt[j] - mx);
			if (j > m)	rem = cnt[j];
			int cc = 0;
			while (cnt[i] < mx && rem){
				rem--;
				cc++;
				cnt[i]++;
				a[vec[j].back()] = i;
				vec[j].pop_back();
			}
			cnt[j] -= cc;
		}
	}
	cout << mx << " " << sm << "\n";
	
	for (int i = 0; i < n; i++){
		if (a[i] == MAXN - 1)	a[i] = b[i];
		cout << a[i] << " ";
	}
	cout << "\n";
	return 0;
}