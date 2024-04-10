#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1<<25|1, MOD = 1e9+7;
int bit0[MN], bit1[MN];
void update (int *bit, int i, int v) {
    for (++i;i<MN;i+=i&-i)
        bit[i] += v;
}
int query (int *bit, int i) {
    int ret = 0;
    for (++i;i;i^=i&-i)
        ret += bit[i];
    return ret;
}
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    ll ret = 0;
    for (int bit = 0; bit < 25; bit++) {
        for (int i = 0; i < (1 << (bit+1)); i++) bit1[i] = bit0[i] = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]>>bit&1) update(bit1,a[i]&((1 << bit)-1),1);
            else update(bit0,a[i]&((1 << bit)-1),1);
        }
        ll p0=0,p1=0;
        for (int i = 0; i < n; i++) {
            int sub = a[i]&((1 << bit)-1);
            if (a[i]>>bit&1) {
                int add = query(bit1,(1 << bit)-sub-1) + query(bit0,(1<<bit)-1) - query(bit0,(1 << bit)-sub-1);
                p0 += add;
                p1 += n - add;
            } else {
                int add = query(bit0,(1 << bit)-sub-1) + query(bit1,(1<<bit)-1) - query(bit1,(1 << bit)-sub-1);
                p0 += add;
                p1 += n - add;
            }
        }
        for (int i = 0; i < n; i++){
            if ((ll)(a[i]+a[i])>>bit&1) p1--;
            else p0--;
        }
        p1 >>= 1; p0 >>= 1;
        if (p1&1) ret |= (1 << bit);
    }
    printf ("%lld\n",ret);
    return 0;
}