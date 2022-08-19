//iterate by position: segt maintaining matrix
//iterate by value: fenwick tree maintaining premax and sufmax positions splitted by max position
 
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
 
struct segt
{
	int tre[524288][2][2];
	segt()
	{
		rep1(i, 524287) rep(j, 2) rep(k, 2) tre[i][j][k] = j != k;
	}
	void modify(int id, int tp)
	{
		id |= 262144;
		rep(i, 2) rep(j, 2) tre[id][i][j] = i != j || (tp >> i & 1);
		for(id >>= 1; id >= 1; id >>= 1) {
			rep(i, 2) rep(j, 2) tre[id][i][j] = min(tre[id << 1][i][0] + tre[id << 1 | 1][0][j],
			tre[id << 1][i][1] + tre[id << 1 | 1][1][j]);
		}
	}
	int query(int l, int r)
	{
		int tl[2] = {}, tr[2] = {}, tmp[2] = {};
		for(l |= 262144, r |= 262144; l < r; l >>= 1, r >>= 1) {
			if(l & 1) {
				rep(i, 2) tmp[i] = min(tl[0] + tre[l][0][i], tl[1] + tre[l][1][i]);
				rep(i, 2) tl[i] = tmp[i];
				l ++;
			}
			if(!(r & 1)) {
				rep(i, 2) tmp[i] = min(tr[0] + tre[r][i][0], tr[1] + tre[r][i][1]);
				rep(i, 2) tr[i] = tmp[i];
				r --;
			}
		}
		if(l == r) {
			rep(i, 2) tmp[i] = min(tl[0] + tre[l][0][i], tl[1] + tre[l][1][i]);
			rep(i, 2) tl[i] = tmp[i];
		}
		return min(tl[0] + tr[0], tl[1] + tr[1]);
	}
}tre;
 
int n, a[200005], cnt[200005];
 
int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) cnt[a[i]] ++;
	
	LL ans = 0; 
	rep1(i, n) if(cnt[i]) tre.modify(i, 1);
	rep1(i, n) if(a[i]) {
		ans += tre.query(0, a[i] - 1) + 1;
		cnt[a[i]] --;
		tre.modify(a[i], cnt[a[i]] ? 3 : 2);
	}
 
	printf("%lld\n", ans);
	return 0;
}