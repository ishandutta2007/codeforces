#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef long double ld;

int m,n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	ld ans = 0;
	for(int i = 1; i <= m; ++i) {
		ld A = ld(i)/m;
		ld B = ld(i-1)/m;
		ans += i*(powl(A,n)-powl(B,n));
	}
	cout << setprecision(12) << fixed << ans << "\n";
	return 0;
}