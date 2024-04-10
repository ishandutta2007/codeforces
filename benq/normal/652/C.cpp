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
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int track[300001], k;
ll lans=0, n,m, curcount=0;
pii foe[300001];

bool comp(pii a, pii b) {
	if (a.s > b.s) return true;
	else if (a.s == b.s) return a.f>b.f;
	return false;
}

int main() {
	cin >> n >> m;
	F0R(i,n) {
		scanf("%d",&k);
		track[k] = i;
	}
	F0R(i,m) {
		pii k;
		scanf("%d%d", &k.f, &k.s);
		foe[i] = mp(min(track[k.f],track[k.s])+1, n-max(track[k.f],track[k.s]));
	}
	sort(foe,foe+m,comp);
	// F0R(i,m) cout << foe[i].f << " " << foe[i].s << endl;
	F0R(i,m) {
		if (foe[i].f > curcount) {
			lans += (foe[i].f-curcount)*foe[i].s;
			curcount = foe[i].f;
		}
	}
	cout << (n*(n+1)/2-lans);
	return 0;
}