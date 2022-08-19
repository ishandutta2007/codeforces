#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

PII merge(const PII& A, const PII& B)
{
	return A.first == B.first ? MP(A.first, A.second + B.second) : 
	(A.second > B.second ? MP(A.first, A.second - B.second) : MP(B.first, B.second - A.second));
}

int n, q, a[300005];
vector<int> occ[300005];
struct segt
{
	PII dat[1048576];
	void init()
	{
		rep1(i, n) dat[524288 + i] = MP(a[i], 1);
		for(int i = 524287; i >= 1; i --) dat[i] = merge(dat[i << 1], dat[i << 1 | 1]);
	}
	int query(int l, int r)
	{
		PII ret = MP(0, 0);
		l += 524288; r += 524288;
		while(l < r) {
			if(l & 1) ret = merge(ret, dat[l]);
			if(!(r & 1)) ret = merge(ret, dat[r]);
			l = (l + 1) >> 1; r = (r - 1) >> 1;
		}
		if(l == r) ret = merge(ret, dat[l]);
		return ret.first;
	}
}tre;

int main()
{
	scanf("%d%d", &n, &q);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) occ[a[i]].push_back(i); 
	tre.init();
	
	rep(i, q) {
		int l, r, x;
		scanf("%d%d", &l, &r);
		x = tre.query(l, r);
		int cnt = upper_bound(occ[x].begin(), occ[x].end(), r) - lower_bound(occ[x].begin(), occ[x].end(), l), len = r - l + 1;
		printf("%d\n", max(cnt * 2 - len, 1));
	}
	return 0;
}