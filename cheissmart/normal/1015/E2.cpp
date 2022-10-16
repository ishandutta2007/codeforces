#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 1024;

char c[N][N];
int l[N][N], r[N][N], u[N][N], d[N][N], row[N][N], col[N][N];

int main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> (c[i]+1);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++) 
			if(c[i][j] == '*')
				l[i][j] = l[i][j-1]+1;
	for(int i=1;i<=n;i++) 
		for(int j=m;j>=1;j--) 
			if(c[i][j] == '*')
				r[i][j] = r[i][j+1]+1;
	
	for(int j=1;j<=m;j++) 
		for(int i=1;i<=n;i++) 
			if(c[i][j] == '*')
				u[i][j] = u[i-1][j]+1;
	for(int j=1;j<=m;j++) 
		for(int i=n;i>=1;i--) 
			if(c[i][j] == '*')
				d[i][j] = d[i+1][j]+1;
	vector<pair<pi, int>> v;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int mn = min(min(l[i][j], r[i][j]), min(u[i][j], d[i][j]));
			if(mn < 2) continue;
			v.PB({{i, j}, mn-1});
			row[i][j-mn+1]++;
			row[i][j+mn]--;
			col[i-mn+1][j]++;
			col[i+mn][j]--;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			row[i][j] += row[i][j-1];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			col[i][j] += col[i-1][j];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			char x = (row[i][j] || col[i][j]) ? '*' : '.';
			if (x != c[i][j]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << v.size() << endl;
	for(auto p:v)
		cout << p.F.F << " " << p.F.S << " " << p.S << endl;
}