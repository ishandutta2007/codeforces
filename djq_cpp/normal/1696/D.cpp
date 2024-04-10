#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[250005];
vector<int> hv[250005];
int sta[250005], p[4][250005], siz;
set<int> S;
void solve()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	
	siz = 0;
	rep1(i, n) {
		while(siz > 0 && a[sta[siz - 1]] < a[i]) siz --;
		p[0][i] = siz == 0 ? 0 : sta[siz - 1];
		sta[siz ++] = i;
	}
	siz = 0;
	rep1(i, n) {
		while(siz > 0 && a[sta[siz - 1]] > a[i]) siz --;
		p[1][i] = siz == 0 ? 0 : sta[siz - 1];
		sta[siz ++] = i;
	}
	siz = 0;
	for(int i = n; i >= 1; i --) {
		while(siz > 0 && a[sta[siz - 1]] < a[i]) siz --;
		p[2][i] = siz == 0 ? n + 1 : sta[siz - 1];
		sta[siz ++] = i;
	}
	siz = 0;
	for(int i = n; i >= 1; i --) {
		while(siz > 0 && a[sta[siz - 1]] > a[i]) siz --;
		p[3][i] = siz == 0 ? n + 1 : sta[siz - 1];
		sta[siz ++] = i;
	}
	
	rep1(i, n) hv[i].clear();
	rep1(i, n) {
		p[0][i] = min(p[0][i], p[1][i]) + 1;
		p[1][i] = max(p[2][i], p[3][i]) - 1;
		hv[p[0][i]].push_back(i);
	}
	S.clear();
	int pos = 1, tmp = 0, ret = 0;
	while(pos < n) {
		while(tmp < pos) {
			tmp ++;
			rep(i, hv[tmp].size()) S.insert(hv[tmp][i]);
		}
		int np = *prev(S.upper_bound(p[1][pos]));
		pos = np;
		ret ++;
	}
	printf("%d\n", ret);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}