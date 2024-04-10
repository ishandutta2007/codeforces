/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

const int kMaxN = 500000;

int Count[kMaxN], Parent[kMaxN], Depth[kMaxN];
vector<int> Leaves[kMaxN];
int Sons[kMaxN], CountCount[kMaxN];
vector<int> G[kMaxN];

int kk;

void DFS(int node, int d) {
	CountCount[d] -= 1;
	for(auto vec : G[node])
		DFS(vec, d + 1);
}

void Assert(int n, int t, int k) {
	for(int i = 2; i <= n; ++i) {
		G[Parent[i]].push_back(i);
	}

	DFS(1, 0);

	int lv = 0;
	for(int i = 1; i <= n; ++i) {
		assert(CountCount[i] == 0);
		lv += G[i].empty();
	}

	assert(lv == kk);
}

void PruneShit(int n, int t, int k) {
	for(int i = 1; i <= n; ++i)
		Sons[Parent[i]] += 1;

	queue<int> Q;
	for(int i = 1; i <= t; ++i)
		for(auto x : Leaves[i])
			Q.push(x);

	while(!Q.empty() && k > 0) {
		auto top = Q.front();
		Q.pop();


		if(--Sons[Parent[top]] == 0) {
			--k;
			Q.push(Parent[top]);
		}
		Parent[top] = Depth[top];
	}

	if(k > 0) {
		cout << -1 << endl;
		return;
	} else {
		Assert(n, t, k);
		cout << n << endl;
		for(int i = 2; i <= n; ++i) {
			cout << i << " " << Parent[i] << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// Comment these lines before submitting
// ?	freopen("input", "r", stdin);	freopen("output", "w", stdout);

	// Start code here

	int n, t, k;
	cin >> n >> t >> k;
	kk = k;

	for(int i = 1; i <= t; ++i) {
		cin >> Count[i];
		CountCount[i] = Count[i];
	}

	for(int i = 2; i <= t + 1; ++i) {
		Parent[i] = i - 1;
		Depth[i] = i - 1;
		if(Count[i - 1] == 0) {
			cout << -1 << endl;
			return 0;
		}
		Count[i - 1] -= 1;
	}

	k -= 1;

	vector<int> Rem;
	
	cerr << "OK" << endl;

	int d = 1;
	for(int i = t + 2; i <= n; ++i) {
		while(Count[d] == 0) ++d;
		Depth[i] = d;
		Count[d] -= 1;

		// cerr << i << ": " << d << endl;

		if(Leaves[d - 1].size()) {
			Parent[i] = Leaves[d - 1].back();
			Leaves[d - 1].pop_back();
		} else {
			k -= 1;
			Parent[i] = d;
		}

		assert(Depth[Parent[i]] == Depth[i] - 1);
		Leaves[d].push_back(i);
	}

	if(k < 0) {
		cout << -1 << endl;
		return 0;
	} else {
		cerr << "PRUNE" << endl;
		PruneShit(n, t, k);
	}


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/