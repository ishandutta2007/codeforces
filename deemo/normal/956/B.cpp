#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, z, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> z;
	for (int i = 0; i < n; i++) cin >> a[i];
	ld ans = 0.;
	bool found = 0;
	for (int i = 0; i+2 < n; i++){
		int k = upper_bound(a, a + n, a[i]+z) - a; k--;
		if (k < i+2) continue;
		found = 1;
		ans = max(ans, ld(a[k]-a[i+1])/ ld(a[k]-a[i]));
	}
	cout << fixed << setprecision(12);
	if (!found)
		cout << "-1\n";
	else
		cout << ans << "\n";
	return 0;
}