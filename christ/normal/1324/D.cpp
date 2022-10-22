#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e3+3, MOD = 1e9+7;
int main() { //a[i]-b[i] > b[j] - a[j]
    int n;
    scanf ("%d",&n);
    ll ret = 0;
    vector<pii> a(n);
    for (auto &au : a) scanf ("%d",&au.first);
    for (auto &au : a) {
        scanf ("%d",&au.second);
        if (au.first - au.second > au.second - au.first)  --ret;
    }
    vector<pii> b(all(a));
    sort(all(a),[](pii a, pii b) {return a.first-a.second < b.first-b.second;});
    sort(all(b),[](pii a, pii b) {return a.second-a.first < b.second-b.first;});
    int bp = 0;
    for (int i = 0; i < n; i++) {
        while (bp < n && a[i].first-a[i].second > b[bp].second-b[bp].first) ++bp;
        ret += bp;
    }
    printf ("%lld\n",ret>>1);
    return 0;
}