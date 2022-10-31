#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 5005;
int a[N]={};
ll dp[N][4];
int prv[N][4];

vi ans;

void trace(int i, int k) {
	if(i < 0 || k < 0) return;
	if(prv[i][k] == 1) ans.pb(i), trace(i,k-1);
	else trace(i-1,k);
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",a+i);
	for(int i = 0; i <= n; ++i) {
		for(int k = 0; k <= 3; ++k) {
			int v = (k&1)?-1:1;
			dp[i][k] = -(1LL<<60);
			//transition now
			if(k) {
				ll tmp = dp[i][k-1];
				if(dp[i][k] < tmp)
					dp[i][k] = tmp, prv[i][k] = 1;
			}
			//transition prior
			if(i) {
				ll tmp = dp[i-1][k] + v*a[i-1];
				if(dp[i][k] < tmp)
					dp[i][k] = tmp, prv[i][k] = 0;
			}
			if(!k && !i)
				dp[i][k] = 0;
		}
	}
	trace(n,3);
	sort(ans.begin(),ans.end());
	for(auto a : ans)
		printf("%d ",a);
	printf("\n");
}