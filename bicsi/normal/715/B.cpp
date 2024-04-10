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

int n, m, s, t;
int A[kMaxN], B[kMaxN];
long long C[kMaxN];
vector<int> G[kMaxN];
vector<int> Empty;

long long D[kMaxN];
long long l;

long long Dijkstra() {
	for(int i = 0; i < n; ++i)
		D[i] = 1e18;

	priority_queue<pair<long long, int>> Q;

	D[s] = 0;
	Q.emplace(0, s);

	while(!Q.empty()) {
		auto top = Q.top();
		Q.pop();

		if(D[top.second] != -top.first) continue;

		int node = top.second;
		for(auto ei : G[node]) {
			int vec = A[ei] ^ B[ei] ^ node;

			if(D[vec] > D[node] + C[ei]) {
				D[vec] = D[node] + C[ei];
				Q.emplace(-D[vec], vec);
			}
		}
	}

	return D[t];
}

long long Good(int use) {
	for(int i = 0; i < use; ++i)
		C[Empty[i]] = 1e18;

	long long ret = Dijkstra();

	for(int i = 0; i < use; ++i)
		C[Empty[i]] = 1;

	return ret;
}

void Output() {
	cout << "YES\n";
	assert(Dijkstra() == l);
	for(int i = 1; i <= m; ++i) {
		cout << A[i] << " " << B[i] << " " << C[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> l >> s >> t;

	for(int i = 1; i <= m; ++i) {
		cin >> A[i] >> B[i] >> C[i];
		G[A[i]].push_back(i);
		G[B[i]].push_back(i);

		if(C[i] == 0) {
			C[i] = 1;
			Empty.push_back(i);
		}
	}

	long long low = Good(0), high = Good(Empty.size());

	if(low == l) {
		Output();
		return 0;
	}

	if(low > l || high < l) {
		cout << "NO\n";
		return 0;
	}

	int ans = 0;
	for(int i = (1 << 16); i; i /= 2) {
		if(ans + i <= Empty.size() && Good(ans + i) < l)
			ans += i;
	}

	assert(ans < Empty.size());

	long long delta = l - Good(ans);
	assert(delta > 0);

	for(int i = 0; i < ans; ++i) C[Empty[i]] = 1e18;
	C[Empty[ans]] = delta + 1;
	Output();
	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/