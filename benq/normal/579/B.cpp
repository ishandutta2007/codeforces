#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define pii pair <int, int>

#define FOR(i, a, b) for (int i=a; i<b; i++)

#define f first
#define s second
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n, team[801];
vector<pair<int,pii>> a;

int main() {
	cin >> n;
	FOR(i,2,2*n+1) FOR(j,1,i) {
		pair<int,pii> b;
		scanf("%d",&b.f);
		b.s.f = i, b.s.s = j;
		a.pb(b);
	}
	sort(a.begin(),a.end());
	for (int i = a.size()-1; i >= 0; --i) {
		if (team[a[i].s.f] == 0 && team[a[i].s.s] == 0) {
			team[a[i].s.f] = a[i].s.s;
			team[a[i].s.s] = a[i].s.f;
		}
	}
	FOR(i,1,2*n+1) cout << team[i] << " ";
}