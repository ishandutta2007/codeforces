#include<bits/stdc++.h>
using namespace std;
int cnt[111111];
int main() {
	int n;
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int ans(1);
	for(int i(2); i <= 100000; i++) {
		int tmp(0);
		for(int j(1); j * i <= 100000; j++) {
			tmp += cnt[j * i];
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
}