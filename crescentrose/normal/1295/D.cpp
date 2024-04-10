#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll p)
{
    ll ans=(long double)a*b/p;
    return (a*b-ans*p+p)%p;
}
ll add(ll a,ll b,ll p)
{
    a+=b;
    return a%p;
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
        flag=(p==2||p%2);
        for(int i=0;i<12&&flag&&pri[i]<p;++i)
            flag&=check(pri[i],p);
    }
};
vector<ll> p;
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
void div(ll N)
{
    if(N==1) return;
    ll q;
    if(is_prime(N).flag)
    {
        p.push_back(N);
        return;
    }
    q=pollard_rho(N);
    ll tmp = N / q;
    do{
        ll x = __gcd(tmp, q);
        if (x==1) break;
        tmp /= x;
    }while (1);
    div(q);div(tmp);
}
ll dfs(ll x, int y) {
    ll out = x;
    for (int i = y ; i < p.size() && p[i] <= x; i ++)
        out -= dfs(x/p[i], i + 1);
    return out;
}
ll work(ll x) {
    if (!x) return 0;
    return dfs(x, 0);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        long long a, m;
        scanf("%lld%lld", &a, &m);
        long long x = __gcd(a, m);
        p.clear();
        div(m / x);
        sort(p.begin(), p.end());
        printf("%lld\n", work((m + a - 1) / x) - work((a - 1) / x));
    }
    return 0;
}