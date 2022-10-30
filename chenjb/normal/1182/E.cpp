#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
#include <cmath>
#include <cstdlib>
#define mp make_pair
#define pb push_back
#define inf 1000000007
using namespace std;
struct matrix
{
    int n;
    long long p[7][7];
    void init(int _n)
    {
        n=_n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                p[i][j]=0;
    }
};
long long gcd(long long x,long long y)
{
    if (y==0)return x;
    return gcd(y,x%y);
}
matrix multiply(matrix a,matrix b)
{
    matrix c; c.init(a.n);
    int n=a.n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                c.p[i][j]=(c.p[i][j]+1ll*a.p[i][k]*b.p[k][j]%(inf-1))%(inf-1);
    return c;
}
typedef long long ll;
ll Pow(ll a, ll n, ll m = inf)
{
    ll t = 1;
    for (; n; n >>= 1, (a *= a) %= m)
        if (n & 1) (t *= a) %= m;
    return t;
}
ll exbsgs(ll a, ll b, ll p)
{
    if (b == 1LL) return 0;
    ll t, d = 1, k = 0;
    while ((t = gcd(a, p)) != 1)
    {
        if (b % t) return -1;
        ++k, b /= t, p /= t, d = d * (a / t) % p;
        if (b == d) return k;
    }
    unordered_map<ll, ll> dic;
    ll m = ceil(sqrt(p));
    ll a_m = Pow(a, m, p), mul = b;
    for (ll j = 1; j <= m; ++j) mul = mul * a % p, dic[mul] = j;
    for (ll i = 1; i <= m; ++i)
    {
        d = d * a_m % p;
        if (dic[d]) return i * m - dic[d] + k;
    }
    return -1;
}
int main()
{
    long long n,f1,f2,f3,c;
    cin>>n>>f1>>f2>>f3>>c;
    c=exbsgs(5,c,inf);
    f1=exbsgs(5,f1,inf);
    f2=exbsgs(5,f2,inf);
    f3=exbsgs(5,f3,inf);

    n-=3;
    matrix X; X.init(5);
    X.p[0][0]=1; X.p[0][1]=1; X.p[0][2]=1; X.p[0][3]=c*2%(inf-1); X.p[0][4]=(-c*6%(inf-1)+(inf-1))%(inf-1);
    X.p[1][0]=1;
    X.p[2][1]=1;
    X.p[3][3]=1; X.p[3][4]=1;
    X.p[4][4]=1;
           
    matrix base; base.init(5);
    for(int i=0;i<5;i++)base.p[i][i]=1;
    while (n)
    {
        if (n&1)base=multiply(base,X);
        X=multiply(X,X);
        n>>=1;
    }

    long long ret=0;
    (ret+=1ll*base.p[0][0]*f3)%=(inf-1);
    (ret+=1ll*base.p[0][1]*f2)%=(inf-1);
    (ret+=1ll*base.p[0][2]*f1)%=(inf-1);
    (ret+=1ll*base.p[0][3]*4ll)%=(inf-1);
    (ret+=1ll*base.p[0][4])%=(inf-1);


    long long ans=1;
    long long x=5;
    while (ret)
    {
        if (ret&1)ans=ans*x%inf;
        x=x*x%inf;
        ret>>=1;
    }
    cout<<ans<<endl;
}