#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e5+3, MOD = 1e9+7;
const double EPS = 1e-15;
char grid[102][102];
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++) scanf ("%s",grid[i]);
	vector<int> a(n);
	for (auto &au : a) scanf ("%d",&au);
	vector<int> ans;
	while (1) {
		bool ok = 1;
		for (int i = 0; i < n; i++) ok &= a[i] != 0;
		if (ok) break;
		for (int i = 0; i < n; i++) if (a[i] == 0) {
			ans.push_back(i+1);
			for (int j = 0; j < n; j++) if (grid[i][j] == '1') --a[j];
		}
	}
	printf ("%d\n",ans.size());
	for (int i : ans) printf ("%d ",i);
	printf ("\n");
    return 0;
}