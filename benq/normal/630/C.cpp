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

ll power(ll k) {
	ll result = 1;
	F0R(i,k) result *= 2;
	return result;
}

int main() {
	ll n, sum=0;
	cin >> n;
	FOR(i,1,n+1) {
		sum += power(i);
	}
	cout << sum;
	return 0;
}