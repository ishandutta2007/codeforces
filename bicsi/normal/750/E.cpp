#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"

string need = "2017#";
string big;

typedef int table[5][5];

table DP[2000000];

void combine(int a, int b, int to) {
	static table A, B;
	memcpy(A, DP[a], sizeof(A));
	memcpy(B, DP[b], sizeof(B));
	memset(DP[to], -1, sizeof(DP[to]));

	for(int i = 0; i < 5; ++i)
	for(int j = i; j < 5; ++j)
	for(int k = j; k < 5; ++k) {
		if(A[i][j] != -1 && B[j][k] != -1) {
			int now = A[i][j] + B[j][k];
			if(DP[to][i][k] == -1 || DP[to][i][k] > now)
				DP[to][i][k] = now;
		}
	}
}

void build_tree(int node, int b, int e) {
	if(b == e) {
		memset(DP[node], -1, sizeof(DP[node]));
		for(int i = 0; i < 5; ++i) {
			if(big[b] == need[i]) {
				DP[node][i][i] = 1;
				DP[node][i][i + 1] = 0;
			} else {
				DP[node][i][i] = (i >= 3 && big[b] == '6');
			}
		}
	} else {
		int m = (b + e) / 2;
		build_tree(node * 2, b, m);
		build_tree(node * 2 + 1, m + 1, e);
		combine(node * 2, node * 2 + 1, node);
	}
}
void query_tree(int node, int b, int e, int l, int r) {
	if(b > r || e < l) return;
	if(b >= l && e <= r) 
		return combine(0, node, 0);
	int m = (b + e) / 2;
	query_tree(node * 2, b, m, l, r);
	query_tree(node * 2 + 1, m + 1, e, l, r);
}

void dump(table t) {
	for(int i = 0; i < 4; ++i)
		for(int j = i; j < 5; ++j) {
			cerr << i << " " << j << ": " << t[i][j] << endl;
		}
	cerr << endl << endl;
}

void dump_tree(int node, int b, int e) {
	cerr << "Dumping: " << node << "[" << b << " " << e << "]...\n";
	dump(DP[node]);

	if(b == e) return;
	int m = (b + e) / 2;
	dump_tree(node * 2, b, m);
	dump_tree(node * 2 + 1, m + 1, e);
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n, q;
	cin >> n >> q >> big;
	build_tree(1, 0, n - 1);

	//dump(DP[1]);
	//dump_tree(1, 0, n - 1);

	while(q--) {
		int a, b;
		cin >> a >> b;

		memset(DP[0], -1, sizeof(DP[0]));
		for(int i = 0; i < 5; ++i) DP[0][i][i] = 0;

		query_tree(1, 0, n - 1, a - 1, b - 1);

		// /dump(DP[0]);

		cout << DP[0][0][4] << '\n';
	}


	return 0;
}