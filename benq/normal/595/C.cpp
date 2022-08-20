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

int main() {
	int n,k,ans=1000000000;
	vi ints;
	cin >> n;
	F0R(i,n) {
		scanf("%d",&k);
		ints.pb(k);
	}
	sort(ints.begin(),ints.end());
	F0R(i,n/2) ans = min(ans,ints[i+n/2]-ints[i]);
	cout << ans;
	return 0;
}