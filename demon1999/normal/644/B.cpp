#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define mp(i, j) make_pair(i, j)
#define rs(j) resize((j))
#define pb push_back
#define pp pop_back
#define len(s) (int)s.length()
#define sz(a) (int)a.size()
#define re  return
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
using namespace std;

ll n, l, r, b, cnt, t, d, ans[200001];
queue<pair<ll, pair<ll, ll> > > q;

int main(){
    iostream::sync_with_stdio(0); cin.tie(0);
    //assert(freopen(".in", "r",  stdin));
    //freopen(".out", "w", stdout);
    cin >> n >> b;
    forn (i, n) {
        cin >> t >> d;
        if (t >= r) {
            q.push(mp(t, mp(d, i)));
            cnt++;
            while(!q.empty() && r <= t) {
                l = max(r, q.front().fi);
                r = l + q.front().se.fi;
                ans[q.front().se.se] = r;
                q.pop();
                cnt--;
            }
        }
        else {
            if (cnt < b) {
                cnt++;
                q.push(mp(t, mp(d, i)));
            }
            else ans[i] = -1;
        }
    }
    while (!q.empty()) {
        l = max(q.front().fi, r);
        r = l + q.front().se.fi;
        ans[q.front().se.se] = r;
        q.pop();
    }
    forn (i, n) cout << ans[i] << " ";
    return 0;
}