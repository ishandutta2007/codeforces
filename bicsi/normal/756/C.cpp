#include <bits/stdc++.h>

using namespace std;

int T[1000000], TMin[1000000], X[1000000];

void Insert(int node, int b, int e, int pos, int op, int x) {
	if(b == e) {
		T[node] += op;
		TMin[node] = min(0, T[node]);
		X[node] = x;
	} else {
		int m = (b + e) / 2;
		if(pos <= m) Insert(node * 2, b, m, pos, op, x);
		else Insert(node * 2 + 1, m + 1, e, pos, op, x);

		T[node] = T[node * 2] + T[node * 2 + 1];
		TMin[node] = min(TMin[node * 2], T[node * 2] + TMin[node * 2 + 1]);
	}
}

int Query(int node, int b, int e, int d) {
	if(b == e) {
		if(d != 1) return -1;
		return X[node];
	} else {
		int m = (b + e) / 2;
		if(T[node * 2] + TMin[node * 2 + 1] < d)
			return Query(node * 2 + 1, m + 1, e, d - T[node * 2]);
		return Query(node * 2, b, m, d);
	}
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		int op, pos, x = -1;
		cin >> pos >> op;
		op = (op == 1) ? 1 : -1;
		if(op == 1) cin >> x;

		Insert(1, 1, n, pos, op, x);
		cout << Query(1, 1, n, T[1]) << '\n';
	}
	return 0;
}