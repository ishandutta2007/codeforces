#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 3e5+2, MOD = 1e9+7;
#define all(x) (x).begin(),(x).end()
int main() {
    int t;
	scanf ("%d",&t);
	while (t--) {
		int n;
		scanf ("%d",&n);
		vector<int> a(n);
		for (auto &au : a) scanf ("%d",&au);
		for (int i = 1; i < n; i++) if (abs(a[i]-a[i-1]) > 1) {
			printf ("YES\n%d %d\n",i,i+1);
			goto succ;
		}
		printf ("NO\n");
		succ:;
	}
    return 0;
}