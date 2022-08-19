#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct BIT
{
	int cc[400005];
	void add(int pos)
	{
		while(pos <= 400000) {
			cc[pos] ++;
			pos += pos & -pos;
		}
	}
	int query(int pos)
	{
		int ret = 0;
		while(pos > 0) {
			ret += cc[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
}trea, treb;

int n;
vector<int> hv;
int sa[100005], ea[100005], sb[100005], eb[100005];
vector<int> ssa[400005], sea[400005], ssb[400005], seb[400005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d%d%d", &sa[i], &ea[i], &sb[i], &eb[i]);
	rep(i, n) {
		hv.push_back(sa[i]);
		hv.push_back(ea[i]);
		hv.push_back(sb[i]);
		hv.push_back(eb[i]);
	}
	sort(hv.begin(), hv.end());
	hv.resize(unique(hv.begin(), hv.end()) - hv.begin());
	rep(i, n) {
		sa[i] = lower_bound(hv.begin(), hv.end(), sa[i]) - hv.begin();
		ea[i] = lower_bound(hv.begin(), hv.end(), ea[i]) - hv.begin();
		sb[i] = lower_bound(hv.begin(), hv.end(), sb[i]) - hv.begin();
		eb[i] = lower_bound(hv.begin(), hv.end(), eb[i]) - hv.begin();
		ssa[sa[i]].push_back(i);
		sea[ea[i]].push_back(i);
		ssb[sb[i]].push_back(i);
		seb[eb[i]].push_back(i);
	}
	
	LL tot = 0, tota = 0, totb = 0;
	int suma = 0, sumb = 0;
	rep(i, hv.size()) {
		rep(j, ssa[i].size()) tot += trea.query(sb[ssa[i][j]]);
		rep(j, sea[i].size()) trea.add(eb[sea[i][j]] + 1);
		rep(j, ssa[i].size()) tot += treb.query(hv.size() - eb[ssa[i][j]] - 1);
		rep(j, sea[i].size()) treb.add(hv.size() - sb[sea[i][j]]);
		tota += 1LL * ssa[i].size() * suma;
		suma += sea[i].size();
		totb += 1LL * ssb[i].size() * sumb;
		sumb += seb[i].size();
	}
	
	if(tota > tot || totb > tot) printf("NO\n");
	else printf("YES\n");
	return 0;
}