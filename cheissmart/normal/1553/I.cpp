#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b?"true":"false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(V<bool> v) {
	string res;
	for(int i=0;i<(int)v.size();i++) res+=char('0'+v[i]);
	return res;
}
template<class T1, class T2> string to_string(pair<T1, T2> p) {return "(" + to_string(p.F) + ", " + to_string(p.S) + ")";}
template<size_t S> string to_string(bitset<S> b) {
	string res;
	for(int i=0;i<S;i++) res+=char('0'+b[i]);
	return res;
}
template<class T> string to_string(T v) {
    bool f=1;
    string res;
    for(auto x:v){
		if(!f) res+=' ';
		f=0; res+=to_string(x);
	}
    return res;
}

template<class T> string to_string(array<T, 2> a) {
	return "(" + to_string(a[0]) + ", " + to_string(a[1]) + ")";
}

string _reset = "\u001b[0m", _yellow = "\u001b[33m", _bold = "\u001b[1m";
void DBG() { cerr << "]" << _reset << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << _yellow << _bold << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 998244353, inv2 = (M + 1) / 2;

namespace NTT {
	/*
	  NOTE:
	    a[0], a[1], ..., a[2^k-1]
	    NTT: inverse = false
	    INTT: inverse = true
	    Dividing by 2^k after INTT is already done inside
	    Verification: https://judge.yosupo.jp/submission/54169
	*/
	const int M = 998244353, G = 3; // 998244353,1004535809,469762049 : G = 3

	int qpow(int a, int b) {
		if(b == 0) return 1;
		ll t = qpow(a, b / 2);
		t = t * t % M;
		if(b & 1) return int(t * a % M);
		else return int(t);
	}

	int inv(int n) {
		return qpow(n, M - 2);
	}

	void NTT(vi& a, int k, bool inverse = false) {
		assert(int(a.size()) <= (1 << k));
		a.resize(1 << k, 0);
		vi pos(1 << k);
		for(int i = 1; i < (1 << k); i++) pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (k - 1));
		for(int i = 0; i < (1 << k); i++) if(pos[i] < i) swap(a[pos[i]], a[i]);
		for(int len = 2; len <= (1 << k); len <<= 1) {
			int omega = qpow(G, (M - 1) / len);
			if(inverse) omega = inv(omega);
			for(int i = 0; i < (1 << k); i += len) {
				int cur = 1;
				for(int j = i; j < i + len / 2; j++) {
					int l = a[j], r = a[j + len/2];
					a[j] = int((l + 1LL * r * cur % M) % M);
					a[j + len / 2] = int((l - 1LL * r * cur % M + M) % M);
					cur = int(1LL * cur * omega % M);
				}
			}
		}
		int inv2k = inv(1 << k);
		if(inverse)
			for(int i = 0; i < (1 << k); i++)
				a[i] = int(1LL * a[i] * inv2k % M);
	}

	vi convolute(vi a, vi b) {
		int n = int(a.size()), m = int(b.size());
		int k = __lg(n + m) + 1;
		assert((1 << k) >= n + m - 1);
		NTT(a, k), NTT(b, k);
		for(int i = 0; i < (1 << k); i++)
			a[i] = int(1LL * a[i] * b[i] % M);
		NTT(a, k, true);
		return a;
	}
}

const int N = 1e5 + 7;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

void add(vi& a, vi b) {
	assert(a.size() == b.size());
	for(int i = 0; i < int(a.size()); i++)
		add(a[i], b[i]);
}

int a[N];

void Bye() {
	cout << 0 << '\n';
	exit(0);
}

typedef array<array<vi, 2>, 2> Data;

int f[N];

signed main()
{
	IO_OP;


	for(int i = f[0] = 1; i < N; i++)
		f[i] = int(1LL * f[i - 1] * i % M);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vi b;
	for(int i = 0; i < n;) {
		int x = a[i];
		int j = i + x - 1;
		while(i <= j) {
			if(i >= n || a[i] != x)
				Bye();
			i++;
		}
		b.PB(min(x, 2));
	}

	function<Data(int, int)> solve = [&] (int L, int R) -> Data {
		Data res;
		for(int l = 0; l < 2; l++) for(int r = 0; r < 2; r++)
			res[l][r] = vi(R - L);
		if(R - L == 1) {
			res[0][0][0] = b[L];
		} else if(R - L == 2) {
			res[b[L] - 1][b[L + 1] - 1][0] += b[L] * b[L + 1];
			res[1][1][1] += 2;
		} else if(R - L == 3) {
			res[b[L] - 1][b[L + 2] - 1][0] += b[L] * b[L + 1] * b[L + 2];
			res[b[L] - 1][1][1] += b[L] * 2;
			res[1][b[L + 2] - 1][1] += b[L + 2] * 2;
			res[1][1][2] += 2;			
		}
		if(R - L <= 3) return res;
		int MID = (L + R) / 2;
		Data resl = solve(L, MID), resr = solve(MID, R);
		#define FOR(i) for(int i = 0; i < 2; i++)
		FOR(left_l) FOR(left_r) FOR(right_l) FOR(right_r) {
			vi& left = resl[left_l][left_r];
			vi& right = resr[right_l][right_r];
			vi& nres = res[left_l][right_r];
			vi c = NTT::convolute(left, right);
			{ // no
				c.resize(R - L, 0);
				add(nres, c);
			}
			{ // yes
				c.insert(c.begin(), 0);
				c.resize(R - L, 0);
				if(left_r == 0 && right_l == 0)
					for(int& e:c)
						e = int(1LL * e * 2 % M);
				else if(left_r == 1 && right_l == 1)
					for(int& e:c)
						e = int(1LL * e * inv2 % M);
				add(nres, c);
			}
		}
		return res;
	};

	Data dp = solve(0, int(b.size()));
	int ans = 0;
	for(int l = 0; l < 2; l++) for(int r = 0; r < 2; r++)
		for(int i = 0; i < int(b.size()); i++) {
			int val = int(1LL * dp[l][r][i] * f[int(b.size()) - i] % M);
			if(i % 2 == 0) {
				add(ans, val);
			} else {
				add(ans, M - val);
			}
		}
	cout << ans << '\n';

}