#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;

const int MAXN = 500 + 5;

int n, m;
ld val[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(12);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> val[i];

	ld ans = 0;
	while (m--){
		int a, b, c;	cin >> a >> b >> c;	a--, b--;
		ans = max(ans, (val[a] + val[b]) / ld(c));
	}
	cout << ans << endl;
	return	0;
}