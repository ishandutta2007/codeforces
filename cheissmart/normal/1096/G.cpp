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

const int INF = 1e9 + 7, M = 998244353, G = 3;


int qpow(int a, int b) {
	if(b == 0) return 1;
	int t = qpow(a, b/2);
	t = t * t % M;
	if(b & 1) return t * a % M;
	else return t;
}

int inv(int a) {
	return qpow(a, M - 2);
}
int a[2000006], pos[2000006];

void NTT(int *a, int k, bool inverse = false) {
	for(int i=1;i<(1<<k);i++) pos[i] = (pos[i>>1]>>1) | ((i&1) << (k-1));
	for(int i=0;i<(1<<k);i++) if(pos[i] < i) swap(a[i], a[pos[i]]);
	for(int len=2;len<=(1<<k);len<<=1) {
		int omega = qpow(G, (M-1)/len);
		if(inverse) omega = inv(omega);
		for(int i=0;i<(1<<k);i+=len) {
			int cur = 1;
			for(int j=i;j<i+len/2;j++) {
				int l = a[j], r = a[j+len/2];
				a[j] = (l + r * cur % M) % M;
				a[j+len/2] = (l - r * cur % M + M) % M;
				cur = cur * omega % M;
			}
		}
	}
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		a[t] = 1;
	}
	int k = __lg(2000006);
	NTT(a, k);
	for(int i=0;i<(1<<k);i++)
		a[i] = qpow(a[i], n/2);
	NTT(a, k, true);
	int invn = inv(1 << k);
	for(int i=0;i<(1<<k);i++)
		a[i] = a[i] * invn % M;
	int ans = 0;
	for(int i=0;i<(1<<k);i++)
		ans += a[i] * a[i] % M;
	cout << ans % M << endl;

	
}