#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll n,m,len, wid, ind, arr[2000][2000], ans;
string s;

void prep() {
	cin >> n >> m >> s;
	ll ind1 = 0;
	F0R(i,s.length()) {
		if (s[i] == '(') {
			len++;
			ind1--;
		} else {
			wid++;
			ind1++;
		}
		ind=max(ind,ind1);
	}
	
	F0R(i,2000) F0R(j,2000) {
		if (i == 0 && j == 0) arr[i][j] = 1;
		else if (i >= j) {
			if (i>0 && (i-1) >= j) arr[i][j] += arr[i-1][j];
			if (j>0) arr[i][j] += arr[i][j-1];
			arr[i][j] %= MOD;
		}
	}
}

int main() {
	prep();
	if (n % 2 == 1) {
		cout << 0;
		return 0;
	}
	
	F0R(i,2000) F0R(j,2000) {
		if (i-j-ind >= 0 && (i+len) <=n/2 && (j+wid)<=n/2) {
			ans += (arr[i][j]*arr[n/2-j-wid][n/2-i-len]);
			ans %= MOD;
		}
	}
	cout << ans;
	return 0;
}