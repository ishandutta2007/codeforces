#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e6+3, MOD = 1e9+7;
char s[MN];
int main() {
    int n;
    scanf ("%d",&n);
    scanf ("%s",s+1);
    int pre = 0, bad = 0, st = 1, ret = 0;
    for (int i = 1; i <= n; i++) {
        pre += s[i] == '(' ? 1 : -1;
        if (pre < 0) bad = 1;
        if (pre == 0) {
            if (bad) ret += i-st+1;
            bad = 0;
            st = i+1;
        }
    }
    if (pre != 0) printf ("-1\n");
    else printf ("%d\n",ret);
    return 0;
}