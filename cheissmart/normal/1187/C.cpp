#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
 
const int INF = 1e9 + 7;
int nw = 1, ans[1024];
 
int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	vector<pi> a, b;
	for(int i=0;i<m;i++) {
		int t, l, r;
		cin >> t >> l >> r;
		if(t) a.EB(l, r);
		else b.EB(l, r);
	}
	sort(a.begin(), a.end());
	for(int i=0,j,l,r;i<a.size();i=j) {
		l = a[i].F, r = a[i].S, j = i+1;
		while(j<a.size() && a[j].F <= r)
			r = max(r, a[j].S), j++;
		ans[r] = l;
	}
	for(int i=n;i>=1;i--) {
		if(ans[i]) {
			int k = i;
			i = ans[i];
			for(int j=i;j<=k;j++)
				ans[j] = nw;
			nw++;
		} else {
			ans[i] = nw++;
		}
	}
	for(pi p:b) {
		int l = p.F, r = p.S;
		bool flag = 0;
		for(int i=l;i<r;i++)
			if(ans[i] > ans[i+1]) { flag = 1; break; }
		if(!flag) { cout << "NO" << endl; return 0; }
	}
	cout << "YES" << endl;
	for(int i=1;i<=n;i++)
		cout << ans[i] << " ";
}