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

int test(pii a, pii b, pii c) {
	if ((b.s-a.s)*(c.f-b.f)!=(c.s-b.s)*(b.f-a.f)) {
		return 1;
	}
	return 0;
}

int main() {
	int n, ans=0;
	pii points[2000];
	cin >> n;
	F0R(i,n) {
		cin >> points[i].f >> points[i].s;
	}
	
	F0R(i,n) {
		FOR(j,i+1,n) {
			FOR(k,j+1,n) {
				ans += test(points[i],points[j],points[k]);
				// cout << i << " " << j << " " << k << endl;
			}
		}
	}
	cout << ans;
	return 0;
}