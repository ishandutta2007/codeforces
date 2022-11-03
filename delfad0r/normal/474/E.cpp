#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <utility>

using namespace std;

typedef pair< int, int > ii;
typedef pair< long long, int > li;

template< int N >
class fenwick_t {
	ii ft[N + 1];
public:
	ii query(int x) {
		ii ans = { 0, 0 };
		for(; x > 0; x -= x & (-x))
			if(ans.second < ft[x].second) {
				ans.first = ft[x].first;
				ans.second = ft[x].second;
			}
		return ans;
	}
	void update(int p, int v) {
		for(int x = p; x <= N; x += x & (-x))
			if(ft[x].second < v) {
				ft[x].first = p;
				ft[x].second = v;
			}
	}
};

int ind[100001];
li H[100001];
int pr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	
	int N, D;
	fenwick_t< 100000 > fen, inv_fen;
	cin >> N >> D;
	for(int n = 1; n <= N; ++n) {
		cin >> H[n].first;
		H[n].second = n;
	}
	
	sort(H + 1, H + N + 1);
	for(int n = 1; n <= N; ++n)
		ind[H[n].second] = n;
	
	for(int n = 1; n <= N; ++n) {
		int low = upper_bound(H + 1, H + N + 1, li(H[ind[n]].first - D, 1 << 20)) - H - 1;
		int high = lower_bound(H + 1, H + N + 1, li(H[ind[n]].first + D, 0)) - H;
		int best = 0;
		if(low > 0) {
			ii q = fen.query(low);
			if(q.second > best) {
				best = q.second;
				pr[n] = H[q.first].second;
			}
		}
		if(high <= N) {
			ii q = inv_fen.query(N + 1 - high);
			if(q.second > best) {
				best = q.second;
				pr[n] =  H[N + 1 - q.first].second;
			}
		}
		++best;
		fen.update(ind[n], best);
		inv_fen.update(N + 1 - ind[n], best);
	}
	
	deque<int> ans;
	for(int i = H[fen.query(N).first].second; i != 0; i = pr[i])
		ans.push_front(i);
	
	cout << fen.query(N).second << '\n';
	for(auto & x : ans) cout << x << ' ';
	
	return 0;
}