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
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<pii> a,b;
	F0R(i,n) {
		int x; cin >> x;
		a.pb(mp(x,i));b.pb(mp(x,i));
	}
	sort(a.begin(),a.end());
	F0R(i,n) {
		b[a[i].s].s = i;
	}
	F0R(i,n) {
		int j = i;
		for (;j<n; ++j) {
			if (b[j].s == i) break;
		}
		while (j > i) {
			swap(b[j-1],b[j]);
			cout << (j) << " " << (j+1) << endl;
			j--;
		}
	}
	return 0;
}