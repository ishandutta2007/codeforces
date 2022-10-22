#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 2e3 + 10;
const int MAXVAL = 5e3 + 10;

int n, a[MAXN];
ld p[3 * MAXVAL + 5], par[3 * MAXVAL + 5];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	sort(a, a + n);

	ld pp = ld(1) / ld(n * (n - 1)/ 2);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			p[a[i] - a[j]] += pp;

	for (int i = 1; i < 3 * MAXVAL; i++)
		par[i] = par[i - 1] + p[i];
	
	ld ans = 0;
	cout << fixed << setprecision(12);
	for (int i = 1; i < MAXVAL; i++)
		for (int j = 1; j < MAXVAL; j++){
			pp = p[i] * p[j];
			int dif = i + j;
			ans += pp * (par[3 * MAXVAL - 1] - par[dif]);	
		}
	cout << ans << "\n";
	return	0;
}