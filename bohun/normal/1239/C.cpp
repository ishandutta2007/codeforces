#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define ss(x) (int) x.size()
 
using namespace std;

const int nax = 1e5 + 111;

int n, p;
int tim;
vector <pair<int, int>> v;
ll ans[nax];

queue <int> q;
set <int> s, kol;

bool good(int u) {
	return kol.size() == 0 || *kol.begin() > u;
}

void add(int u) {
	s.erase(s.begin());
	kol.insert(u);
	q.push(u);
}
 
int main() {
	scanf("%d %d", &n, &p);
	for(int i = 1; i <= n; ++i) { 
		scanf("%d", &tim);
		v.pb(mp(tim, i));
	}
	sort(v.begin(), v.end());
	ll Time = 0;
	int N = n;
	int w = 0;
	
	int Last = -1;
	
	while(N--) {
		if(!s.size() && kol.size() <= 1 && Time < v[w].fi) {
			int co = v[w].fi;
			while(w < n && v[w].fi == co) {
				s.insert(v[w].se);
				if(good(v[w].se))
					add(v[w].se);
				w += 1;
			}
			Time = co;
		}
		else {
			while(w < n && v[w].fi < Time) {
				s.insert(v[w].se);
				if(good(v[w].se))
					add(v[w].se);
				w += 1;
			}
		}
		//cout << s.size() << " " << kol.size() << " " << q.size() << endl;
		if(Last != -1) {
			kol.erase(Last);
		}
		
		while(w < n && v[w].fi == Time) {
				s.insert(v[w].se);
				w += 1;
			}
		while(s.size() && good(*s.begin()))
			add(*s.begin());
		
		int u = q.front();
		Last = u;
		q.pop();
		Time += p;
		ans[u] = Time;	
	}
	
	for(int i = 1; i <= n; ++i) 
		printf("%lld ", ans[i]);
 
	return 0;
}