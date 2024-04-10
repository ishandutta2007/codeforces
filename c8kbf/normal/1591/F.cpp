
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxt = 6E6+8;
constant big = 1E9+1;
constant mod = 998244353;

_ n, a[maxn], t[maxt], ml[maxt], ad[maxt], l[maxt], r[maxt], rt, cnt;

void rgtms(_ L, _ R, _ l, _ r, _ c, _ pos);
void rgadd(_ L, _ R, _ l, _ r, _ c, _ pos);
void pushDown(_ pos);
void pushUp(_ pos);
_ newNode(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    rt = newNode(0);
    rgadd(1, a[1], 1, big, 1, rt);
    for(_ i = 2; i <= n; ++i) {
        _ sm = t[rt];
        rgtms(1, a[i], 1, big, -1, rt);
        rgtms(a[i]+1, big, 1, big, 0, rt);
        rgadd(1, a[i], 1, big, sm, rt);
    }
    printf("%lld\n", (t[rt]+mod)%mod);
    
    return 0;
}

_ newNode(_ x) {
    t[++cnt] = x;
    ml[cnt] = 1;
    return cnt;
}

void pushUp(_ pos) {
    t[pos] = (t[r[pos]]+t[l[pos]])%mod;
    return;
}

void pushDown(_ pos, _ ls, _ rs) {
    if(!l[pos]) l[pos] = newNode(ad[pos]*ls);
    else {
        t[l[pos]] *= ml[pos];
        t[l[pos]] += ad[pos]*ls;
        t[l[pos]] %= mod;
    }
    if(!r[pos]) r[pos] = newNode(ad[pos]*rs);
    else {
        t[r[pos]] *= ml[pos];
        t[r[pos]] += ad[pos]*rs;
        t[r[pos]] %= mod;
    }
    ad[l[pos]] *= ml[pos];
    ad[r[pos]] *= ml[pos];
    ad[l[pos]] += ad[pos];
    ad[r[pos]] += ad[pos];
    ml[l[pos]] *= ml[pos];
    ml[r[pos]] *= ml[pos];
    ad[l[pos]] %= mod;
    ad[r[pos]] %= mod;
    ml[l[pos]] %= mod;
    ml[r[pos]] %= mod;
    ml[pos] = 1;
    ad[pos] = 0;
    return;
}

void rgadd(_ L, _ R, _ l, _ r, _ c, _ pos) {
    if(L <= l && r <= R) {
        t[pos] += (r-l+1)*c%mod;
        ad[pos] += c;
        t[pos] %= mod;
        ad[pos] %= mod;
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos, md-l+1, r-md);
    if(L <= md) rgadd(L, R, l, md, c, ::l[pos]);
    if(R > md) rgadd(L, R, md+1, r, c, ::r[pos]);
    pushUp(pos);
    return;
}

void rgtms(_ L, _ R, _ l, _ r, _ c, _ pos) {
    if(L <= l && r <= R) {
        t[pos] *= c;
        ad[pos] *= c;
        ml[pos] *= c;
        return;
    }
    _ md = (l+r)>>1;
    pushDown(pos, md-l+1, r-md);
    if(L <= md) rgtms(L, R, l, md, c, ::l[pos]);
    if(R > md) rgtms(L, R, md+1, r, c, ::r[pos]);
    pushUp(pos);
    return;
}