#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, p[200005], nh[2][200005], nx[2][200005];
int sta[200005], siz;

struct segt
{
	int tre[524288];
	void clear()
	{
		memset(tre, INF, sizeof(tre));
	}
	void modify(int id, int val)
	{
		tre[id |= 262144] = val;
		for(id >>= 1; id >= 1; id >>= 1) tre[id] = min(tre[id << 1], tre[id << 1 | 1]);
	}
	int query(int l, int r)
	{
		int ret = INF;
		for(l |= 262144, r |= 262144; l < r; l >>= 1, r >>= 1) {
			if(l & 1) ret = min(ret, tre[l ++]);
			if(!(r & 1)) ret = min(ret, tre[r --]);
		}
		if(l == r) ret = min(ret, tre[l]);
		return ret;
	}
}t;

void calc(int id)
{
	nx[id][n] = nh[id][n] = n;
	siz = 0;
	t.clear();
	for(int i = n - 1; i >= 0; i --) {
		while(siz >= 1 && p[sta[siz - 1]] < p[i]) siz --;
		nx[id][i] = siz ? sta[siz - 1] : n;
		nh[id][i] = min(nh[id][nx[id][i]], t.query(p[i] + 1, siz ? p[sta[siz - 1]] - 1 : n));
		sta[siz ++] = i;
		t.modify(p[i], i);
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &p[i]);
	calc(0);
	rep(i, n) p[i] = n + 1 - p[i];
	calc(1);
	
	int r = n;
	LL ans = 0;
	for(int i = n - 1; i >= 0; i --) {
		int tp = nh[0][i] > nh[1][i];
		r = min(r, nh[!tp][i]);
		r = min(r, max(nh[tp][i], nh[tp][nx[!tp][i]]));
		ans += r - i;
	}
	printf("%lld\n", ans);
	return 0;
}