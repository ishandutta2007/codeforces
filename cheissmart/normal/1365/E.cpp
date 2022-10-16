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

const int INF = 1e9 + 7, N = 505;

int a[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;	
	for(int i = 0; i < n; i++) cin >> a[i];
	ll mx = 0;
	for(int i = 0; i < n; i++) {
		mx = max(mx, a[i]);
		for(int j = i + 1; j < n; j++) {
			mx = max(mx, a[i] | a[j]);
			for(int k = j + 1; k < n; k++) {
				mx = max(mx, a[i] | a[j] | a[k]);
			}
		}
	}
	cout << mx << endl;

}