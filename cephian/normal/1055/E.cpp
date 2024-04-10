#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

//point update, range query, 0-indexed
template <class T>
struct bit {
	vector<T> b;
	void init(int n){b.resize(n+1);}
	bit(){}
	bit(int n){init(n);}
	inline void update(int i, T v) {
		for(++i; i<(int)b.size(); i+=i&-i)
			b[i] += v;
	}
	//sum of the first i values
	T prefix(int i) const {
		T a = 0;
		for(; i; i^=i&-i)
			a += b[i];
		return a;
	}
	inline T query(int l, int r) const {
		return prefix(r+1)-prefix(l);
	}
};

const int N = 1505;
int n, s, m, k;
int a[N];
int b[N];
int srt[N];

int L[N], R[N];
bool in[N] ={};

pair<int,int> events[N*2];

int dp[N][N];

bool can_do(int x) {
	bit<int> B(n+1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= x) {
			B.update(i, 1);
		}
	}
	//dp[i, j] = up to location i, using <= j segs, how many 1s acn we get?

	map<pair<int,int>, int> opens;
	fill(in, in+N, false);

	int best = 0;
	int cur = 0;
	for(int i = 1; i <= n; ++i) {
		while(cur < s*2 && events[cur].first == i) {
			int id = events[cur].second;
			const pair<int,int> p(L[id], R[id]);
			if(in[id]) {
				in[id] = false;
				if(--opens[p] == 0)
					opens.erase(p);
			} else {
				in[id] = true;
				++opens[p];
			}
			++cur;
		}

		for(int j = 1; j <= m; ++j) {
			dp[i][j] = dp[i-1][j];
			if(opens.size()) {
				const auto p = opens.begin()->first;
				dp[i][j] = max(dp[i][j], dp[p.first-1][j-1] + B.query(p.first, min(i, p.second)));
			}
			best = max(best, dp[i][j]);
			//cout << i << ", " << j << ": " << dp[i][j] << endl;
		}
	}
	return best >= k;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> s >> m >> k;

	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		srt[i] = a[i];
	}

	for(int i = 1; i <= s; ++i) {
		cin >> L[i] >> R[i];
		events[2*i-2] = make_pair(L[i], i);
		events[2*i-1] = make_pair(R[i]+1, i);
	}
	sort(events, events+2*s);

	for(int i = 0; i <= n; ++i) dp[i][0] = 0;
	for(int j = 0; j <= m; ++j) dp[0][j] = 0;

	sort(srt+1, srt+n+1);
	if(!can_do(srt[n])) {
		cout << "-1\n";
		return 0;
	}

	int lo = -1, hi = n;
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		if(can_do(srt[md]))
			hi = md;
		else lo = md;
	}
	cout << srt[hi] << endl;
}