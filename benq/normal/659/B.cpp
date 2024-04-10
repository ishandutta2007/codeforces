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

bool comp (pair<int,string> a, pair<int,string> b) {
	if (a.f > b.f) return true;
	else if (a.f == b.f) return a.s > b.s;
	return false;
}

int main() {
	int n,m;
	vector<pair<int,string>> regions[10001];
	cin >> n >> m;
	F0R(i,n) {
		string a;
		int b, c;
		cin >> a >> b >> c;
		regions[b].pb(mp(c,a));
	}
	FOR(i,1,m+1) {
		sort(regions[i].begin(),regions[i].end(), comp);
		if (regions[i].size() > 2 && regions[i][1].f == regions[i][2].f) cout << '?';
		else cout << regions[i][0].s << " " << regions[i][1].s;
		cout << endl;
	}
	return 0;
}