#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string g[105];

vector<char> ans = {'B','G','R'};

int main() {	
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> g[i];
	//horizontal
	if(n%3 == 0) {
		vector<char> c;
		for(int k = 0; k < 3; ++k) {
			int A = k * (n / 3);
			int B = (k+1) * (n / 3);
			char last = 0;
			for(int i = A; i < B; ++i) {
				for(int j = 0; j < m; ++j) {
					if(last != 0 && g[i][j] != last)
						goto skp;
					last = g[i][j];
				}
			}
			c.pb(g[A][0]);
		}
		sort(c.begin(),c.end());
		if(c == ans) {
			cout << "YES\n";
			return 0;
		}
	}
	skp:;
	//vertical
	if(m%3 == 0) {
		vector<char> c;
		for(int k = 0; k < 3; ++k) {
			int A = k * (m / 3);
			int B = (k+1) * (m/3);
			char last = 0;
			for(int j = A; j < B; ++j) {
				for(int i = 0; i < n; ++i) {
					if(last != 0 && g[i][j] != last)
						goto sk2;
					last = g[i][j];
				}
			}
			c.pb(g[0][A]);
		}
		sort(c.begin(),c.end());
		if(c == ans) {
			cout << "YES\n";
			return 0;
		}
	}
	sk2:;
	cout << "NO\n";
}