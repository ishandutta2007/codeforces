#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <ll,ll> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

bool comp(pii a, pii b) {
    if (a.f != b.f) return (a.f>b.f);
    else return (a.s<b.s);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	pii x; cin >> x.f >> x.s;
	vector<pii> k(n-1);
	F0R(i,n-1) cin >> k[i].f >> k[i].s;
	sort(k.begin(),k.end(),comp);
	
	map<ll,int> z;
	if (x.f >= k[0].f) { cout << 1; return 0;}
	
	ll best = n, cursum = 0, curnum = 0, cnumc = 0, count = 0;
	FOR(i,1,n) {
		ll k1 = k[i-1].s-k[i-1].f+1;
		if (i == n-1) k.pb(mp(0,0));
	    z[k1]++;
	    if (k[i].f > x.f) continue;
	    
	    if (k1 < curnum) {
	        cursum += k1-curnum, cnumc --;
	        if (cnumc <= 0) {
	            curnum = (*prev(z.lb(curnum))).f;
	            cnumc = z[curnum];
	        }
	    }
	    while (cursum < x.f-k[i].f) {
	        if (cnumc < z[curnum]) {
	            if (cursum + curnum <= x.f-k[i].f) {
	                cursum += curnum, cnumc++, count++;
	            } else break;
	        } else {
	            auto u = z.ub(curnum);
	            if (u == z.end()) break;
	            if (cursum + (*u).f <= x.f-k[i].f) {
	                curnum = (*u).f, cursum += (*u).f, cnumc = 1, count++;
	            } else break;
	        }
	    }
	    best = min(best,i+1-count);
	}
	cout << best;
}