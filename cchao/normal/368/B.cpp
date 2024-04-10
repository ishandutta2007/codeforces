#include <iostream>
using namespace std;

bool vis[100010]={};
int a[100010]={}, ans[100010]={};
int main() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = n-1; i >= 0; --i) {
		ans[i] += ans[i+1];
		if(!vis[a[i]]) {
			ans[i]++;
		}
		vis[a[i]] = true;
	}
	while(m--) {
		int t; cin >> t;
		cout << ans[t-1] << endl;
	}
	return 0;
}