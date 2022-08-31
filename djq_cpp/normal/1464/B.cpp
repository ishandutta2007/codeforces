#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

char s[100005];
int n, x, y;
int cnt[100005][2];
vector<int> pos;

LL ans;
int main()
{
	scanf("%s%d%d", s, &x, &y);
	n = strlen(s);
	if(x > y) {
		swap(x, y);
		rep(i, n) s[i] ^= 1;
	}
	rep(i, n) {
		if(s[i] == '0') ans += 1LL * y * cnt[i][1];
		else if(s[i] == '1') ans += 1LL * x * cnt[i][0];
		else pos.push_back(i);
		cnt[i + 1][0] = cnt[i][0] + (s[i] == '0');
		cnt[i + 1][1] = cnt[i][1] + (s[i] == '1');
	}
	
	LL ca = 0, ta;
	rep(i, pos.size()) ca += 1LL * cnt[pos[i]][1] * (y - x) + 1LL * cnt[n][1] * x;
	ta = ca;
	for(int i = (int)pos.size() - 1; i >= 0; i --) {
		ca -= 1LL * cnt[pos[i]][1] * (y - x) + 1LL * cnt[n][1] * x;
		ca += 1LL * cnt[pos[i]][0] * (x - y) + 1LL * cnt[n][0] * y;
		ta = min(ta, ca + 1LL * i * ((int)pos.size() - i) * x);
	}
	
	ans += ta;
	printf("%lld\n", ans);
	return 0;
}