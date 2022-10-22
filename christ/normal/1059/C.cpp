#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, MOD = 1e9+9, BASE = 31, INF = 1e9, ED = 1e3+1;
#define all(x) (x).begin(),(x).end()
vector<int> has[20];
int main() {
	int n;
	scanf ("%d",&n);
	if (n <= 3) {
		for (int i = 1; i < n; i++) printf ("1 ");
		printf ("%d\n",n);
		return 0;
	}
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0, cur = i;
		while (cur%2==0) cur/=2, cnt++;
		has[cnt].push_back(i);
		mx = max(mx,cnt);
	}
	int cnt = 0;
	for (int take = 0; take < 20; take++) {
		if (n-cnt <= 3) {
			int go = (1 << take) * (n-cnt);
			while (++cnt < n) printf ("%d ",1 << take);
			printf ("%d",go);
			break;
		}
		for (int j : has[take]) printf ("%d ",1 << take);
		cnt += has[take].size();
	}
	printf ("\n");
    return 0;
}