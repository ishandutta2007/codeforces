#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[102];

int main()
{
	IO_OP;
	
	int n, d;
	string s;
	cin >> n >> d >> s;
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for(int i=1;i<n;i++) {
		if(s[i] == '0') continue;
		for(int j=1;j<=d;j++) {
			if(i-j >= 0)
				dp[i] = min(dp[i], dp[i-j] + 1);
		}
	}
	if(dp[n-1] != 0x3f3f3f3f)
		cout << dp[n-1] << endl;
	else
		cout << "-1" << endl;

}