#include <cstdio>
#include <map>

using namespace std;

const int N = 3*100000+5;
int nr[N];
int a[N];
int dp[N];
int seg_end[N];
map<int, int> recent;

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	dp[n] = -1;
	seg_end[n] = n-1;
	for(int i = n-1; i >=0; --i) {
		dp[i] = dp[i+1];
		seg_end[i] = seg_end[i+1];
		if(recent.count(a[i])) {
			dp[i] = max(dp[i],1);
			int k = recent[a[i]];
			if(dp[k+1] != -1) {
				int q = 1+dp[k+1];
				if(q > dp[i]) {
					dp[i] = q;
					seg_end[i] = k;
				}
			}
		}
		recent[a[i]] = i;
	}
	printf("%d\n", dp[0]);
	int c=0;
	while(dp[0] != -1 && true) {
		printf("%d %d\n", c+1, seg_end[c]+1);
		if(seg_end[c] == n-1)
			break;
		c = seg_end[c]+1;
	}
	return 0;
}