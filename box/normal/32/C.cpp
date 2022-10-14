// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m, s; cin >> n >> m >> s;
	int mxf = 0, mxfcnt = 0, mxg = 0, mxgcnt = 0;
	rep1(a, n) {
		int tr = (n-a)/s-(1-a)/s+1;
		if(mxf < tr) {
			mxfcnt = 1;
			mxf = tr;
		} else if(mxf == tr) mxfcnt++;
	}
	rep1(b, m) {
		int tr = (m-b)/s-(1-b)/s+1;
		if(mxg < tr) {
			mxgcnt = 1;
			mxg = tr;
		} else if(mxg == tr) mxgcnt++;
	}
	ll v = mxfcnt; v *= mxgcnt;
	cout << v << endl;
}