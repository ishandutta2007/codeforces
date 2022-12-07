#include <bits/stdc++.h>
using namespace std;

const int M = 25;
array<long long, M> ID;

array<long long, M> f(array<long long, M> &a, array<long long, M> &b) {
	array<long long, M> ans = ID;
	for(int i = 0; i < M; i++) ans[i] = a[i] + b[i];
	return ans;
}

template<typename T>
struct Tree {
	vector<T> s; int n;
	Tree(int n = 0, T def = ID) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = ID, rb = ID;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	for(int i = 0; i < M; i++) ID[i] = 0;
	unordered_map<int, int, custom_hash> mp;
	int alloc = 0;
	int n, q;
	cin >> n >> q;
	vector <int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(mp.find(v[i]) == mp.end()) {
			mp[v[i]] = alloc++;
		}
	}
	vector<vector<int>> query;
	for(int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int pos, val;
			cin >> pos >> val;
			--pos;
			query.push_back({pos, val});
			if(mp.find(val) == mp.end()) {
				mp[val] = alloc++;
			}
		} else {
			int l, r, k;
			cin >> l >> r >> k;
			--l; --r;
			query.push_back({l, r, k});
		}
	}
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vector<array<long long, M>> hash(alloc);
	for(int i = 0; i < alloc; i++) {
		for(int j = 0; j < M; j++) {
			hash[i][j] = rng();
		}
	}
	Tree<array<long long, M>> st(n);
	for(int i = 0; i < n; i++) {
		st.update(i, hash[mp[v[i]]]);
	}
	for(auto q : query) {
		if((int)q.size() == 2) {
			st.update(q[0], hash[mp[q[1]]]);
		} else {
			auto x = st.query(q[0], q[1] + 1);
			bool pos = true;
			for(int i = 0; i < M; i++) {
				if(x[i] % q[2] != 0) pos = false;
			}
			cout << (pos ? "YES" : "NO") << '\n';
		}
	}

	
	return 0;
}