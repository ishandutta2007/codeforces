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
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;
 
const int INF = 1e9 + 7, N = 1e7 + 7;
 
int lp[N], vis[N], a[N];
 
vi go(int x) {
	vi ps;
	while(x != 1) {
		ps.PB(lp[x]);
		int p = lp[x];
		while(x % p == 0) x /= p;
	}
	return ps;
}
 
signed main()
{
	IO_OP;
	
	for(int i=2;i<N;i++) {
		if(lp[i]) continue;
		lp[i] = i;
		for(ll j = (ll)i*i; j < N; j+=i) {
			lp[j] = i;
		}
	}
 	int n;
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	vi b;
	for(int i=0;i<n;i++) {
		vi ps = go(a[i]);
		bool ok = true;
		for(int p:ps) if(vis[p]) ok = false;
		if(ok) {
			for(int p:ps) vis[p] = 1;
			b.PB(a[i]);
		} else {
			for(int j=a[i]+1;j<N;j++) {
				bool ok = true;
				ps = go(j);
				for(int p:ps) if(vis[p]) ok = false;
				if(ok) {
					for(int p:ps) vis[p] = 1;
					b.PB(j);
					break;
				}
			}
			break;
		}
	}
	for(int i=2;(int)b.size() < n && i < N;i++) {
		if(lp[i]==i && !vis[i]) {
			b.PB(i);
			vis[i] = 1;
		}
	}
	for(int e:b) cout << e << " ";
	
}