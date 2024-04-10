#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

// closest stairs, elevator in each direction

const int INF = 1e9;
const ll INFLL = 1e18;

struct pt {
	 int x, y;
	 pt() {}
	 pt(int a, int b) : x(a), y(b) {}
	 bool operator< (const pt& o) { return y < o.y; }
	 string tostring() const {
		return "(" + to_string(x) + "," + to_string(y) + ")";
	 }
};

template <typename IT>
void fill(IT stairit, IT stairend, IT posit, IT posend, function<int&(pair<pii, pii>&)> f, function<bool(int, int)> comp, map<int, pair<pii, pii>>& mp, int init) {
	int last = init;
	for(;stairit != stairend;++stairit) {
		for(;posit != posend && comp(*posit , *stairit);++posit) {
			if(mp.count(*posit) == 0) {
				mp[*posit] = pair<pii, pii>();
			}
			f(mp[*posit]) = last;
		}
		last = *stairit;
	}
	for(;posit != posend; ++posit) {
		if(mp.count(*posit) == 0) {
			mp[*posit] = pair<pii, pii>();
		}
		f(mp[*posit]) = last;
	}
}

ll compute_time(int transport_pos, int v, pt p1, pt p2)
{
	if(transport_pos == -1) {
		return INFLL;
	}
	if(p1.x == p2.x) {
		return abs(p1.y-p2.y);
	}
	ll horizontal_time = abs(p1.y-transport_pos) + abs(p2.y-transport_pos);
	int height = abs(p1.x-p2.x);
	ll ans;
	if(v == -1) {
		ans = horizontal_time + height;
	} else {
		ll extra = height/v;
		if(height%v != 0) ++ extra;
		ans = horizontal_time + extra;
	}
	//cerr << "ANS " << ans << endl;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M; cin >> N >> M;
	int L, E; cin >> L >> E; // stairs, elevators
	int v; cin >> v;
	vector<int> l(L), e(E);
	for(int& ii : l) cin >> ii;
	for(int& ii : e) cin >> ii;
	
	int Q;cin >> Q;
	vector<pair<pt, pt>> queries;
	vector<int> rnums;
	map<int, pair<pii, pii>> mp; // maps position to indices of staircases (l, r), and elevators (l, r)
	while(Q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		queries.push_back(pair<pt, pt>(pt(x1, y1), pt(x2, y2)));
		rnums.push_back(y1);
		rnums.push_back(y2);
	}
	sort(rnums.begin(), rnums.end());

	fill(l.begin(),  l.end(),  rnums.begin(),  rnums.end(),  [](pair<pii, pii>& pr) -> int& { return pr.first.first;  }, [](int a, int b) -> bool {return a<b;}, mp, -1);
	fill(l.rbegin(), l.rend(), rnums.rbegin(), rnums.rend(), [](pair<pii, pii>& pr) -> int& { return pr.first.second; }, [](int a, int b) -> bool {return a>b;}, mp, -1);
	fill(e.begin(),  e.end(),  rnums.begin(),  rnums.end(),  [](pair<pii, pii>& pr) -> int& { return pr.second.first; }, [](int a, int b) -> bool {return a<b;}, mp, -1);
	fill(e.rbegin(), e.rend(), rnums.rbegin(), rnums.rend(), [](pair<pii, pii>& pr) -> int& { return pr.second.second;}, [](int a, int b) -> bool {return a>b;}, mp, -1);

	for(pair<pt, pt> query : queries) {
		pair<pii, pii> positions = mp[query.first.y];
		ll ans = INFLL;
		ans = min(ans, compute_time(positions.first.first, -1, query.first, query.second));
		ans = min(ans, compute_time(positions.first.second, -1, query.first, query.second));
		ans = min(ans, compute_time(positions.second.first, v, query.first, query.second));
		ans = min(ans, compute_time(positions.second.second, v, query.first, query.second));
		cout << ans << "\n";
	}
	
	return 0;
}