#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 87;

int a[N], t[N], l[N], r[N];

int32_t main()
{
	IO_OP;
	
	int n, q, m;
	cin >> n >> q >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=0;i<q;i++)
		cin >> t[i] >> l[i] >> r[i];
	for(int i=0;i<m;i++) {
		int b;
		cin >> b;
		for(int j=q-1;j>=0;j--) {
			if(b > r[j] || b < l[j]) continue;
			if(t[j] == 1) {
				if(b > l[j]) b--;
				else b = r[j];
			} else {
				b = r[j] - (b - l[j]);
			}
		}
		cout << a[b] << " ";
	}
	
}