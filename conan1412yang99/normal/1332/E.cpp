#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, M = 998244353;

int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b/2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

struct Mat{
	int a[2][2], n, m;
	Mat(int _n, int _m) {
		n = _n, m = _m;
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}
	Mat operator * (const Mat t) const {
		Mat ret(n, t.m);
		for(int i=0;i<n;i++)
			for(int j=0;j<t.m;j++) 
				for(int k=0;k<m;k++) {
					ret.a[i][j] = (ret.a[i][j] + a[i][k] * t.a[k][j] % M) % M;
				}
				
		return ret;
	}

};

Mat qpow(Mat a, int b) {
	if(b == 0) {
		Mat ret(2, 2);
		ret.a[0][0] = ret.a[1][1] = 1;
		return ret;
	}
	Mat t = qpow(a, b/2);
	t = t * t;
	if(b & 1) return t * a;
	else return t;
}

signed main()
{
	IO_OP;
	
	int n, m, l, r;
	cin >> n >> m >> l >> r;
	if((n * m) & 1) cout << qpow((r-l+1) % M, n * m) << endl;
	else {
		int ans = qpow((r-l+1) % M, n * m);
		int a = r / 2 - (l-1) / 2, b = r - l + 1 - a;
		Mat A(2, 2);
		A.a[0][0] = a, A.a[0][1] = b;
		A.a[1][0] = b, A.a[1][1] = a;
		int sz = n * m;
		Mat vec(2, 1);
		vec.a[0][0] = a, vec.a[1][0] = b;
		A = qpow(A, sz - 1);
		vec = A * vec;
		ans -= vec.a[1][0];
		ans = (ans + M) % M;
		cout << ans << endl;
	}
}