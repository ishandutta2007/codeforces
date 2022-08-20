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

int n;

vector<pair<pair<ll,ll>,ll>> points;

int online(int w, int x, int y) {
	if ((points[x].f.s-points[w].f.s)*(points[y].f.f-points[w].f.f) == (points[y].f.s-points[w].f.s)*(points[x].f.f-points[w].f.f)) {
		return 1;
	}
	return 0;
}

int main() {
	cin >> n;
	FOR(i,1,n+1) {
		pii temp;
		cin >> temp.f >> temp.s;
		points.pb(mp(temp,i));
	}
	sort(points.begin(), points.end());
	cout << points[n-1].s << " " << points[n-2].s << " ";
	int k = n-3;
	while (online(n-1,n-2,k)) k--;
	cout << points[k].s;
}