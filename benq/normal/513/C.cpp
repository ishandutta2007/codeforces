#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pii> lr;
int n;
double ans = 0;

double prob (int num) {
	double finprob = 0;
	
	F0R(i,n) FOR(j,1,1<<n) {
		bool x[5] = {0,0,0,0,0};
		F0R(k,n) if (j & (1<<k)) x[k] = 1;
		if (x[i]) continue;
		double cprob = 1;
		F0R(k,n) {
			if (k == i) {
				if (lr[k].f > num) continue;
				else if (lr[k].s > num) cprob *= double(lr[k].s-num)/(lr[k].s-lr[k].f+1);
				else cprob = 0;
			} else if (x[k]) {
				if (lr[k].f <= num && num <= lr[k].s) cprob /= (lr[k].s-lr[k].f+1);
				else cprob = 0;
			} else {
				if (lr[k].f >= num) cprob = 0;
				else if (lr[k].s >= num) cprob *= double(num-lr[k].f)/(lr[k].s-lr[k].f+1);
				else continue;
			}
		}
		finprob += cprob;
	}
	FOR(j,1,1<<n) {
		bool x[5] = {0,0,0,0,0};
		int sum = 0;
		F0R(k,n) if (j & (1<<k)) {
			x[k] = 1;
			sum ++;
		}
		if (sum == 1) continue;
		double cprob = 1;
		F0R(k,n) {
			if (x[k] == 1) {
				if (lr[k].f <= num && num <= lr[k].s) cprob /= double(lr[k].s-lr[k].f+1);
				else cprob = 0;
			} else {
				if (lr[k].f >= num) cprob = 0;
				else if (lr[k].s >= num) cprob *= double(num-lr[k].f)/(lr[k].s-lr[k].f+1);
				else continue;
			}
		}
		finprob += cprob;
	}
	return finprob;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; lr.resize(n);
	F0R(i,n) cin >> lr[i].f >> lr[i].s;
	FOR(i,1,10001) {
		// if (prob(i)>0) cout << i << " " << prob(i) << "\n";
		ans += i*prob(i);
	}
	cout << fixed << setprecision(15) << ans;
}