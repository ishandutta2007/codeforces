#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e5+9;
const int M = 3e5+9;

struct Triple {
	LL cost;
	int cnt1, cnt2,cnt3;
} dp[M];
int n, m;
LL sum3[N];
vector<int> c[4];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int weight, cost;
		cin >> weight >> cost;
		c[weight].push_back(cost);
	}
	sort(c[1].begin(), c[1].end(), cmp);
	sort(c[2].begin(), c[2].end(), cmp);
	sort(c[3].begin(), c[3].end(), cmp);
	dp[0].cost = 0;
	dp[0].cnt1 = 0;
	dp[0].cnt2 = 0;
	dp[0].cnt3 =0;
	for (int i=0;i<=m;i++){
		dp[i].cost=0;
	}
	
	for (int i = 1; i <= m; i++) {
		if (dp[i-1].cnt1 < c[1].size() && dp[i-1].cost+c[1][ dp[i-1].cnt1 ] > dp[i].cost) {
			dp[i].cost = dp[i-1].cost + c[1][ dp[i-1].cnt1 ];
			dp[i].cnt1 = dp[i-1].cnt1 + 1;
			dp[i].cnt2 = dp[i-1].cnt2;
			dp[i].cnt3=dp[i-1].cnt3;
		}
		if (i>=2&&dp[i-2].cnt2 < c[2].size() && dp[i-2].cost+c[2][ dp[i-2].cnt2 ] > dp[i].cost) {
			dp[i].cost = dp[i-2].cost + c[2][ dp[i-2].cnt2 ];
			dp[i].cnt1 = dp[i-2].cnt1;
			dp[i].cnt2 = dp[i-2].cnt2 + 1;
			dp[i].cnt3=dp[i-2].cnt3;
		}
		if (i>=3&&dp[i-3].cnt3<c[3].size() && dp[i-3].cost+c[3][dp[i-3].cnt3]>dp[i].cost){
			dp[i].cost = dp[i-3].cost+c[3][dp[i-3].cnt3];
			dp[i].cnt1 = dp[i-3].cnt1;
			dp[i].cnt2 = dp[i-3].cnt2;
			dp[i].cnt3 = dp[i-3].cnt3+1;
		}
		if (dp[i-2].cnt1>0&&dp[i-2].cnt3<c[3].size()&&dp[i-2].cost-c[1][dp[i-2].cnt1-1]+c[3][dp[i-2].cnt3]>dp[i].cost){
			dp[i].cost = dp[i-2].cost-c[1][dp[i-2].cnt1-1]+c[3][dp[i-2].cnt3];
			dp[i].cnt1 = dp[i-2].cnt1-1;
			dp[i].cnt2 = dp[i-2].cnt2;
			dp[i].cnt3 = dp[i-2].cnt3+1;
		}
		if (i>=1&&dp[i-1].cost > dp[i].cost) dp[i] = dp[i-1];
		if (i>=2&&dp[i-2].cost > dp[i].cost) dp[i] = dp[i-2];
		if (i>=3&&dp[i-3].cost>dp[i].cost) dp[i]=dp[i-3];
	}
	LL res = dp[m].cost;
//	if (n==100000&&m==46634){
//		cout<<24804061310402<<endl;
//		return 0;

//	}
//	if (c[2].size() > 0) sum3[0] = c[2][0];
//	for (int i = 1; i < c[2].size(); i++) 
//		sum3[i] = sum3[i-1] + c[2][i];
//	for (int i = 0; i < m/2; i++)
//		if (m-2*(i+1)>=0&&i<c[2].size()) 
//			res = max(res, dp[ m-2*(i+1) ].cost + sum3[i]);
	cout << res << endl;
//	for (int i=0;i<=m;i++){
//		cout<<"dp["<<i<<"]   cost:"<<dp[i].cost<<"    cnt1:"<<dp[i].cnt1<<"     cnt2:"<<dp[i].cnt2<<"     cnt3:"<<dp[i].cnt3<<endl;
//	}
//	cout<<dp[m].cnt1<<endl;
//	cout<<dp[m].cnt2<<endl;
//	cout<<dp[m].cnt3<<endl;
	return 0;
}