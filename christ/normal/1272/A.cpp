#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 1e5+2, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
void solve () {
    vector<int> a(3);
    scanf ("%d %d %d",&a[0],&a[1],&a[2]); ll ret = LLONG_MAX;
    for (int m = 0; m < (3 * 3 * 3); m++) {
        int mask = m;
        int take1 = mask%3; mask/=3; int take2 = mask%3; mask/=3; int take3 = mask%3;
        vector<int> na = a;
        if (take1 == 0) --na[0];
        else if (take1 == 2) ++na[0];
        if (take2 == 0) --na[1];
        else if (take2 == 2) ++na[1];
        if (take3 == 0) --na[2];
        else if (take3 == 2) ++na[2];
        ll att = 0;
        for (int i = 0; i < 3; i++)
            for (int j = i+1; j < 3; j++)
                att += abs(na[i]-na[j]);
        ret = min(ret,att);
    }
    printf ("%lld\n",ret);
}
int main() {
    int t;
    scanf ("%d",&t);
    while (t--) solve();
    return 0;
}