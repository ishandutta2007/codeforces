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

bool comp(pii a, pii b) {
	if (a.s<b.s) return true;
	return false;
}

int main() {
	ll n, ans=0;
	vector<pii> k;
	cin >> n;
	F0R(i,n) {
		int x,y;
		cin >> x >> y;
		k.pb(mp(x,y));
	}
	sort(k.begin(),k.end());
	F0R(i,n) {
		ll v = i;
		while (i < n-1 && k[i].f == k[i+1].f) i++;
		ans += (i-v+1)*(i-v)/2;
	}
	sort(k.begin(),k.end(),comp);
	
	F0R(i,n) {
		ll v = i;
		while (i < n-1 && k[i].s == k[i+1].s) i++;
		ans += (i-v+1)*(i-v)/2;
	}
	sort(k.begin(),k.end());
	F0R(i,n) {
		ll v = i;
		while (i < n-1 && k[i] == k[i+1]) i++;
		ans -= (i-v+1)*(i-v)/2;
	}
	cout << ans;
	return 0;
}