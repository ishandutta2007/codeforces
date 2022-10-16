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

const int INF = 1e9 + 7;

char a[1003][1003], b[1003][1003];

signed main()
{
	IO_OP;
	memset(b ,'.', sizeof b);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	for(int i=0;i<n-2;i++)
		for(int j=0;j<m-2;j++) {
			V<pi> v;
			v.EB(i, j);
			v.EB(i+1, j);
			v.EB(i+2, j);
			v.EB(i, j+1);
			v.EB(i+2, j+1);
			v.EB(i, j+2);
			v.EB(i+1, j+2);
			v.EB(i+2, j+2);
			bool ok = true;
			for(pi p:v) {
				if(a[p.F][p.S] == '.')
					ok = false;
			}
			if(ok) {
				for(pi p:v)
					b[p.F][p.S] = '#';
			}
		}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j] != b[i][j]) {
				return cout << "NO" << endl, 0;
			}
		}
	}
	
	cout << "YES" << endl;
}