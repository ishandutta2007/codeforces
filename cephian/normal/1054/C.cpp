#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1005;

//range update, point query, 0-indexed
template <class T>
struct bit {
	vector<T> b;
	void init(int n){b.resize(n+1);}
	bit(){}
	bit(int n){init(n);}
	inline void ud(int i, T v) {
		for(; i<(int)b.size(); i+=i&-i)
			b[i] += v;
	}
	//update [l,r] with value v
	inline void update(int l, int r, T v) {
		if(r < l ) return;
		ud(l+1,v);
		if(r+2<(int)b.size())ud(r+2,-v);
	}

	//get value at i
	inline int query(int i) const {
		T a = 0;
		for(++i; i; i^=i&-i)
			a += b[i];
		return a;
	}
};


int f[N];
bool done[N] = {};

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	
	bit<int> l(n);
	bit<int> r(n);

	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		l.update(i, i, x);
	}
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		r.update(i, i, x);
	}

	int val = n;
	while(true) {
		bool all_done = true;
		vector<int> marked;
		for(int i = 0; i < n; ++i) {
			if(done[i]) continue;
			all_done = false;
			if(l.query(i) == 0 && r.query(i) == 0) {
				done[i] = true;
				marked.push_back(i);
			}
		}
		if(all_done) break;

		if(marked.size() == 0) {
			cout << "NO\n";
			return 0;
		}
		for(int i : marked) {
			f[i] = val;
			r.update(0, i-1, -1);
			l.update(i+1, n-1, -1);
		}
		--val;
	}
	cout << "YES\n";
	for(int i = 0; i < n; ++i) {
		cout << f[i] << " ";
	}
	cout << "\n";
}