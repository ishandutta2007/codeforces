#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;
const int N = 305;

int l[N], c[N];
map<int, int> dp;

int main()
{
	IO_OP;
	
	int n, g = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> l[i];
		g = __gcd(g, l[i]);
	}
	for(int i=0;i<n;i++)
		cin >> c[i];
	if(g != 1) {
		cout << -1 << endl;
		return 0;
	}
	dp[0] = 0;
	for(int i=0;i<n;i++) {
		for(auto p:dp) {
			int g = p.F, cc = p.S;
			if(dp[__gcd(g, l[i])])
				dp[__gcd(g, l[i])] = min(dp[__gcd(g, l[i])], cc+c[i]);
			else 
				dp[__gcd(g, l[i])] = cc+c[i];
		}
	}
	cout << dp[1] << endl;
	
}