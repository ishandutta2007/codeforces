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

int r[50004], c[50004];
vi a[50004];

int main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, m;
		cin >> n >> m;
		memset(r, 0, sizeof r);
		memset(c, 0, sizeof c);
		for(int i=0;i<n;i++) {
			a[i].clear();
			a[i].resize(m);
			for(int j=0;j<m;j++) {
				char cc;
				cin >> cc;
				if(cc == '.')
					a[i][j] = 1;
				r[i] += a[i][j];
				c[j] += a[i][j];
			}
		}
		
		int mn = INF;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int re = r[i] + c[j];
				if(a[i][j]) re--;
				mn = min(mn, re);
			}
		}
		cout << mn << endl;
	}
	
}