#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	string s;
	int m;
	cin >> s >> m;
	F0R(i,m) {
		int l,r,k;
		cin >> l >> r >> k;
		r--;
		l--;
		k %= (r-l+1);
		string temp1 = s.substr(r-k+1,k), temp2 = s.substr(l,r-l+1-k);
		F0R(j,k) s[l+j] = temp1[j];
		F0R(j,r-l-k+1) s[j+k+l] = temp2[j];
	}
	cout << s;
	return 0;
}