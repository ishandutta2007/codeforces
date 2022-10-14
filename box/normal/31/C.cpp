// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;
#define time ttttttt
int dont, n;
pair<pii, int> time[5005];
bool tt() {
	int curend = -1;
	rep(i, n) {
		if(i == dont) continue;
		if(time[i].fi.fi < curend) return 0;
		curend = time[i].fi.se;
	}
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
     cin >> n;
    rep(i, n) { cin >> time[i].fi.fi >> time[i].fi.se; time[i].se = i+1; }
    sort(time, time+n);
    vector<int> ans;
    rep(i, n) {
    	dont = i;
    	if(tt()) ans.pb(time[i].se);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int& k:ans) cout << k << ' ';
}