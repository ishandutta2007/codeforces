#include <bits/stdc++.h>
#define db long double
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex{
	int minimum;
	int right_piece;
	int left_piece;
	ll sum;
	int p;
	int right_maximum_appear;
	int left_maximum_appear;
	int size;
	int maximum;
};

vector<Vertex> rmq;
const int K = 200000;
set<int> sets[K];
vector<int> v;

Vertex unite(int i, Vertex &a, Vertex &b){
	if (a.minimum < b.minimum){
		int delta = max(a.right_piece, b.maximum) - a.right_piece;
		rmq[i] = {a.minimum, a.right_piece+delta, a.left_piece, a.sum+delta, 0, max(a.right_piece, b.maximum), a.left_maximum_appear, a.size+b.size, max(a.maximum, b.maximum)};
	}
	else if (a.minimum > b.minimum){
		int delta = max(a.maximum, b.left_piece) - b.left_piece;
		rmq[i] = {b.minimum, b.right_piece, b.left_piece+delta, b.sum+delta, 0, b.right_maximum_appear, max(b.left_piece, a.maximum), a.size + b.size, max(a.maximum, b.maximum)};
	}
	else{
		int lost = a.right_maximum_appear + b.left_maximum_appear - max(a.right_maximum_appear, b.left_maximum_appear);
		rmq[i] = {a.minimum, b.right_piece, a.left_piece, a.sum+b.sum-lost, 0, b.right_maximum_appear, a.left_maximum_appear, a.size+b.size, max(a.maximum, b.maximum)};
	}
}

void build(int i, int l, int r){
	if (r-l==1){
		Vertex Q = {0, 0, 0, 0, 0, 0, 0, 1, 0};
		rmq[i] = Q;
		return;
	}
	int mid = (l+r)/2;
	build(2*i+1, l, mid);
	build(2*i+2, mid, r);
	unite(i, rmq[2*i+1], rmq[2*i+2]);
}

int n,q;

void push(int i, int l, int r){
	if (r-l <= 1) return;
	int P = rmq[i].p;
	rmq[i].p=0;
	if (P==0) return;
	rmq[2*i+1].p += P, rmq[2*i+2].p += P, rmq[2*i+1].minimum += P, rmq[2*i+2].minimum += P;
}

void change_maximum(int i, int l, int r, int index, int val){
	push(i, l, r);
	if (r-l==1){
		rmq[i] = {rmq[i].minimum, 0, val, val, 0, 0, val, 1, val};
		return;
	}
	int mid = (l+r)/2;
	if (index < mid) change_maximum(2*i+1, l, mid, index, val);
	else change_maximum(2*i+2, mid, r, index, val);
	unite(i, rmq[2*i+1], rmq[2*i+2]);
}

void change(int i, int l, int r, int l1, int r1, int val){
	push(i, l, r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1){
		rmq[i].minimum += val, rmq[i].p += val;
		return;
	}
	int mid = (l+r)/2;
	change(2*i+1, l, mid, l1, min(r1, mid), val);
	change(2*i+2, mid, r, max(l1, mid), r1, val);
	unite(i, rmq[2*i+1], rmq[2*i+2]);
}

void add(set<int> &x){
	if (!x.size()) return;
	int L = (*x.begin());
	auto it = x.end();
	it--;
	int R = (*it);
	change_maximum(0, 0, n, L, x.size());
	change(0, 0, n, L, R, 1);
}


main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("J_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	v.assign(n, -1);
	for (int i=0;i<n;++i) cin >> v[i];
	for (int i=0;i<n;++i) v[i]--;
	for (int i=0; i < n; ++i) sets[v[i]].insert(i);
	rmq.assign(4*n, {});
	build(0, 0, n);
	for (int i=0;i<K;++i){
		add(sets[i]);
	}
	cout << n-rmq[0].sum << "\n";
}