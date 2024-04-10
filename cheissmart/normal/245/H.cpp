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

int dp1[5005][5005], dp2[5005][5005];

int main()
{
	IO_OP;
	
	string s;
	int q;
	cin >> s >> q;

	for(int i=0;i<s.size();i++)
		dp1[i][i] = 1;
	for(int i=2;i<=s.size();i++) {
		for(int j=0;j+i-1<s.size();j++) {
			int l = j, r = j + i - 1;
			dp1[l][r] = s[l] == s[r] && (i==2 || dp1[l+1][r-1]); 
		}
	}
	for(int i=0;i<s.size();i++) {
		dp2[i][i] = 1;
		for(int j=i+1;j<s.size();j++) {
			dp2[i][j] = dp2[i][j-1] + dp1[i][j];
		}
	}
	for(int i=0;i<s.size();i++)
		dp1[i][i] = 1;
	for(int i=2;i<=s.size();i++) {
		for(int j=0;j+i-1<s.size();j++) {
			int l = j, r = j + i - 1;
			dp1[l][r] = dp1[l+1][r] + dp2[l][r];
		}
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << dp1[l][r] << '\n';
	}
	
}