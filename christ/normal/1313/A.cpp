#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) {
        int a,b,c;
        vector<int> d(3);
        for (auto &au : d) scanf ("%d",&au);
        sort(all(d)); reverse(all(d));
        a = d[0], b = d[1], c = d[2];
        int ret = 0;
        if (a) --a, ret++;
        if (b) --b, ret++;
        if (c) --c, ret++;
        if (a&&b) --a, --b, ret++;
        if (a&&c) --a, --c, ret++;
        if (b&&c) --b, --c, ret++;
        if (a&&b&&c) ret++;
        printf ("%d\n",ret);
    }
    return 0;
}