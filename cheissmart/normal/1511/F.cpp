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
typedef V<vi> Mat;

void DBG() { cerr << "]" << endl; }
template<class H, class...T> void DBG(H h, T ...t) {
	cerr << to_string(h);
	if(sizeof ...(t)) cerr << ", ";
	DBG(t...);
}
#ifdef CHEISSMART
#define debug(...) cerr << "Line(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define debug(...)
#endif

const int INF = 1e9 + 7, M = 998244353, N = 45;

void add(int& a, int b) {
	a += b;
	if(a >= M) a -= M;
}

Mat mul(Mat A, Mat B) {
	Mat C(A.size(), vi(B[0].size()));
	assert(A[0].size() == B.size());
	for(int i = 0; i < int(A.size()); i++) 
		for(int j = 0; j < int(B[0].size()); j++)
			for(int k = 0; k < int(B.size()); k++)
				add(C[i][j], (ll) A[i][k] * B[k][j] % M);
	return C;
}

Mat qpow(Mat A, int b) {
	if(b == 0) {
		Mat I(A.size(), vi(A.size()));
		for(int i = 0; i < int(I.size()); i++)
			I[i][i] = 1;
		return I;
	}
	Mat t = qpow(A, b / 2);
	t = mul(t, t);
	if(b & 1) return mul(t, A);
	else return t;
}

int t[N][26], cnt, isend[N];

void add(string& s) {
	int u = 0;
	for(char c:s) {
		int cc = c - 'a';
		if(!t[u][cc]) t[u][cc] = ++cnt;
		u = t[u][cc];
	}
	isend[u] = 1;
}

int vis[N][N];
int trans[N][N][N][N], pos[N][N];

signed main()
{
	IO_OP;

	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		add(s);
	}

	V<pi> q;
	vis[0][0] = 1;
	q.EB(0, 0);
	for(int i = 0; i < int(q.size()); i++) {
		pi p = q[i];
		int u = p.F, v = p.S;
		pos[u][v] = i;
		for(int c = 0; c < 26; c++) {
			int uu = t[u][c], vv = t[v][c];
			if(uu == 0 || vv == 0) continue;
			vi us({uu}), vs({vv});
			if(isend[uu]) us.PB(0);
			if(isend[vv]) vs.PB(0);
			for(int uuu:us) for(int vvv:vs) {
				trans[u][v][uuu][vvv]++;
				if(vis[uuu][vvv] == 0) {
					vis[uuu][vvv] = 1;
					q.EB(uuu, vvv);
				}
			}
		}
	}
	V<vi> A(q.size(), vi(q.size()));
	for(int i = 0; i < int(q.size()); i++) {
		int u = q[i].F, v = q[i].S;
		for(int uu = 0; uu <= cnt; uu++)
			for(int vv = 0; vv <= cnt; vv++)
				if(vis[uu][vv])
					A[i][pos[uu][vv]] = trans[u][v][uu][vv];
	}
	V<vi> v(q.size(), vi(1));
	v[0][0] = 1;

	A = qpow(A, m);
	v = mul(A, v);
	cout << v[0][0] << '\n';

}