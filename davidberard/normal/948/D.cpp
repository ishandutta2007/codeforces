#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

struct node {
	ll level;
	ll count;
	char bit;
	node** nodes;

	node() {
		nodes = new node*[2];
		nodes[0] = nullptr;
		nodes[1] = nullptr;
	}
	//node(char bt, ll lvl) : left(nullptr), right(nullptr), bit(bt), count(0), level(lvl) {}
	void insert(ll v) {
		++count;
		if(level == 0) {
			//cerr << endl;
			return;
		}
		ll bt = ((v & (1 << (level-1))) != 0);
		//cerr << " bt " << bt << endl;
		if(nodes[bt] == nullptr) {
			nodes[bt] = new node;
			nodes[bt]->bit = bt;
			nodes[bt]->count = 0;
			nodes[bt]->level = level-1;
		}
		nodes[bt]->insert(v);
	}
	ll takeMin(ll goal) {
		//cerr << level << "\twe wanted " << (((1 << (level)) & goal) != 0) << ", got " << (int) bit << endl;
		if(level == 0) {
			--count;
			return (ll) bit;
		}
		ll ch = (goal & (1<<(level-1))) != 0;
		if(nodes[ch] == nullptr)
			ch = !ch;
		ll res = nodes[ch]->takeMin(goal);
		if(nodes[ch]->count == 0) {
			delete nodes[ch];
			nodes[ch] = nullptr;
		}
		--count;
		return (bit == 0 ? res : (res | (1 << level)));
	}
	~node() {
		for(ll i=0;i<2;++i)
			if(nodes[i] != nullptr) delete nodes[i] ;
		delete[] nodes;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	node base;
	base.level = 31;
	base.bit = 0;
	base.count = 0;
	
	int N; cin >> N;
	vector<ll> A(N);
	for(int i=0;i<N;++i) cin >> A[i];
	vector<ll> P(N);
	for(int i=0;i<N;++i) {
		cin >> P[i];
		base.insert(P[i]);
	}
	for(int i=0;i<N;++i) {
		//cerr << bitset<30>(A[i]) << endl;
		ll best = base.takeMin(A[i]);
		cout << (best^A[i]) << " ";
	}
	cout << endl;


	return 0;
}