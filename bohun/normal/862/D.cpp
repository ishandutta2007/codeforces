#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int n;

int query(string &x) {
	printf("? %s\n", x.c_str());
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

int w, q;
int z, o;

void solve(int l, int r) {
	if(l == r) {
		q = l;
		return;
	}
	int m = (l + r + 1) / 2;
	string y = "";
	for(int i = 1; i < m; ++i)
		y.pb('0' + w);
	for(int i = m; i <= r; ++i)
		y.pb('0' + 1 - w);
	for(int i = r + 1; i <= n; ++i)
		y.pb('0' + w);
	int k = query(y);
	if((w == 0 && k == z + (r - m + 1)) || (w == 1 && k == o + (r - m + 1)))
		solve(l, m - 1);
	else
		solve(m, r);
}
			
int main() {
	scanf("%d", &n);
	string zer (n, '0');
	string one (n, '0');
	one[0] = '1'; 
	z = query(zer);
	o = query(one);
	
	w = (z < o ? 0 : 1);
	
	for(int i = 0; i < n; ++i)
		one[i] = '1';
	o = query(one);
	
	solve(2, n);
	
	if(w == 0)
		printf("! %d %d\n", 1, q);
	else
		printf("! %d %d\n", q, 1);
	
	return 0;
}