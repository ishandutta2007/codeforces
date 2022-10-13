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

struct Node {
	int l, r, x, cnt;
};
Node T[10000000];
int nodes = 0;

bool value_at(int node, int b, int e, int pos) {
	if(b == e) return T[node].x;

	int m = b + e >> 1;
	if(m >= pos) {
		return T[node].x ^ value_at(T[node].l, b, m, pos);
	} else {
		return T[node].x ^ value_at(T[node].r, m + 1, e, pos);
	}
}

int GetReal(int x, int b, int e) {
	if(T[x].x == 1) return (e - b + 1) - T[x].cnt;
	return T[x].cnt;
}

int update(int x, int b, int e, int l, int r) {

	T[++nodes] = T[x];
	int node = nodes;

	if(e < l || b > r) {
		return node;
	}
	if(e <= r && b >= l)  {
		T[node].x ^= 1;
		return node;
	}

	int m = b + e >> 1;
	T[node].l = update(T[node].l, b, m, l, r);
	T[node].r = update(T[node].r, m + 1, e, l, r);

	T[node].cnt = GetReal(T[node].l, b, m) + GetReal(T[node].r, m + 1, e);
	return node;
}

int Pos[1005][1005];
int Root[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	int count_pos = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			Pos[i][j] = ++count_pos;

	int cur_root_index = 0;
	for(int qi = 1; qi <= q; ++qi) {
		int t;
		cin >> t;
		if(t == 1) {
			int i, j;
			cin >> i >> j;
			if(value_at(cur_root_index, 1, count_pos, Pos[i][j]) == 0)
			//cerr << "Updating " << i << " " << j << "...\n";
			Root[qi] = update(cur_root_index, 1, count_pos, Pos[i][j], Pos[i][j]);
			else Root[qi] = cur_root_index;
		}
		if(t == 2) {
			int i, j;
			cin >> i >> j;
			if(value_at(cur_root_index, 1, count_pos, Pos[i][j]) == 1)
			//cerr << "Updating " << i << " " << j << "...\n";
			Root[qi] = update(cur_root_index, 1, count_pos, Pos[i][j], Pos[i][j]);
			else Root[qi] = cur_root_index;
		}
		if(t == 3) {
			int i;
			cin >> i;
			Root[qi] = update(cur_root_index, 1, count_pos, Pos[i][1], Pos[i][m]);
		}
		if(t == 4) {
			int k;
			cin >> k;
			Root[qi] = Root[k];
		}

		cur_root_index = Root[qi];
		cout << GetReal(cur_root_index, 1, count_pos) << '\n';
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/