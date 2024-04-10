#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

pi a[200005];
int d[200005], pmx[200005], pmn[200005], smx[200005], smn[200005], n;

bool ok(int x) {
	vi v;
	for(int i=1;i<=n;i++)
		if(i != x)
			v.PB(a[i].F);
	for(int i=0;i<v.size()-1;i++)
		if(v[i+1] - v[i] != v[1] - v[0])
			return false;
	
	return true;
}

int main()
{
	IO_OP;
	
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	if(n == 2) {
		cout << 1 << endl;
		return 0;
	}
	if(n == 3) {
		cout << 1 << endl;
		return 0;
	}
	sort(a+1, a+n+1);
	for(int i=1;i<n;i++)
		d[i] = a[i+1].F - a[i].F;
	pmx[0] = -INF, pmn[0] = INF;
	for(int i=1;i<n;i++) {
		pmx[i] = max(pmx[i-1], d[i]);
		pmn[i] = min(pmn[i-1], d[i]);
	}
	smx[n] = -INF, smn[n] = INF;
	for(int i=n-1;i>=1;i--) {
		smx[i] = max(smx[i+1], d[i]);
		smn[i] = min(smn[i+1], d[i]);
	}
	if(pmx[n-2] == pmn[n-2]) {
		cout << a[n].S << endl;
		return 0;
	}
	if(smx[2] == smn[2]) {
		cout << a[1].S << endl;
		return 0;
	}
	if(ok(2)) {
		cout << a[2].S << endl;
		return 0;
	}
	if(ok(n-1)) {
		cout << a[n-1].S << endl;
		return 0;
	}
	for(int i=3;i<n-1;i++) {
		if(smx[i+1] == smn[i+1] && pmx[i-2] == pmn[i-2] && smx[i+1] == pmx[i-2] && a[i+1].F-a[i-1].F == pmx[i-2]) {
			cout << a[i].S << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}