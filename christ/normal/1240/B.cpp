#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 3e5+3, MOD = 1e9+7;
void solve () {
    int n;
    scanf ("%d",&n);
    vector<int> a(n+1); vector<int> fst(n+1), lst(n+1); int cnt = 0; vector<int> has;
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        if (!fst[a[i]]) fst[a[i]] = i, ++cnt, has.push_back(a[i]);
        lst[a[i]] = i;
    }
    sort(all(has)); vector<int> bad;
    int ret = 1;
    for (int i = 1; i < has.size(); i++) {
        if (lst[has[i-1]] > fst[has[i]]) bad.push_back(i);
    }
    for (int i = 1; i < has.size(); i++) {
        auto it = upper_bound(all(bad),i);
        if (it == bad.begin()) ret = max(ret,i+1);
        else ret = max(ret,i-*(--it)+1);
    }
    printf ("%d\n",cnt-ret);
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}