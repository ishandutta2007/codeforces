#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

vi init(vi& x) {
	int l = 1;
	while(l < (int)x.size()) {
		l *= 2;
	}
	vi mrq(2*l, 0);
	forn(i, x.size()) {
		mrq[i+l] = x[i];
	}
	dforn(i, l) {
		mrq[i] = mrq[2*i]+mrq[2*i+1];
	}
	return mrq;
}

void update(vi& rmq, tint pos, tint v) {
	pos += rmq.size()/2;
	rmq[pos] = v;
	while(pos > 0) {
		pos /= 2;
		rmq[pos] = rmq[2*pos] + rmq[2*pos+1];
	}
}

tint get(vi& rmq, tint n, tint nl, tint nr, tint l, tint r) {
	if(nr <= l || r <= nl) return 0;
	if(l <= nl && nr <= r) return rmq[n];
	tint mid = (nl+nr)/2;
	return get(rmq, 2*n, nl, mid, l, r) + get(rmq, 2*n+1, mid, nr, l, r);
}

tint get(vi& rmq, tint l, tint r) {
	return get(rmq, 1, 0, rmq.size()/2, l, r);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	forn(tc, T) {
		tint n;
		cin >> n;
		
		string s, t, o;
		cin >> s;
		cin >> t;
		o = s;
		sort(o.begin(), o.end());
		if(o >= t) {
			cout << -1 << endl;
			continue;
		}
		vector<set<tint>> ex(26);
		
		forn(i, n){
			ex[s[i]-'a'].insert(i);
		}
		vi x(n, 1);
		vi rmq = init(x);
		tint ans = n*n, cur = 0;
		forn(i, n) {
			tint best = n;
			forn(j, t[i]-'a') {
				if(!ex[j].empty()) {
					best = min(best, *ex[j].begin());
				}
			}
			if(best < n) {
				ans = min(ans, cur + get(rmq, 0, best));
			}
			
			if(ex[t[i]-'a'].empty()) break;
			tint voy = *ex[t[i]-'a'].begin();
			ex[t[i]-'a'].erase(voy);
			update(rmq, voy, 0);
			cur += get(rmq, 0, voy);
		}
		cout << ans << endl;
	}
}