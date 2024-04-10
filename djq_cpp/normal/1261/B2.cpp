#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

struct fwt
{
	int dat[200005];
	
	void add(int pos, int val)
	{
		pos ++;
		while(pos <= 200000) {
			dat[pos] += val;
			pos += pos & -pos;
		}
	}
	
	int findkth(int k)
	{
		int cur = 0;
		for(int st = 131072; st >= 1; st >>= 1)
		if(cur + st <= 200000 && k > dat[cur + st])
		k -= dat[cur += st];
		return cur;
	}
}tre;

int n, m;
int a[200005];
vector<int> vals;
vector<int> hv[200005];
int qk[200005], qpos[200005];
int ans[200005];
vector<int> qy[200005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) vals.push_back(a[i]);
	sort(vals.begin(), vals.end());
	vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
	rep(i, n) a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
	rep(i, n) hv[a[i]].push_back(i); 
	
	scanf("%d", &m);
	rep(i, m) {
		scanf("%d%d", &qk[i], &qpos[i]);
		qy[qk[i]].push_back(i);
	}
	
	int ccnt = 0;
	for(int i = vals.size() - 1; i >= 0; i --)
	rep(j, hv[i].size()) {
		ccnt ++;
		tre.add(hv[i][j], 1);
		rep(k, qy[ccnt].size()) {
			int cq = qy[ccnt][k];
			ans[cq] = vals[a[tre.findkth(qpos[cq])]];
		}
	}
	
	rep(i, m) printf("%d\n", ans[i]);
	return 0;
}