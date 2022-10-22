#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	vector<int> inds;
	set<int> used;
	for (int i = 1; i <= n; i++) {
		int a; scanf ("%d",&a);
		if (!used.count(a)) {
			used.insert(a);
			inds.push_back(i);
		}
	}
	if (inds.size() < k) printf ("NO\n");
	else {
		printf ("YES\n");
		for (int i = 0; i < k; i++) printf ("%d ",inds[i]);
		printf ("\n");
	}
    return 0;
}