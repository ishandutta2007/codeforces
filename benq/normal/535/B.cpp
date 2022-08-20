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
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	string n;
	cin >> n;
	int ans = 0;
	F0R(i,n.length()) {
		if (n[i] == '4') n[i] = '0';
		else n[i] = '1';
	}
	F0R(i,n.length()) {
		if (n[n.length()-1-i] != '0') {
			ans += pow(2,i);
		} 
	}
	ans += pow(2,n.length());
	ans -= 1;
	cout << ans;
	return 0;
}