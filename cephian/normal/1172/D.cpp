#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 1005;
int r[N];
int c[N];
int r_inv[N];
int c_inv[N];
int n, x;

void swap_perm(int i, int j, int* p, int* p_inv) {
	p_inv[p[i]] = j;
	p_inv[p[j]] = i;
	swap(p[i], p[j]);
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> r[i];
		r_inv[r[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
		c_inv[c[i]] = i;
	}
	vector<tuple<int,int,int,int>> ans;
	for(int i = 1; i <= n; ++i) {
		if(r[i] == i && c[i] == i) continue;
		ans.emplace_back(r_inv[i], i, i, c_inv[i]);
		swap_perm(r_inv[i], i, r, r_inv);
		swap_perm(c_inv[i], i, c, c_inv);
	}
	cout << ans.size() << '\n';
	for(auto x : ans) {
		int a,b,c,d;
		tie(a,b,c,d) = x;
		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
}