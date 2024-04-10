#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;


const int N = 2e5+5;
int a[N];
int m,n,k,t;
tuple<int,int,int> traps[N];
vector<int> layout[N];

bool ok(int ppl) {
	int lowest = a[m-ppl];
	fill(layout, layout+n+2, vector<int>());
	unordered_set<int> disarmed;
	unordered_set<int> behind;
	for(int i = 1; i <= k; ++i) {
		int l,r,d;
		tie(l,r,d) = traps[i];
		if(d > lowest) {
			//cout << "setting trap " << l << "," << r << "," << d << endl;
			layout[l].push_back(i);
			layout[r].push_back(-i);
		}
	}
	for(int i = 0; i <= n+1; ++i)
		sort(layout[i].rbegin(), layout[i].rend());
	int loc = 0;
	int crew = 0;
	int clock = t;
	while(crew != n+1) {
		if(loc == crew || !behind.empty()) {
			bool follow = (loc == crew);
			++loc;
			--clock;
			for(int x : layout[loc]) {
				if(x > 0) {
					if(!disarmed.count(x)) {
						behind.insert(x);
						follow = false;
					}
				} else {
					disarmed.insert(-x);
					behind.erase(-x);
				}
			}
			if(follow) {
				//cout << loc-1 << " to " << loc << ", crew follow" << endl;
				++crew;
			} else {
				//cout << loc-1 << " to " << loc << ", solo" << endl;
			}
		} else if(behind.empty()) {
			//cout << "retreive crew from " << crew << endl;
			clock -= 2*(loc - crew);
			crew = loc;
		}
		if(clock < 0) return false;
	}
	return true;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> m >> n >> k >> t;
	for(int i = 0; i < m; ++i)
		cin >> a[i];
	sort(a, a+m);

	for(int i = 1; i <= k; ++i) {
		int l,r,d;
		cin >> l >> r >> d;
		traps[i] = make_tuple(l,r,d);
	}
	int lo = 0, hi = m+1;
	while(hi-lo > 1) {
		int md = (lo+hi)/2;
		//cout << "TESTING " << md << endl;
		if(ok(md)) lo = md;
		else hi = md;
	}
	cout << lo << '\n';
}