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

int f1[367], f2[367], m1[367], m2[367];

int main() {
	int n, ans=0, m=0,f=0;
	cin >> n;
	F0R(i,n) {
		int a,b;
		char x;
		cin >> x >> a >> b;
		if (x == 'M') {
			m1[a] ++;
			m2[b+1] ++;
		} else {
			f1[a] ++;
			f2[b+1] ++;
		}
	}
	FOR(i,1,367) {
		m += m1[i];
		m -= m2[i];
		f += f1[i];
		f -= f2[i];
		ans = max(ans,2*min(m,f));
	}
	cout << ans;
	return 0;
}