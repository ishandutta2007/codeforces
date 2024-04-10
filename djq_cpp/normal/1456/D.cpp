#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n;
bool pret[2][5005];
vector<pair<LL, LL> > rgc[2];
PII seq[5005];

LL absv(LL x)
{
	return x < 0 ? -x : x;
}

void trans_tt(int id)
{
	if(id == 0 || !pret[id & 1][id - 1]) return;
	for(int i = id; i < n; i ++)
	if(absv(seq[id - 1].second - seq[i].second) + absv(seq[id].second - seq[i].second) <=
	seq[id].first - seq[id - 1].first) pret[!(id & 1)][i] = true;
	for(int i = id; i < n; i ++)
	if(pret[id & 1][i] && pret[!(id & 1)][id]) pret[!(id & 1)][i] = true;
}

void trans_tc(int id)
{
	if(id == 0 || !pret[id & 1][id]) return;
	rgc[!(id & 1)].push_back(MP(seq[id - 1].second + seq[id - 1].first - seq[id].first,
	seq[id - 1].second - seq[id - 1].first + seq[id].first));
}

LL getdis(const vector<pair<LL, LL> >& cur, int cp)
{
	LL ret = INF;
	rep(i, cur.size()) if(cur[i].first <= cp && cur[i].second >= cp) ret = 0;
	else if(cur[i].first <= cp) ret = min(ret, cp - cur[i].second);
	else ret = min(ret, cur[i].first - cp);
	return ret;
}

void trans_ct(int id)
{
	LL tim = seq[id].first - (id == 0 ? 0 : seq[id - 1].first);
	for(int i = id; i < n; i ++)
	if(getdis(rgc[id & 1], seq[i].second) + absv(seq[id].second - seq[i].second) <= tim) pret[!(id & 1)][i] = true;
}

void trans_cc(int id)
{
	LL tim = seq[id].first - (id == 0 ? 0 : seq[id - 1].first), dis = tim - getdis(rgc[id & 1], seq[id].second);
	if(dis >= 0) rgc[!(id & 1)].push_back(MP(seq[id].second - dis, seq[id].second + dis));
}

void upd_c(int cur)
{
	sort(rgc[cur].begin(), rgc[cur].end());
	if(rgc[cur].size() == 2 && rgc[cur][0].second >= rgc[cur][1].first) {
		rgc[cur][0].second = max(rgc[cur][0].second, rgc[cur][1].second);
		rgc[cur].resize(1);
	}
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d%d", &seq[i].first, &seq[i].second);
	
	rgc[0].push_back(MP(0, 0));
	rep(i, n) {
		rep(j, n) pret[!(i & 1)][j] = false;
		rgc[!(i & 1)].clear();
		
		trans_tt(i);
		trans_tc(i);
		trans_ct(i);
		trans_cc(i);
		if(pret[!(i & 1)][i]) rgc[!(i & 1)].push_back(MP(seq[i].second, seq[i].second));
		upd_c(!(i & 1));
	}
	
	if(!rgc[n & 1].empty()) printf("YES\n");
	else printf("NO\n");
	return 0;
}