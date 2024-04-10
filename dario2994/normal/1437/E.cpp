#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

template<typename A, typename B>
ostream& operator<<(ostream& out, const pair<A, B>& P) {
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec) {
	out << "[";
	for (const T& x: vec) out << x << ", ";
	out << "]";
	return out;
}

#ifdef DEBUG
	ifstream in("input.txt");
	#define cin in
#endif

const int MAXN = 1<<19;
int ff[2*MAXN];

int query(int v, int l, int r, int a, int b) {
	if (r < a or b < l) return 0;
	if (a <= l and r <= b) return ff[v];
	int m = (l+r)/2;
	return max(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}

void set_val(int pos, int x) {
	pos += MAXN;
	ff[pos] = x;
	while (pos != 1) {
		pos /= 2;
		ff[pos] = max(ff[2*pos], ff[2*pos+1]);
	}
}

int get_max(int from, int to) {
	return query(1, 0, MAXN-1, from, to);
}

int longest_increasing(const vector<int>& c) {
	int N = c.size();
	vector<int> ord(N);
	for (int i = 0; i < N; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int i, int j) {
		if (c[i] != c[j]) return c[i] > c[j];
		return i > j;
	});
	
	//~ cout << c << " " << ord << endl;
	
	int res = 0;
	for (int it: ord) {
		int ris = 1 + get_max(it+1, N-1);
		set_val(it, ris);
		res = max(res, ris);
	}
	
	//~ cout << res << endl;
	//~ exit(0);
	return res;
}

void solve() {
	int N, K;
	cin >> N >> K;
	vector<int> a(N+1);
	a[0] = -1.5e9;
	for (int i = 1; i <= N; i++) cin >> a[i];
	a.push_back(1.5e9);
	vector<int> b(K+1);
	b[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
	}
	b.push_back(N+1);
	
	N += 2, K += 2;
	for (int i = 0; i < N; i++) a[i] -= i;
	vector<bool> forbidden(N, false);
	
	for (int i = 1; i < K; i++) {
		if (a[b[i-1]] > a[b[i]]) {
			cout << -1 << "\n";
			return;
		}
		//~ cout << i << " " << prev_pos << " " << curr << endl;
		
		for (int j = b[i-1]; j <= b[i]; j++) {
			if (a[j] < a[b[i-1]] or a[j] > a[b[i]]) 
				forbidden[j] = true;
		}
	}
	vector<int> c;
	for (int i = 0; i < N; i++) if (!forbidden[i]) c.push_back(a[i]);
	cout << N - longest_increasing(c) << "\n";
}

int main() {
	solve();
}