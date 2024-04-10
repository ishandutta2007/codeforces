#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ub upper_bound

int mx[1<<21], mn[1<<20], nexmin[1<<20], ans[1<<20], n, k;

int maxquery(int low, int high) {
	low += (1<<20)-1, high += (1<<20)-1;
	int z = 0;
	while (low<high) {
		// eoeoeoeo
		if (low % 2 == 1) z = max(z,mx[low]), low++;
		if (high % 2 == 0) z = max(z,mx[high]), high--;
		low /= 2, high /= 2;
	}
	if (low == high) z = max(z,mx[low]);
	return z;
}

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> k;
	vector<pii> pairs;
	set<int> indices; indices.insert(n+1);
	FOR(i,1,n+1) cin >> mx[i+(1<<20)-1];
	FORd(i,1,1<<20) mx[i] = max(mx[2*i],mx[2*i+1]);
	FOR(i,1,n+1) {
		cin >> mn[i];
		pairs.pb(mp(mn[i],i));
	}
	sort(pairs.begin(),pairs.end());
	for (pii x: pairs) {
		nexmin[x.s] = *indices.ub(x.s);
		indices.insert(x.s);
	}
}

int main() {
	input();
	FORd(i,1,n+1) {
		ans[i] = min(100*maxquery(i,nexmin[i]-1),mn[i]);
		ans[i] = max(ans[i],ans[nexmin[i]]);
	}
	sort(ans+1,ans+n+1);
	double cur = 1, num = n-1, t1 = 0, t2 = 0; // n-1 choose k-1;
	FOR(i,1,n+1) {
		t1 += cur*ans[i], t2 += cur;
		cur *= (num-k+1)/num;
		num--;
	}
	cout << fixed << setprecision(9) << t1/t2;
}