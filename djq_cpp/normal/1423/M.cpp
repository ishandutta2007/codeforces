#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;
bool chkmin(int& x, int y)
{
	return x > y ? (x = y, true) : false;
}

int query(int x, int y)
{
	int ret;
	cout << "? " << x + 1 << ' ' << y + 1 << endl;
	cin >> ret;
	return ret;
}
int ans = INF;

vector<int> calc(const vector<int>& hn, const vector<int>& hm)
{
	if(hn.size() == 1) {
		int ca = INF;
		vector<int> ret(1);
		rep(i, hm.size()) if(chkmin(ca, query(hn[0], hm[i]))) ret[0] = hm[i];
		ans = min(ans, ca);
		return ret;
	}
	
	vector<int> fn, fm, fr, ret;
	vector<PII> cdat;
	rep(i, hn.size()) if(i & 1) fn.push_back(hn[i]);
	cdat.clear();
	rep(i, hm.size()) {
		while(!cdat.empty() && cdat.back().first > query(fn[(int)cdat.size() - 1], hm[i])) cdat.pop_back();
		int cs = (int)cdat.size();
		if(cs < (int)fn.size()) cdat.push_back(MP(query(fn[cs], hm[i]), hm[i]));
	}
	rep(i, cdat.size()) fm.push_back(cdat[i].second);
	fr = calc(fn, fm);
	
	ret.resize(hn.size());
	int pos = 0;
	rep(i, ret.size()) if(i & 1) ret[i] = fr[i >> 1];
	else {
		int rb = (i >> 1) >= (int)fr.size() ? hm.back() : fr[i >> 1], ca = INF;
		while(hm[pos] < rb) {
			if(chkmin(ca, query(hn[i], hm[pos]))) ret[i] = hm[pos];
			pos ++;
		}
		if(chkmin(ca, query(hn[i], hm[pos]))) ret[i] = hm[pos];
		ans = min(ans, ca);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector<int> A, B;
	rep(i, n) A.push_back(i);
	rep(i, m) B.push_back(i);
	calc(A, B);
	cout << "! " << ans << endl;
	return 0;
}