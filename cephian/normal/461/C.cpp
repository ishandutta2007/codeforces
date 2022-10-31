#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//point update, range query, 0-indexed
template <class T>
struct bit {
	vector<T> b;
	void init(int n){b.resize(n+1);}
	bit(){}
	bit(int n){init(n);}
	inline void update(int i, T v) {
		for(++i; i<b.size(); i+=i&-i)
			b[i] += v;
	}
	//sum of the first i values
	int prefix(int i) const {
		T a = 0;
		for(; i; i^=i&-i)
			a += b[i];
		return a;
	}
	inline int query(int l, int r) const {
		return prefix(r+1)-prefix(l);
	}
};

bit<ll> B;

const int N = 1e5+5;

///
int l, r, width = 0;
bool flip = false;

//0-indexed inclusuve query
int query(int i, int j) {
	if(flip) return B.query(r-j+1, r-i);
	return B.query(l+i, l+j-1);
}

ll a[N];

int get_elem(int i) {
	if(flip) return a[r-i];
	return a[l+i];
}

void fold_left(int p) {
	for(int i = 0; i < p; ++i) {
		B.update(l+p+i, a[l+p-i-1]);
		a[l+p+i] += a[l+p-i-1];
	}
	l = l+p;
}

void fold_right(int p) {
	for(int i = 0; i < r+1-l-p; ++i) {
		B.update(l+p-i-1, a[l+p+i]);
		a[l+p-i-1] += a[l+p+i];
	}
	r = l+p-1;
}

inline void reverse() {
	flip ^= true;
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, q;
	cin >> n >> q;
	fill(a, a+N, 1);
	B = bit<ll>(n);
	for(int i = 0; i < n; ++i)
		B.update(i, 1);
	l = 0, r = n-1, width = n;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			int p;
			cin >> p;
			if(p <= (r-l)/2) {
				if(flip) {
					fold_right(r-l+1-p);
				} else {
					fold_left(p);
				}
			} else {
				if(flip) {
					fold_left(r-l+1-p);
					reverse();
				} else {
					fold_right(p);
					reverse();
				}
			}
		} else {
			int i, j;
			cin >> i >> j;
			cout << query(i, j) << "\n";
		}
	}
}