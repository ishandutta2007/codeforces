#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 25;

int n, m, Q, x;
string s[N], t[N];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	fo(i, 1, n) cin >> s[i];
	fo(i, 1, m) cin >> t[i];
	for(scanf("%d", &Q); Q; Q --) {
		scanf("%d", &x);
		int p = (x - 1) % n + 1, q = (x - 1) % m + 1;
		string g = s[p] + t[q];
		cout << g << endl;
	}
}