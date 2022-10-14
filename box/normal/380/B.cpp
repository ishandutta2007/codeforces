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
//#define int ll
const int MOD = 1000000007;

struct op { int l, r, x; };
struct qry { int q, t, l, r, x; };
int fa[500506];
int cn[500006];
bool h[1000006]; int ans[1000006];
int result[7005];

int qury(int i, int l, vector<op>& lay) {
	int cnt = 0;
	for(op& t:lay) if(t.l <= l && l <= t.r && !h[t.x]) h[t.x] = 1, ans[cnt++] = t.x;
	rep(i, cnt) h[ans[i]] = 0;
	return cnt;
}

void run(vector<qry>& q, int curlayer) {
	vector<op> lay; int id = 0;
	for(qry& o:q) {
		if(o.q == 1 && o.t == curlayer) {
			lay.pb({o.l, o.r, o.x});
			o.l = fa[o.l];
			o.r = fa[o.r];
			o.t--;
		} if(o.q == 2) {
			if(o.t == curlayer) result[id] = qury(o.t, o.l, lay);
			id++;
		}
	}
}

signed main() {
    rep(i, 19) cn[1<<i]++;
    rep1(i, 500002) {
    	cn[i] += cn[i-1];
    	fa[i+cn[i-1]] = fa[i+cn[i]] = i;
    }
    int n, m; cin >> n >> m;
    vector<qry> qrs(m); int cnt = 0;
    rep(i, m) {
    	cin >> qrs[i].q;
    	if(qrs[i].q == 1) cin >> qrs[i].t >> qrs[i].l >> qrs[i].r >> qrs[i].x;
    	else cin >> qrs[i].t >> qrs[i].l, cnt++;
    }
    for(int i=n; i>=1; i--) run(qrs, i);
    rep(i, cnt) cout << result[i] << endl;
}