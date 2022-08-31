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
// #define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

ll a,b,c,l,ans = 0;

void solve() {
	F0R(i,l+1) 
		if (l-i >= max((ll)0,(a+b-c+i))) 
			ans -= (i+1)*(l-i-max((ll)0,(a+b-c+i))+1);
}

int main() {
	cin >> a >> b >> c >> l;
	ans = (l+3)*(l+2)*(l+1)/6;
	solve();
	swap(a,c);
	solve();
	swap(b,c);
	solve();
	cout << ans;
	// z >= a+x+b+y-c
	// x+y+z<= l
	return 0;
}