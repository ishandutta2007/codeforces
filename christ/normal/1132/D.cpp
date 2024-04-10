#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
struct Info {
    int which; ll die;
    bool operator< (const Info &o) const {
        return die > o.die;
    }
};
ll ch[MN];
int main() {
    int n,k;
    scanf ("%d %d",&n,&k);
    vector<ll> charge(n); vector<int> go(n);
    for (auto &au : charge) scanf ("%lld",&au);
    for (auto &au : go) scanf ("%d",&au);
    auto check = [&] (ll mid) {
        priority_queue<Info> dead;
        for (int i = 0; i < n; i++) dead.push({i,(charge[i]+go[i])/go[i]}), ch[i] = charge[i];
        for (int i = 0; i < k; i++) {
            Info cur = dead.top(); dead.pop();int w = cur.which;
            if (cur.die <= i) return 0;
            ch[w] += mid;
            dead.push({cur.which,(ch[w]+go[w])/go[w]});
        }
        return 1;
    };
    ll low = 0, high = 1e14, mid, ans = -1;
    while (low <= high) {
        mid = (low+high)/2;
        if (check(mid)) high = (ans = mid) - 1;
        else low = mid+1;
    }
    printf ("%lld\n",ans);
    return 0;
}