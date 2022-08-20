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
	ll n, sum = 0;
	cin >> n;
	F0R(i,2520) {
		if ((i % 2 != 0) && (i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0) && i <= n) {
			sum +=(n-i)/2520;
			sum += 1;
		}
	}
	cout << sum;
}