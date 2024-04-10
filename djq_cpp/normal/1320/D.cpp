#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> hash_t;
const int MODF = 998244353;
const int MODS = 1000000007;
const int RF = 3, IRF = (MODF + 1) / RF;
const int RS = 2, IRS = (MODS + 1) / RS;

int n, q;
char t[200005];
vector<int> pos_o1;
int cnt0[200005];
int l1[200005], r1[200005];
PII hsum[200005];
int pwf[200005], pws[200005];
int ipwf[200005], ipws[200005];

void gen_pw(int arr[], int a, int m)
{
	arr[0] = 1;
	rep1(i, 200000) arr[i] = 1LL * arr[i - 1] * a % m;
}

void init_hash()
{
	gen_pw(pwf, RF, MODF);
	gen_pw(ipwf, IRF, MODF);
	gen_pw(pws, RS, MODS);
	gen_pw(ipws, IRS, MODS);
}

int count0(int l, int r)
{
	return cnt0[r + 1] - cnt0[l];
}

hash_t merge_t(const hash_t& u, const hash_t& v)
{
	return MP(u.first + v.first, MP((u.second.first + 1LL * v.second.first * pwf[u.first]) % MODF,
									(u.second.second + 1LL * v.second.second * pws[u.first]) % MODS));
}
hash_t ch_t(int dat)
{
	return MP(1, MP(dat + 1, dat + 1));
}

hash_t per_t(int l, int r)
{
	return MP(r - l, MP(1LL * (hsum[r].first - hsum[l].first + MODF) * ipwf[l] % MODF,
						1LL * (hsum[r].second - hsum[l].second + MODS) * ipws[l] % MODS));
}

hash_t get_str(int l, int r)
{
	if(count0(l, r) == 0) return r - l + 1 & 1 ? merge_t(ch_t(0), ch_t(0)) : ch_t(0);
	int pl = upper_bound(pos_o1.begin(), pos_o1.end(), l) - pos_o1.begin();
	int pr = upper_bound(pos_o1.begin(), pos_o1.end(), r) - pos_o1.begin() - 1;
	if(pr >= pl && count0(pos_o1[pr], r) == 0) pr --;
	hash_t cur;
	if(pl > pr) cur = ch_t(count0(l, r));
	else cur = merge_t(merge_t(ch_t(count0(l, pos_o1[pl])), per_t(pl, pr)), ch_t(count0(pos_o1[pr], r)));
	if(t[l] == '1' && (r1[l] - l + 1 & 1)) cur = merge_t(ch_t(0), cur);
	if(t[r] == '1' && (r - l1[r] + 1 & 1)) cur = merge_t(cur, ch_t(0));
	return cur;
}

int main()
{
	init_hash();
	scanf("%d%s%d", &n, t, &q);
	int cnt = 0;
	rep(i, n) if(t[i] == '1') {
		l1[i] = i - cnt;
		cnt ++;
	} else {
		if(cnt & 1) pos_o1.push_back(i - cnt);
		cnt = 0;
	}
	if(cnt & 1) pos_o1.push_back(n - cnt);
	cnt = 0;
	for(int i = n - 1; i >= 0; i --) if(t[i] == '1') {
		r1[i] = i + cnt;
		cnt ++;
	} else cnt = 0;
	rep(i, n) cnt0[i + 1] = cnt0[i] + (t[i] == '0');
	rep(i, pos_o1.size()) if(i > 0)
	hsum[i] = MP((hsum[i - 1].first + 1LL * count0(pos_o1[i - 1], pos_o1[i]) * pwf[i - 1]) % MODF,
				 (hsum[i - 1].second + 1LL * count0(pos_o1[i - 1], pos_o1[i]) * pws[i - 1]) % MODS);
	rep(i, q) {
		int p, q, l;
		scanf("%d%d%d", &p, &q, &l);
		p --; q --;
		if(get_str(p, p + l - 1) == get_str(q, q + l - 1)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}