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
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

map<pii,int> k;
pii d;
int n;
vector<pii> points, mids;

int main() {
	cin >> n;
	F0R(i,n) {
		cin >> d.f >> d.s;
		points.pb(d);
	}
	
	F0R(i,n) {
		FOR(j,i+1,n) {
			pii z = mp(points[i].f+points[j].f,points[i].s+points[j].s);
			k[z] ++;
			if (k[z] == 1) {
				mids.pb(z);
			}
		}
	}
	
	int ans = 0;
	F0R(i,mids.size()) {
		ans += k[mids[i]]*(k[mids[i]]-1)/2;
	}
	cout << ans;
	return 0;
}