#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, t[MAXN], d[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int cur = 0;
	for (int i = 0; i < n; i++){
		cin >> t[i];
		d[i + 1] = d[i] + 20;
		int pos = upper_bound(t, t + i+1, t[i] - 90) - t;
		d[i + 1] = min(d[i + 1], d[pos] + 50);
		pos = upper_bound(t, t + i+1, t[i] - 1440) - t;
		d[i + 1] = min(d[i + 1], d[pos] + 120);
		cout << d[i + 1] - cur << "\n";
		cur = d[i + 1];
	}
	return 0;
}