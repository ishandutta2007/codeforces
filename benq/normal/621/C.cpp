#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;
 
int n,p;
double probs[100000];
 
double prob(int l, int r) {
	int ans = r/p;
	ans -= (l-1)/p;
	double asdf = ans;
	return asdf/(r-l+1);
}
 
int main() {
	cin >> n >> p;
	double ans = 0;
	F0R(i,n) {
		int l,r;
		cin >> l >> r;
		probs[i] = prob(l,r);
	}
 
	F0R(i,n-1) {
		ans += (1.0-(1.0-probs[i])*(1.0-probs[i+1]));
	}
	ans += (1.0-(1.0-probs[n-1])*(1.0-probs[0]));
	cout << fixed << setprecision(10) << (ans*2000);
	return 0;
}