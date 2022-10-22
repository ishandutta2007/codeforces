#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int a[300300];
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(0);
  int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i];
	int ans=1e9;
	for (int i = 1; i <= N; i++) {
		if (i > 1) ans = min(ans, a[i] / (i - 1));
		if (i < N) ans = min(ans, a[i] / (N - i));
	}
	cout << ans << endl;
	return 0;
}