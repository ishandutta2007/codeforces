#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

ld p[101][100005];
int n,m,x,s=0;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	if(m == 1) {
		cout << 1 << "\n";
		return 0;
	}
	p[0][0] = 1;
	ld C = ld(1)/(m-1);
	for(int i = 1; i <= n; ++i) {
		fill(p[i],p[i] + i*m+1,0);
		cin >> x;
		s+=x;
		for(int j = (i-1)*m; j >= 0; --j) {
			p[i][j+1] += C*p[i-1][j];
			p[i][j+m+1] -= C*p[i-1][j];
		}
		for(int j = 1; j <= i*m; ++j)
			p[i][j] += p[i][j-1];
		for(int j = (i-1)*m; j >= 0; --j) {
			p[i][j+x] -= C*p[i-1][j];
		}
	}
	ld a = 0;
	for(int i = 0; i < s; ++i)
		a += (m-1)*p[n][i];
	cout << setprecision(12) << fixed << 1+a << "\n";
	return 0;
}