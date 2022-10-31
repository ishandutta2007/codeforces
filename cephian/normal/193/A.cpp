#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int n,m,tt=0;
string g[55];
bool vis[55][55];

bool ok(int i, int j) {
	if(i < 0 || j < 0 || i >= n || j >= m) return false;
	return g[i][j] == '#';
}

int search(int i, int j) {
	if(!ok(i,j) || vis[i][j]) return 0;
	vis[i][j] = true;
	int a = 1;
	a += search(i+1,j);
	a += search(i-1,j);
	a += search(i,j-1);
	a += search(i,j+1);
	return a;
}

bool disc(int a, int b, int c, int d) {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			vis[i][j] = false;
	vis[a][b] = true;
	int k = search(c,d);
	return k != 0 && k != tt-1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> g[i];
		for(char c : g[i])
			tt += c == '#';
	}
	if(tt <= 2) {
		cout << "-1\n";
		return 0;
	}
	int bst = 2;
	for(int i = 0; bst == 2 && i < n; ++i) {
		for(int j = 0; bst == 2 && j < m; ++j) {
			if(!ok(i,j)) continue;
			if(disc(i,j,i+1,j)) bst = 1;
			else if(disc(i,j,i-1,j)) bst = 1;
			else if(disc(i,j,i,j+1)) bst = 1;
			else if(disc(i,j,i,j-1)) bst = 1;
		}
	}
	cout << bst << "\n";
}