#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 2e5+87; 

int dp[N][6], prev[N][6], a[N];

int main()
{
	IO_OP;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=1;i<=5;i++)
		dp[0][i] = i;
	for(int i=1;i<n;i++) {
		if(a[i] > a[i-1]) {
			for(int j=1;j<=5;j++) {
				if(dp[i-1][j]) {
					dp[i][j+1] = j;
				}
				else if(dp[i][j]){
					dp[i][j+1] = dp[i][j]; 
				}
				 
			}
		}
		if(a[i] < a[i-1]) {
			for(int j=5;j>=1;j--) {
				if(dp[i-1][j]) {
					dp[i][j-1] = j;
				} else if(dp[i][j])
					dp[i][j-1] = dp[i][j]; 
				 
			} 
		}
		if(a[i] == a[i-1]) {
			for(int j=1;j<=5;j++) {
				int lst = 0;
				for(int k=1;k<=5;k++) {
					if(dp[i-1][k] && k != j) lst = k;
				}
				dp[i][j] = lst;
				
			}
		}
	}
	for(int i=1;i<=5;i++) {
		if(dp[n-1][i]) {
			vi ans={i};
			int cnt = i;
			for(int j=n-1;j>=1;j--) {
				ans.PB(dp[j][cnt]);
				cnt = dp[j][cnt];
			}
			for(int j=n-1;j>=0;j--)
				cout << ans[j] << " "; 
			return 0;
		}
	}
	
	cout << -1 << endl;
}