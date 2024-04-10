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
#define a c
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

char c[66][66];

void solve() {
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++) {
			cin >> c[i][j];
			if(c[i][j] == 'A') cnt++;
		}
	if(cnt == 0) {
		cout << "MORTAL" << endl;
		return;
	}
	if(cnt == n*m) {
		cout << 0 << endl;
		return;
	}
	{
		bool ok = true;
		for(int i=0;i<n;i++) {
			if(c[i][0] != 'A') ok = false;
		}
		if(ok) {
			cout << 1 << endl;
			return;
		}
	}
	{
		bool ok = true;
		for(int i=0;i<n;i++) {
			if(c[i][m-1] != 'A') ok = false;
		}
		if(ok) {
			cout << 1 << endl;
			return;
		}
	}
	{
		bool ok = true;
		for(int i=0;i<m;i++) {
			if(c[0][i] != 'A') ok = false;
		}
		if(ok) {
			cout << 1 << endl;
			return;
		}
	}
	{
		bool ok = true;
		for(int i=0;i<m;i++) {
			if(c[n-1][i] != 'A') ok = false;
		}
		if(ok) {
			cout << 1 << endl;
			return;
		}
	}
	if(c[0][0] == 'A' || c[0][m-1] == 'A' || c[n-1][0] == 'A' || c[n-1][m-1] == 'A') {
		cout << 2 << endl;
		return;
	}
	for(int i=0;i<n;i++) {
		bool ok = true;
		for(int j=0;j<m;j++) {
			if(c[i][j] != 'A') ok = false;
		}
		if(ok) {
			cout << 2 << endl;
			return;
		}
	}
	for(int i=0;i<m;i++) {
		bool ok = true;
		for(int j=0;j<n;j++) {
			if(c[j][i] != 'A') ok = false;
		}
		if(ok) {
			cout << 2 << endl;
			return;
		}
	}
	for(int i=0;i<n;i++)
		if(a[i][0] == 'A') {
			cout << 3 << endl;
			return;
		}
	for(int i=0;i<n;i++)
		if(a[i][m-1] == 'A') {
			cout << 3 << endl;
			return;
		}

	for(int i=0;i<m;i++)
		if(a[0][i] == 'A') {
			cout << 3 << endl;
			return;
		}
	for(int i=0;i<m;i++)
		if(a[n-1][i] == 'A') {
			cout << 3 << endl;
			return;
		}
	cout << 4 << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}