#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
 
struct seg {
	int overall, tleft, tright, len;
};

const int N = 3e5+5;
seg segt[4*N];
ll diff[N] = {};
int n, m;
 
inline int max(int a, int b, int c, int d) {
	return max(max(a,b), max(c,d));
}
 
seg combine(const seg& L, const seg& R, int m) {
	seg Z;
	Z.len = L.len + R.len;
 
	Z.tleft = L.tleft;
	if(L.tleft == L.len) {
		if(diff[m] > 0 || diff[m+1] < 0)
			Z.tleft = L.len + R.tleft;
	}
 
	Z.tright = R.tright;
	if(R.tright == R.len) {
		if(diff[m] > 0 || diff[m+1] < 0)
			Z.tright = R.len + L.tright;
	}
 
	Z.overall = max(L.overall, R.overall);
	if(diff[m] > 0 || diff[m+1] < 0)
		Z.overall = max(Z.overall, L.tright + R.tleft);
 
	return Z;
}
 
void single(int v, int val, int i) {
	segt[v].len = 1;
	diff[i] += val;
	segt[v].tleft = segt[v].tright = segt[v].overall = diff[i] != 0;
}
 
void init(int i, int j, int v = 1) {
	if(i == j) {
		single(v, 0, i);
	} else {
		init(i, (i+j)/2, v*2);
		init((i+j)/2+1, j, v*2+1);
		segt[v] = combine(segt[v*2], segt[v*2+1], (i+j)/2);
	}
}
 
void update(int i, int val, int l, int r, int v = 1) {
	if(l == r) {
		single(v, val, i);
	} else {
		int md = (l + r)/2;
		if(i <= md) update(i, val, l, (l+r)/2, v*2);
		else update(i, val, (l+r)/2+1, r, v*2+1);
		segt[v] = combine(segt[v*2], segt[v*2+1], md);
	}
}

void pr(int v, int l, int r) {
	//cout << ">>> " << l << ", " << r << ":" << endl;
	//cout << segt[v].overall << " " << segt[v].tleft << " " << segt[v].tright << endl;
	if(l == r) return;
	int m = (l+r)/2;
	pr(v*2, l, m);
	pr(v*2+1, m+1, r);
}
 
int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> diff[i];
	}
	for(int i = 0; i < n-1; ++i) {
		diff[i] = diff[i+1] - diff[i];
	}
	cin >> m;
	if(n == 1) {
		for(int i = 0; i < m; ++i)
			cout << "1\n";
		return 0;
	}
	init(0, n-2);
	for(int i = 0; i < m; ++i) {
		int l, r, d;
		cin >> l >> r >> d;
		--l, --r;
		if(l != 0) update(l-1, d, 0, n-2);
		if(r != n-1) update(r, -d, 0, n-2);
		cout << segt[1].overall+1 << '\n';
	}
	//for(int i = 0; i < n-1; ++i)
	//	cout << diff[i] << ' ';
	//cout << endl;
	//pr(1, 0, n-2);
	
}