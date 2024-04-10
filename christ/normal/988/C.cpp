#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int main() {
	int k;
	scanf ("%d",&k);
	map<int,pii> poss;
	for (int iu = 1; iu <= k; iu++) {
		int n,sum=0;
		scanf ("%d",&n); vector<int> a(n+1);
		for (int i = 1; i <= n; i++) {
			scanf ("%d",&a[i]); sum += a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (poss.count(sum-a[i]) && poss[sum-a[i]].first != iu) {
				printf ("YES\n");
				printf ("%d %d\n%d %d\n",poss[sum-a[i]].first,poss[sum-a[i]].second,iu,i);
				return 0;
			}
			poss[sum-a[i]] = {iu,i};
		}
	}
	printf ("NO\n");
    return 0;
}