#include<bits/stdc++.h>
using namespace std;
char _;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <typename t> void scan (t& x) {do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MN = 3e5+2, MOD = 998244353;
int fac[MN];
int main () {
    fac[0] = 1;
    for (int i = 1; i < MN; i++) fac[i] = fac[i-1] * 1LL * i % MOD;
    int n;
    scan(n);
    vector<int> a(n+1), b(n+1);
    vector<pii> tog(n+1);
    for (int i = 1; i <= n; i++) {
        scan(a[i],b[i]);
        tog[i] = {a[i],b[i]};
    }
    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());
    sort(tog.begin()+1,tog.end());
    bool bth = 1;
    for (int i = 2; i <= n; i++) if (tog[i].second < tog[i-1].second) bth = 0;
    vector<pii> afreq, bfreq;
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i-1]) afreq.push_back({i,1});
        else afreq.back().second++;
        if (b[i] != b[i-1]) bfreq.push_back({i,1});
        else bfreq.back().second++;
    }
    int aperm = 1, bperm = 1;
    for (pii p : afreq) aperm = aperm * 1LL * fac[p.second] % MOD;
    for (pii p : bfreq) bperm = bperm * 1LL * fac[p.second] % MOD;
    int both = 1;
    if (bth) {
        int bp = 0;
        for (pii p : afreq) {
            int s = p.first, e = p.first + p.second - 1;
            while (bp < bfreq.size() && bfreq[bp].first <= e) {
                pii p2 = bfreq[bp];
                int s2 = p2.first, e2 = p2.first + p2.second - 1;
                int overlap = 0;
                if (e2 <= e) both = both * 1LL * fac[min(p2.second,e2 - s + 1)] % MOD;
                else both = both * 1LL * fac[e - max(s,s2) + 1] % MOD;
                ++bp;
            }
            if (bp > 0) --bp;
        }
    }
    else both = 0;
    printf ("%d\n",(fac[n] - (((aperm+bperm)%MOD-both+MOD)%MOD) + MOD)%MOD);
    return 0;
}