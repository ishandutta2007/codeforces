#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

double d[101][101][101], t[101][101][101];

double dp (int a, int b, int c) {
	double ans = 0;
	if (t[a][b][c]) return d[a][b][c];
	if (a == 0) return 0;
	if (b == 0 && c == 0) return 1;
	double combo = a*b+b*c+a*c;
	if (b != 0) ans += a*b*dp(a,b-1,c);
	if (c != 0) ans += b*c*dp(a,b,c-1);
	ans += a*c*dp(a-1,b,c);
	ans /= combo;
	t[a][b][c] = 1;
	d[a][b][c] = ans;
	return ans;
}

int main() {
	int r,s,p;
	cin >> r >> s >> p;
	cout << fixed << setprecision(15) << dp(r,s,p) << " " << dp(s,p,r) << " " << dp(p,r,s);
	return 0;
}