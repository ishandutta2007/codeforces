#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005];
priority_queue<LL> que;
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	reverse(a, a + n);
	LL s = 0;
	rep(i, n) s += a[i];
	que.push(s);
	int pos = 0;
	while(!que.empty()) {
		s = que.top(); que.pop();
		if(pos + que.size() >= n) {
			printf("NO\n");
			while(!que.empty()) que.pop();
			return;
		}
		if(s == a[pos]) pos ++;
		else {
			que.push(s / 2); que.push((s + 1) / 2);
		}
	}
	printf(pos == n ? "YES\n" : "NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}