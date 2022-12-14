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

char a[102][102], b[102][102];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int r, c, k, rice = 0;
		cin >> r >> c >> k;
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++){
				cin >> a[i][j];
				if(a[i][j] == 'R')
					rice++;
			}
		V<pi> v;
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(i & 1) v.EB(i, c-j-1);
				else v.EB(i, j);
			}
		}
		// int every = rice / k;
		int every1, every2, x;
		every1 = rice / k;
		every2 = every1 + 1;
		x = k - rice % k;
	
		string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
		int j = 0;
		for(int i=0;i<x;i++) {
			int cnt = 0;
			while(cnt < every1) {
				int x = v[j].F, y = v[j].S;
				j++;
				b[x][y] = s[i];
				if(a[x][y] == 'R') cnt++;
			}
		}
		for(int i=x;i<k;i++) {
			int cnt = 0;
			while(cnt < every2) {
				int x = v[j].F, y = v[j].S;
				j++;
				b[x][y] = s[i];
				if(a[x][y] == 'R') cnt++;
			}
		}
		while(j < v.size()) {
			int x = v[j].F, y = v[j].S;
			b[x][y] = s[k-1];
			j++;
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				cout << b[i][j];
			cout << '\n';
		}
	}	
	
}