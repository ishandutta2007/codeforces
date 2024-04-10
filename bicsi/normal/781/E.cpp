// Create your own template by modifying this file!
#include <bits/stdc++.h>
using namespace std;

int n, h, w;
const int kMod = 1e9 + 7;

struct Barrier {
	int row, l, r, tres;
};

map<int, int> Set[500000];

bool TreeComp(int a, int b) {

	assert(a != 0); assert(b != 0);

	if(Set[a].empty()) return false;
	if(Set[b].empty()) return true;
	if(Set[a].begin()->first < Set[b].begin()->first)
		return true;
	return false;
}

int TPos[5000000];
void Init(int node, int b, int e) {
	TPos[node] = b;
	if(b == e) return;

	int m = (b + e) / 2;
	Init(node * 2, b, m);
	Init(node * 2 + 1, m + 1, e);
}
void Refresh(int node, int b, int e, int pos) {
	// cerr << "Refresh: " << node << " " << b << " " << e << " " << pos << endl;
	if(b == e) {
		assert(pos == b);
		TPos[node] = b;
		return;
	}
	
	int m = (b + e) / 2;
	if(pos <= m) Refresh(node * 2, b, m, pos);
	else Refresh(node * 2 + 1, m + 1, e, pos);

	TPos[node] = min(TPos[node * 2], TPos[node * 2 + 1], TreeComp);	
	// cerr << "TPos " << node << " " << b << " " << e << " " << pos << ": " << TPos[node] << endl;
}
int Query(int node, int b, int e, int l, int r) {
	if(b >= l && e <= r) return TPos[node];
	if(b > r || e < l) return l;

	int m = (b + e) / 2;
	return min(	Query(node * 2, b, m, l, r),
				Query(node * 2 + 1, m + 1, e, l, r),
				TreeComp );
}

void Insert(int pos, int h, int c) {
	Set[pos][h] += c;
	Set[pos][h] %= kMod;

	// cerr << "From insert: ";
	// cerr << Set[pos].begin()->first << endl;

	Refresh(1, 1, w, pos);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> h >> w >> n;

	Init(1, 1, w);
	for(int i = 1; i <= w; ++i) {
		Insert(i, h + 1, 1);
	}

	vector<Barrier> barriers;
	for(int i = 1; i <= n; ++i) {
		int row, l, r, tres;
		cin >> row >> l >> r >> tres;
		barriers.push_back(Barrier {row, l, r, tres});
	}

	sort(barriers.begin(), barriers.end(), [](Barrier a, Barrier b) {
		return a.row > b.row;
	});

	for(auto b : barriers) {
		int to_left = b.l == 1 ? b.r + 1 : b.l - 1;
		int to_right = b.r == w ? b.l - 1: b.r + 1;

		int balls = 0;
		while(true) {
			int idx = Query(1, 1, w, b.l, b.r);
			// cerr << "Got: " << idx << endl;
			// cerr << Set[idx].size() << endl;

			if(Set[idx].empty() || Set[idx].begin()->first - b.row > b.tres)
				break;


			auto it = Set[idx].begin();
			// cerr << "Moved: " << it->first << " height with " << it->second << " balls\n";

			balls += it->second;
			balls %= kMod;

			Set[idx].erase(it);
			Refresh(1, 1, w, idx);
		}

		Insert(to_left, b.row, balls);
		Insert(to_right, b.row, balls);
	}

	int ans = 0;

	for(int i = 1; i <= w; ++i) {
		for(auto p : Set[i]) {
			ans += p.second;
			ans %= kMod;
		}
	}

	cout << ans << endl;
}