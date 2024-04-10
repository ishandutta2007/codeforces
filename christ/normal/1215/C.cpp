#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
char aa[MN], bb[MN];
int main() {
    int n;
    scanf ("%d",&n);
    scanf ("%s\n%s",aa+1,bb+1);
    int tot = 0; vector<int> ab,ba;
    for (int i = 1; i <= n; i++) if (aa[i] != bb[i]) {
        if (aa[i] == 'a') ab.push_back(i);
        else ba.push_back(i);
        ++tot;
    }
    if (tot&1) return !printf ("-1\n");
    vector<pii> ret;
    while (ab.size() >= 2) {
        int a = ab.back(); ab.pop_back();
        ret.emplace_back(a,ab.back()); ab.pop_back();
    }
    while (ba.size() >= 2) {
        int a = ba.back(); ba.pop_back();
        ret.emplace_back(a,ba.back()); ba.pop_back();
    }
    if (!ab.empty()) {
        ret.emplace_back(ab.back(),ab.back()); ret.emplace_back(ab.back(),ba.back());
    }
    printf ("%d\n",ret.size());
    for(auto &p : ret) printf ("%d %d\n",p.first,p.second);
    return 0;
}