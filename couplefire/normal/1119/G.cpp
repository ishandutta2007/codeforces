#include<bits/stdc++.h>

using namespace std;

#define NN 1000005

int hp[NN], sum[NN];
vector<int> ans[NN];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; i++) {
		scanf("%d", hp+i);
		sum[i] = (sum[i-1] + hp[i]) % n;
	}
	
	sum[m] = n;
	sort(sum + 1, sum + m + 1);
	for(int i=m; i; i--) sum[i] -= sum[i-1];
	
	int cur = 1;
	
	for(int i=1; i<=m; i++) {
		while(hp[i] > 0) {
			ans[cur].push_back(i);
			hp[i] -= sum[cur];
			cur = cur % m + 1;
		}
	}
	
	cout << ans[1].size() << endl;
	for(int i=1; i<=m; i++) {
		cout << sum[i] << ' ' ;
	}
	puts("");
	
	for(int j=0; j<ans[1].size(); j++) {
		for(int i=1; i<=m; i++) {
			cout << (j >= ans[i].size() ? 1 : ans[i][j]) << ' ' ;
		}
		puts("");
	}
}