#include <bits/stdc++.h>

using namespace std;

#define F0Rd(i, a) for (int i=a; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)

int dp[76][76][76][2], v,k,x,n;
string s; 

int main() {
	cin >> n >> s;
	for (char a: s) if (a == 'V') v ++;
	else if (a == 'K') k++;
	else x++;
	
	F0Rd(i1,v) F0Rd(i2,k) F0Rd(i3,x) F0Rd(i4,1) {
		if (i1 == v && i2 == k && i3 == x) continue;
		dp[i1][i2][i3][i4] = 1000000007;
		
		int v1=0, k1=0, x1=0, v2=-1, k2=-1, x2=-1, cur=0;
		F0R(i,n) {
			if (s[i] == 'V') {
				if (v1 == i1) v2 = cur;
				if (v1 >= i1) cur++;
				v1 ++;
			} else if (s[i] == 'K') {
				if (k1 == i2) k2 = cur;
				if (k1 >= i2) cur++;
				k1++;
			} else {
				if (x1 == i3) x2 = cur;
				if (x1 >= i3) cur++;
				x1++;
			}
		}
		if (i1 != v) dp[i1][i2][i3][i4] = min(dp[i1][i2][i3][i4],dp[i1+1][i2][i3][1]+v2);
		if (i2 != k && i4 == 0) dp[i1][i2][i3][i4] = min(dp[i1][i2][i3][i4],dp[i1][i2+1][i3][0]+k2);
		if (i3 != x) dp[i1][i2][i3][i4] = min(dp[i1][i2][i3][i4],dp[i1][i2][i3+1][0]+x2);
	}
	cout << dp[0][0][0][0];
}