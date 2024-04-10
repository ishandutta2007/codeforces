#include<bits/stdc++.h>

using namespace std;

const int MAXX = 1e3 + 10;

int cnt[MAXX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x0;	cin >> n >> x0;
	int mx = -1, mn = 1e9;
	for (int i = 0; i < n; i++){
		int a, b;	cin >> a >> b;
		if (a > b)	swap(a, b);
		for (int j = a; j <= b; j++)
			cnt[j]++;
	}
	int ans = 1e9;
	for (int i = 0; i < MAXX; i++)
		if (cnt[i] == n)
			ans = min(ans, abs(i - x0));
	
	if (ans > 1e8)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}