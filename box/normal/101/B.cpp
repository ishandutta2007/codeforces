#include <bits/stdc++.h>
#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using pii=pair<int, int>;
#define mod 1000000007
//#define int ll

long long DP[100005];
long long psum[100005];
vector<pii> bus; // (end, start)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
    rep(i, m) {
        int s, e; cin >> s >> e;
        if(e == 0 || s == e) {
            m--;
            continue;
        }
        bus.push_back(mp(e, s));
    }
    sort(all(bus));
    long long ans = 0;
    for(int b=0; b<m; b++) {
        int en = bus[b].fi, st = bus[b].se;
        DP[b] = (st == 0);
        int fir = lower_bound(all(bus), mp(st, 0)) - bus.begin();
        int la = lower_bound(all(bus), mp(en-1, 1000000001)) - bus.begin();
        //cout << b << ' ' << la << ' ' << fir << endl;
        if(la != 0) {
            if(fir != 0) DP[b] += (psum[la-1] - psum[fir-1] + mod) % mod;
            else DP[b] += psum[la-1];
        }
        if(b == 0) psum[b] = DP[b];
        else psum[b] = (psum[b-1] + DP[b]) % mod;
        if(en == n) ans = (ans + DP[b]) % mod;
    }
    cout << ans << endl;
}