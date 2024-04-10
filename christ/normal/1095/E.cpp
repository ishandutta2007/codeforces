#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 1e6+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char s[MN];
int pre[MN];
int bad[MN];
int mn[MN];
int main() {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	bad[0] = INT_MAX;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i-1] + (s[i] == '(' ? 1 : -1);
		bad[i] = min(bad[i-1],pre[i]);
	}
	mn[n+1] = INT_MAX;
	for (int i = n; i >= 1; i--) {
		mn[i] = min(mn[i+1],pre[i]);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (bad[i-1] < 0) break;
		if ((s[i] == '(' && pre[n] == 2 && mn[i] >= 2) || (s[i] == ')' && pre[n] == -2 && mn[i] >= -2)) {
			++ret;
		}
	}
	printf ("%d\n",ret);
    return 0;
}