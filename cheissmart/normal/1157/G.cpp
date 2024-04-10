#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int in[202][202], a[202][202], p[202], n, m;
string t;

bool issort(int i) {
	for(int j=2;j<=m;j++)
		if(a[i][j] < a[i][j-1])
			return false;
	return true;
}

bool isinsort(int i) {
	for(int j=2;j<=m;j++)
		if(a[i][j] > a[i][j-1])
			return false;
	return true;
}

bool ok() {
	string s;
	for(int i=1;i<=n;i++) {
		p[i] = 0;
		for(int j=1;j<=m;j++)
			p[i] += a[i][j];
	}
	int i;
	for(i=1;i<=n;i++) {
		if(p[i] == 0) s += '0';
		else if(p[i] == m) s += '1';
		else break;
	}
	if(i <= n) {
		if(issort(i)) s += '0';
		else if(isinsort(i)) s += '1';
		else return false;
		for(i=i+1;i<=n;i++) {
			if(p[i] == 0) s += '1';
			else if(p[i] == m) s += '0';
			else return false;
		}
	}
	cout << "YES" << endl;
	cout << s << endl << t << endl;
	return true;
}

int main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin >> in[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j] = in[i][j];
	t = "";
	for(int i=1;i<=m;i++) {
		if(a[1][i]) {
			t += '1';
			for(int j=1;j<=n;j++) 
				a[j][i] ^= 1;
		} else {
			t += '0';
		}
	}
	if(ok()) return 0;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j] = in[i][j];
	t = "";
	for(int i=1;i<=m;i++) {
		if(a[n][i]) {
			t += '1';
			for(int j=1;j<=n;j++) 
				a[j][i] ^= 1;
		} else {
			t += '0';
		}
	}
	if(ok()) return 0;
	
	cout << "NO" << endl;
}