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

const int INF = 1e9 + 7, N = 100005;

int a[N], s[N];

signed main()
{
	IO_OP;

	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		cin >> a[i];
	}
	for(int i=m-1;i>=0;i--) s[i] = a[i] + s[i+1];
	if(s[0] < n) {
		cout << -1 << endl;
		return 0;
	}
	else {
		vi v;
		for(int i=0, j=0;i<n&&j<m;i++) {
			if(s[j] >= n-i) {
				if(i+a[j]-1 >= n) {
					cout << -1 << endl;
					return 0;
				}
				v.PB(i+1);
				j++;
			}
		}
		for(int e:v) cout << e << " ";
	}
	
}