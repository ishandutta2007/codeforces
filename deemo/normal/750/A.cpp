#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	int n, k;	cin >> n >> k;
	int cur = k;
	for (int i = 1; i <= n; i++){
		cur += 5*i;
		if (cur > 240)	break;
		ans++;
	}
	cout << ans << endl;
	return 0;
}