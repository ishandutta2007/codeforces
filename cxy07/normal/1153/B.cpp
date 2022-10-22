//Code By CXY
#include<bits/stdc++.h>
using namespace std;

int n,m,h;
int fr[110],l[110],top[110][110];
int ans[110][110];

int main () {
	cin >> n >> m >> h;
	for(int i = 1; i <= m; ++i)
		cin >> fr[i];
	for(int i = 1;i <= n; ++i)
		cin >> l[i];
	for(int i = 1;i <= n; ++i)
		for(int j = 1;j <= m; ++j)
			cin >> top[i][j];
	for(int i = 1;i <= n; ++i) {
		for(int j = 1;j <= m; ++j) {
			if(!top[i][j]) continue;
			ans[i][j] = min(l[i],fr[j]);
		}
	}
	for(int i = 1;i <= n; ++i) {
		for(int j = 1; j <= m; ++j)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	return 0;
}