#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 2e18;
const int MAX = 1e6 + 10;

ll dp[MAX];

int main(){
	ll x;	cin >> x;
	int ans = 0;
	dp[0] = 1;
	for (int i = 1; i < MAX; i++){
		dp[i] = dp[i - 1] + dp[max(0,i - 2)];
		if (dp[i] > x)	break;
		ans = i;
	}
	printf("%d\n", ans);
	return 0;
}