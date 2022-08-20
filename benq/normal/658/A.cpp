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

ll a=0, b=0, n,c, scores[1000], tim[1000];

void calca() {
	ll ti = 0;
	F0R(i,n) {
		ti += tim[i];
		a += max((ll)0,scores[i]-c*ti);
	}
}

void calcb() {
	ll ti = 0;
	F0Rd(i,n) {
		ti += tim[i];
		b += max((ll)0,scores[i]-c*ti);
	}
}

int main() {
	cin >> n >> c;
	F0R(i,n) cin >> scores[i];
	F0R(i,n) cin >> tim[i];
	calca();
	calcb();
	if (a>b) cout << "Limak";
	else if (a == b) cout << "Tie";
	else cout << "Radewoosh";
	return 0;
}