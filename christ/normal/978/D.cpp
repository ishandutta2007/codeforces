#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, BASE = 31; const ll MOD = 1000000000000037LL;
#define all(x) (x).begin(),(x).end()
int main() {
	int n;
	scanf ("%d",&n);
	vector<int> a(n), diff(n);
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		if (i) diff[i] = a[i] - a[i-1];
	}
	if (n <= 2) return !printf ("0\n");
	int ret = 1e9+1;
	for (int f = a[0]-1; f <= a[0]+1; f++) {
		for (int s = a[1]-1; s <= a[1]+1; s++) {
			vector<int> na = a;
			na[0] = f;
			na[1] = s;
			int att = abs(f-a[0]) + abs(s-a[1]), diff = s-f;
			for (int i = 2; i < n; i++) {
				int need = na[i-1] + diff;
				if (abs(na[i]-need) >= 2) goto fail;
				att += abs(na[i]-need);
				na[i] = need;
			}
			ret = min(ret,att);
			fail:;
		}
	}
	printf ("%d\n",ret>1e9?-1:ret);
    return 0;
}