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

ll n,m,genres[11];
	
ll combo(ll a) {
	return a*(a-1)/2;
}

int main() {
	cin >> n >> m;
	F0R(i,n) {
		int a;
		cin >> a;
		genres[a]++;
	}
	ll ans = combo(n);
	F0R(i,11) ans -= combo(genres[i]);
	cout << ans;
	return 0;
}