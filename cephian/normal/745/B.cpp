#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
struct __test {} test;
using namespace std;
template <typename T>const __test &operator<<(const __test& d,
const T& v) {return cerr << "\033[31m" << v << "\033[0m",d;}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int g[505][505];
const int INF = 1e9;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	pii A(INF,INF),B=pii(-1,-1);
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for(int j = 0; j < m; ++j) {
			g[i][j] = s[j] == 'X';
			if(g[i][j]) {
				A.fi = min(A.fi,i);
				B.fi = max(B.fi,i);
				A.se = min(A.se,j);
				B.se = max(B.se,j);
			}
		}
	}
	// test << A.fi << "," << A.se << " " << B.fi << "," << B.se << "\n";
	for(int i = A.fi; i <= B.fi; ++i) {
		for(int j = A.se; j <= B.se; ++j) {
			if(!g[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	
	return 0;
}