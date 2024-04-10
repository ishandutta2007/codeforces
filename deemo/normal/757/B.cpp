#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, cnt[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	if (cnt[1])	ans = 1;
	
	for (int i = MAXN - 1; i > 1; i--){
		int t = 0;
		for (int j = i; j < MAXN; j += i)
			t += cnt[j];
		ans = max(ans, t);
	}
	cout << ans << "\n";
	return 0;
}