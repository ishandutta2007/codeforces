#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
ll mul(ll a,ll b,ll p)
{
    ll ans=(long double)a*b/p;
    return (a*b-ans*p+p)%p;
}
ll qp(ll a,ll n,ll p)
{
    ll ans=1;
    while(n)
    {
        if(n&1ll) ans=mul(ans,a,p);
        a=mul(a,a,p);
        n>>=1;
    }
    return ans;
}
ll pri[12]{2,3,5,7,11,13,17,19,23,29,31,37};
struct is_prime{
    bool flag;
    bool check(ll a,ll p)
    {
        ll now=p-1;
        if(qp(a,now,p)!=1) return false;
        while(now%2==0)
        {
            now>>=1;
            ll ans=qp(a,now,p);
            if(ans==p-1) return true;
            if(ans!=1) return false;
        }
        return true;
    }
    is_prime(ll p)
    {
        if (p == 1) {
            flag = 0;
        } else {
            flag=(p==2||p%2);
            for(int i=0;i<12&&flag&&pri[i]<p;++i)
                flag&=check(pri[i],p);
        }
    }
};
ll pollard_rho(ll n)
{
    ll a,b,c,del;
    while(true) {
        c = rand() % n;
        a = b = rand() % n;
        b = (mul(b, b, n) + c) % n;
        while(a != b) {
            del = a-b;
            del = __gcd(abs(del), n);
            if(del > 1 && del < n) {
                return del;
            }
            a = (mul(a, a, n) + c) % n;
            b = (mul(b, b, n) + c) % n;
            b = (mul(b, b, n) + c) % n;
        }
    }
}
void div(ll N, vector<ll>&p)
{
    if(N==1) return;
    ll q;
    if(is_prime(N).flag)
    {
        p.push_back(N);
        return;
    }
    q=pollard_rho(N);
    div(q,p);div(N/q,p);
}
const int N = 1e6 + 10;
int a[N], c[N];
ll b[N];
int n;
long long all = 0;
vector<ll>d;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]), all += a[i];
    if (all == 1) {
        printf("-1\n");
        return 0;
    }
    div(all, d);
    sort(d.begin(), d.end());
    ll ans = 1e18;
    ll last = -1;
    for (auto u:d) {
        if (last == u) continue;
        last = u;
        ll v = 0, pre = 0;
        int l = 1;
        for (int i = 1; i <= n; i ++)
            c[i] = a[i] % u, b[i] = 0;
        for (int i = 1; i <= n; i ++) {
            pre = pre + c[i];
            if (pre >= u) {
                int tmp = c[i] - (u - (pre - c[i]));
                c[i] -= tmp;
                pre = 0;
                ll vv = 1e18;
                if (l == i)vv = 0;
                b[l] = 0;
                for (int j = l ; j < i; j ++) {
                    pre = (pre + c[j]) % u;
                    b[j + 1] = b[j] + pre;
                }
                vv = min(vv, b[i]);
                pre = 0;
                ll vvv = 0;
                for (int j = i ;j > l; j --) {
                    pre = (pre + c[j]) % u;
                    vvv += pre;
                    vv = min(vv, b[j - 1] + vvv);
                }
                vv = min(vv, vvv);
                pre = 0;
                v += vv;
                if (tmp) {
                    c[i] = tmp;
                    l = i;
                    i --;
                }else
                    l = i + 1;
            }
        }
        ans = min(ans, v);
    }
    printf("%lld\n", ans);
    return 0;
}