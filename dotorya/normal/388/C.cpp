	#include <stdio.h>
	#include <vector>
	#include <algorithm>
	using namespace std;
	vector <int> x;
	int d[105][105];
	int main() {
		int N, t, i, j, ans1 = 0, ans2 = 0;
		scanf("%d", &N);
		for(i = 1; i <= N; i++) {
			scanf("%d", &d[i][0]);
			for(j = 1; j <= d[i][0]; j++) scanf("%d", &d[i][j]);
		}
		for(i = 1; i <= N; i++) {
			for(j = 1; j <= d[i][0]/2; j++) ans1 += d[i][j];
			for(j = 1; j <= d[i][0]/2; j++) ans2 += d[i][d[i][0]+1-j];
			if(d[i][0]%2 != 0) x.push_back(d[i][(1+d[i][0])/2]);
		}
		sort(x.begin(), x.end());
		while(!x.empty()) {
			ans1 += x.back();
			x.pop_back();
			if(x.empty()) break;
			ans2 += x.back();
			x.pop_back();
		}
		printf("%d %d", ans1, ans2);
		return 0;
	}